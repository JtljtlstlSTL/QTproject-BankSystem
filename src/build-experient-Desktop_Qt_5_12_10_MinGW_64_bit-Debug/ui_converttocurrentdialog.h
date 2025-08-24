/********************************************************************************
** Form generated from reading UI file 'converttocurrentdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONVERTTOCURRENTDIALOG_H
#define UI_CONVERTTOCURRENTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ConvertToCurrentDialog
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QListWidget *depositListWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *convertButton;
    QPushButton *pushButton;

    void setupUi(QDialog *ConvertToCurrentDialog)
    {
        if (ConvertToCurrentDialog->objectName().isEmpty())
            ConvertToCurrentDialog->setObjectName(QString::fromUtf8("ConvertToCurrentDialog"));
        ConvertToCurrentDialog->resize(400, 300);
        verticalLayout_2 = new QVBoxLayout(ConvertToCurrentDialog);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(ConvertToCurrentDialog);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        depositListWidget = new QListWidget(ConvertToCurrentDialog);
        depositListWidget->setObjectName(QString::fromUtf8("depositListWidget"));

        verticalLayout->addWidget(depositListWidget);


        verticalLayout_2->addLayout(verticalLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        convertButton = new QPushButton(ConvertToCurrentDialog);
        convertButton->setObjectName(QString::fromUtf8("convertButton"));

        horizontalLayout->addWidget(convertButton);

        pushButton = new QPushButton(ConvertToCurrentDialog);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout->addWidget(pushButton);


        verticalLayout_2->addLayout(horizontalLayout);


        retranslateUi(ConvertToCurrentDialog);

        QMetaObject::connectSlotsByName(ConvertToCurrentDialog);
    } // setupUi

    void retranslateUi(QDialog *ConvertToCurrentDialog)
    {
        ConvertToCurrentDialog->setWindowTitle(QApplication::translate("ConvertToCurrentDialog", "Dialog", nullptr));
        label->setText(QApplication::translate("ConvertToCurrentDialog", "\350\257\267\351\200\211\346\213\251\351\234\200\350\246\201\350\275\254\344\270\272\346\264\273\346\234\237\347\232\204\345\256\232\346\234\237\345\255\230\346\254\276", nullptr));
        convertButton->setText(QApplication::translate("ConvertToCurrentDialog", "Confirm", nullptr));
        pushButton->setText(QApplication::translate("ConvertToCurrentDialog", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ConvertToCurrentDialog: public Ui_ConvertToCurrentDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONVERTTOCURRENTDIALOG_H
