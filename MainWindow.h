#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <future>
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
signals:
    //! lambda thread emits this to notify completion.
    void asyncValueFinished(const QString&);
    void asyncReferenceFinished(const QString&);

private slots:
    void on_pushButton_clicked();
    void updateCaptureValueText(const QString&);
    void updateCaptureReferenceText(const QString&);
private:
    Ui::MainWindow *ui;

    //! Future associated with the std::async worker thead
    //! for performing long running background tasks. Set as
    //! member instead of temporary, as std::future<void>
    //! going out of temp scope would block waiting for
    //! the underlying thread to complete (which is not what we want).
    std::future<void> mFuture;
    std::future<void> mFuture1;
};

#endif // MAINWINDOW_H
