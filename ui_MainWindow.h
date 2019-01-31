/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *captureValue;
    QLineEdit *captureReference;
    QLabel *label2;
    QLineEdit *lineEdit2;
    QLabel *label1;
    QLabel *label_2;
    QLineEdit *mainThreadID;
    QPushButton *pushButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(388, 198);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        formLayout = new QFormLayout();
        formLayout->setSpacing(6);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label);

        captureValue = new QLineEdit(centralWidget);
        captureValue->setObjectName(QStringLiteral("captureValue"));

        formLayout->setWidget(1, QFormLayout::FieldRole, captureValue);

        captureReference = new QLineEdit(centralWidget);
        captureReference->setObjectName(QStringLiteral("captureReference"));

        formLayout->setWidget(2, QFormLayout::FieldRole, captureReference);

        label2 = new QLabel(centralWidget);
        label2->setObjectName(QStringLiteral("label2"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label2);

        lineEdit2 = new QLineEdit(centralWidget);
        lineEdit2->setObjectName(QStringLiteral("lineEdit2"));

        formLayout->setWidget(3, QFormLayout::FieldRole, lineEdit2);

        label1 = new QLabel(centralWidget);
        label1->setObjectName(QStringLiteral("label1"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label1);

        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_2);

        mainThreadID = new QLineEdit(centralWidget);
        mainThreadID->setObjectName(QStringLiteral("mainThreadID"));

        formLayout->setWidget(0, QFormLayout::FieldRole, mainThreadID);


        horizontalLayout->addLayout(formLayout);

        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout->addWidget(pushButton);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 388, 26));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QApplication::translate("MainWindow", "Async Lambda [=]", nullptr));
        label2->setText(QApplication::translate("MainWindow", "Normal Sig/Slot", nullptr));
        label1->setText(QApplication::translate("MainWindow", "Async Lambda [&]", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "Main ThreadID:", nullptr));
        pushButton->setText(QApplication::translate("MainWindow", "Start", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
