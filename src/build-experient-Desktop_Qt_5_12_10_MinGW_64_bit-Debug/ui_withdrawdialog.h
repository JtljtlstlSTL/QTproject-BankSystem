/********************************************************************************
** Form generated from reading UI file 'withdrawdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WITHDRAWDIALOG_H
#define UI_WITHDRAWDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_WithdrawDialog
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *accountNumberEdit;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *amountEdit;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *WithdrawDialog)
    {
        if (WithdrawDialog->objectName().isEmpty())
            WithdrawDialog->setObjectName(QString::fromUtf8("WithdrawDialog"));
        WithdrawDialog->resize(400, 300);
        verticalLayout = new QVBoxLayout(WithdrawDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(WithdrawDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        accountNumberEdit = new QLineEdit(WithdrawDialog);
        accountNumberEdit->setObjectName(QString::fromUtf8("accountNumberEdit"));

        horizontalLayout_2->addWidget(accountNumberEdit);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(WithdrawDialog);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        amountEdit = new QLineEdit(WithdrawDialog);
        amountEdit->setObjectName(QString::fromUtf8("amountEdit"));

        horizontalLayout->addWidget(amountEdit);


        verticalLayout->addLayout(horizontalLayout);

        buttonBox = new QDialogButtonBox(WithdrawDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(WithdrawDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), WithdrawDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), WithdrawDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(WithdrawDialog);
    } // setupUi

    void retranslateUi(QDialog *WithdrawDialog)
    {
        WithdrawDialog->setWindowTitle(QApplication::translate("WithdrawDialog", "Dialog", nullptr));
        label_2->setText(QApplication::translate("WithdrawDialog", "\345\217\226\346\254\276\350\264\246\345\217\267\357\274\232", nullptr));
        label->setText(QApplication::translate("WithdrawDialog", "\350\257\267\350\276\223\345\205\245\345\217\226\346\254\276\351\207\221\351\242\235\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WithdrawDialog: public Ui_WithdrawDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WITHDRAWDIALOG_H
