/********************************************************************************
** Form generated from reading UI file 'bankselectiondialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BANKSELECTIONDIALOG_H
#define UI_BANKSELECTIONDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BankSelectionDialog
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *OnlineButton;
    QPushButton *OfflineButton;

    void setupUi(QWidget *BankSelectionDialog)
    {
        if (BankSelectionDialog->objectName().isEmpty())
            BankSelectionDialog->setObjectName(QString::fromUtf8("BankSelectionDialog"));
        BankSelectionDialog->resize(400, 300);
        verticalLayout_2 = new QVBoxLayout(BankSelectionDialog);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(BankSelectionDialog);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        label_2 = new QLabel(BankSelectionDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout->addWidget(label_2);


        verticalLayout_2->addLayout(verticalLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        OnlineButton = new QPushButton(BankSelectionDialog);
        OnlineButton->setObjectName(QString::fromUtf8("OnlineButton"));

        horizontalLayout->addWidget(OnlineButton);

        OfflineButton = new QPushButton(BankSelectionDialog);
        OfflineButton->setObjectName(QString::fromUtf8("OfflineButton"));

        horizontalLayout->addWidget(OfflineButton);


        verticalLayout_2->addLayout(horizontalLayout);


        retranslateUi(BankSelectionDialog);

        QMetaObject::connectSlotsByName(BankSelectionDialog);
    } // setupUi

    void retranslateUi(QWidget *BankSelectionDialog)
    {
        BankSelectionDialog->setWindowTitle(QApplication::translate("BankSelectionDialog", "Form", nullptr));
        label->setText(QApplication::translate("BankSelectionDialog", "TextLabel", nullptr));
        label_2->setText(QApplication::translate("BankSelectionDialog", "\346\254\242\350\277\216\346\235\245\345\210\260\344\270\255\345\233\275\351\223\266\350\241\214\357\274\201Welcome to Bank of China!", nullptr));
        OnlineButton->setText(QApplication::translate("BankSelectionDialog", "\347\272\277\344\270\212\351\223\266\350\241\214", nullptr));
        OfflineButton->setText(QApplication::translate("BankSelectionDialog", "\347\272\277\344\270\213\351\223\266\350\241\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BankSelectionDialog: public Ui_BankSelectionDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BANKSELECTIONDIALOG_H
