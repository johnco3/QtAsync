#include "MainWindow.h"
#include "ui_MainWindow.h"

#include <thread>
#include <sstream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // using the new Qt5 Connect syntax
    connect(this, &MainWindow::asyncValueFinished,
        this, &MainWindow::updateCaptureValueText);
    connect(this, &MainWindow::asyncReferenceFinished,
        this, &MainWindow::updateCaptureReferenceText);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    std::stringstream ss;
    ss << std::this_thread::get_id();
    const auto threadIDStr = ss.str();
    // directly update the widget (safe as we are in main)
    ui->mainThreadID->setText(threadIDStr.c_str());

    // Run this future in a separate thread.  Note: very not to use
    // temporary as thread will block indefinitely waiting
    // for the destructor to complete in this scope block.
    // this async uses capture by value - including 'the 'this'
    // or is it '*this'
    mFuture = std::async(std::launch::async, [=] {
        std::stringstream ss;
        ss << std::this_thread::get_id();
        const auto asyncThreadID = QString("tid:") + ss.str().c_str();
        // THIS CODE DOES NOT CRASH - I THOUGHT I COULD NOT UPDATE
        // UI FROM WORKER THREAD DIRECTLY. Is this because I safely copied
        // this or *this in the capture lambda, without [=] above
        // the compiler spits out the usage of 'MainWindow::ui' requires the
        // compiler to capture 'this' but the current default capture mode does not allow it
        //ui->mainThreadID->setText(asyncThreadID);

        // Signal the Main GUI thread we are finished with the completion
        // text which will be painted once its received in the signal
        emit asyncValueFinished(asyncThreadID);
    });

    mFuture1 = std::async(std::launch::async, [&, threadIDStr] {
        std::stringstream ss;
        ss << std::this_thread::get_id();
        const auto str = QString("tid:") + ss.str().c_str();
        ui->mainThreadID->setText(threadIDStr.c_str());
        // Signal the Main GUI thread we are finished
        emit asyncReferenceFinished(str);
    });
}

void MainWindow::updateCaptureValueText(const QString& rLineEditText)
{
    ui->captureValue->setText(rLineEditText);
}

void MainWindow::updateCaptureReferenceText(const QString& rLineEditText)
{
    ui->captureReference->setText(rLineEditText);
}
