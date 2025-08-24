/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_5;
    QLabel *logo;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer_10;
    QPushButton *depositButton;
    QSpacerItem *verticalSpacer_11;
    QPushButton *registerButton;
    QSpacerItem *verticalSpacer_4;
    QPushButton *transferButton;
    QSpacerItem *verticalSpacer_3;
    QVBoxLayout *verticalLayout_2;
    QPushButton *convertToFixedButton;
    QSpacerItem *verticalSpacer_2;
    QPushButton *convertToCurrentButton;
    QSpacerItem *verticalSpacer;
    QPushButton *exitButton;
    QLabel *logo_2;
    QVBoxLayout *verticalLayout_4;
    QSpacerItem *verticalSpacer_8;
    QPushButton *withdrawButton;
    QSpacerItem *verticalSpacer_5;
    QPushButton *inquireButton;
    QPushButton *queryButton;
    QSpacerItem *verticalSpacer_6;
    QPushButton *reportLostButton;
    QSpacerItem *verticalSpacer_7;
    QPushButton *closeAccountButton;
    QPushButton *settingsButton;
    QSpacerItem *verticalSpacer_9;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(629, 345);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout_5 = new QVBoxLayout(centralwidget);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        logo = new QLabel(centralwidget);
        logo->setObjectName(QString::fromUtf8("logo"));

        verticalLayout_5->addWidget(logo);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalSpacer_10 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_10);

        depositButton = new QPushButton(centralwidget);
        depositButton->setObjectName(QString::fromUtf8("depositButton"));

        verticalLayout->addWidget(depositButton);

        verticalSpacer_11 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_11);

        registerButton = new QPushButton(centralwidget);
        registerButton->setObjectName(QString::fromUtf8("registerButton"));

        verticalLayout->addWidget(registerButton);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_4);

        transferButton = new QPushButton(centralwidget);
        transferButton->setObjectName(QString::fromUtf8("transferButton"));

        verticalLayout->addWidget(transferButton);


        verticalLayout_3->addLayout(verticalLayout);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_3);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        convertToFixedButton = new QPushButton(centralwidget);
        convertToFixedButton->setObjectName(QString::fromUtf8("convertToFixedButton"));

        verticalLayout_2->addWidget(convertToFixedButton);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);

        convertToCurrentButton = new QPushButton(centralwidget);
        convertToCurrentButton->setObjectName(QString::fromUtf8("convertToCurrentButton"));

        verticalLayout_2->addWidget(convertToCurrentButton);


        verticalLayout_3->addLayout(verticalLayout_2);

        verticalSpacer = new QSpacerItem(20, 80, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);

        exitButton = new QPushButton(centralwidget);
        exitButton->setObjectName(QString::fromUtf8("exitButton"));

        verticalLayout_3->addWidget(exitButton);


        horizontalLayout->addLayout(verticalLayout_3);

        logo_2 = new QLabel(centralwidget);
        logo_2->setObjectName(QString::fromUtf8("logo_2"));

        horizontalLayout->addWidget(logo_2);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalSpacer_8 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_8);

        withdrawButton = new QPushButton(centralwidget);
        withdrawButton->setObjectName(QString::fromUtf8("withdrawButton"));

        verticalLayout_4->addWidget(withdrawButton);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_5);

        inquireButton = new QPushButton(centralwidget);
        inquireButton->setObjectName(QString::fromUtf8("inquireButton"));

        verticalLayout_4->addWidget(inquireButton);

        queryButton = new QPushButton(centralwidget);
        queryButton->setObjectName(QString::fromUtf8("queryButton"));

        verticalLayout_4->addWidget(queryButton);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_6);

        reportLostButton = new QPushButton(centralwidget);
        reportLostButton->setObjectName(QString::fromUtf8("reportLostButton"));

        verticalLayout_4->addWidget(reportLostButton);

        verticalSpacer_7 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_7);

        closeAccountButton = new QPushButton(centralwidget);
        closeAccountButton->setObjectName(QString::fromUtf8("closeAccountButton"));

        verticalLayout_4->addWidget(closeAccountButton);

        settingsButton = new QPushButton(centralwidget);
        settingsButton->setObjectName(QString::fromUtf8("settingsButton"));

        verticalLayout_4->addWidget(settingsButton);

        verticalSpacer_9 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_9);


        horizontalLayout->addLayout(verticalLayout_4);


        verticalLayout_5->addLayout(horizontalLayout);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 629, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        logo->setText(QApplication::translate("MainWindow", "TextLabel", nullptr));
        depositButton->setText(QApplication::translate("MainWindow", "Deposit", nullptr));
        registerButton->setText(QApplication::translate("MainWindow", "Rigester", nullptr));
        transferButton->setText(QApplication::translate("MainWindow", "Transfer", nullptr));
        convertToFixedButton->setText(QApplication::translate("MainWindow", "convertToFixed", nullptr));
        convertToCurrentButton->setText(QApplication::translate("MainWindow", "convertToCurrent", nullptr));
        exitButton->setText(QApplication::translate("MainWindow", "Exit", nullptr));
        logo_2->setText(QApplication::translate("MainWindow", "TextLabel", nullptr));
        withdrawButton->setText(QApplication::translate("MainWindow", "Withdraw", nullptr));
        inquireButton->setText(QApplication::translate("MainWindow", "Inquire", nullptr));
        queryButton->setText(QApplication::translate("MainWindow", "Query", nullptr));
        reportLostButton->setText(QApplication::translate("MainWindow", "ReportLost", nullptr));
        closeAccountButton->setText(QApplication::translate("MainWindow", "Remove", nullptr));
        settingsButton->setText(QApplication::translate("MainWindow", "Setting", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
