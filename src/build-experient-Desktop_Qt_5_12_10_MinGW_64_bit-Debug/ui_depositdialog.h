/********************************************************************************
** Form generated from reading UI file 'depositdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEPOSITDIALOG_H
#define UI_DEPOSITDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DepositDialog
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *lineEditAccount;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEditAmount;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QComboBox *comboBoxTerm;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *DepositDialog)
    {
        if (DepositDialog->objectName().isEmpty())
            DepositDialog->setObjectName(QString::fromUtf8("DepositDialog"));
        DepositDialog->resize(400, 300);
        verticalLayout = new QVBoxLayout(DepositDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(DepositDialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_3->addWidget(label_3);

        lineEditAccount = new QLineEdit(DepositDialog);
        lineEditAccount->setObjectName(QString::fromUtf8("lineEditAccount"));

        horizontalLayout_3->addWidget(lineEditAccount);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(DepositDialog);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        lineEditAmount = new QLineEdit(DepositDialog);
        lineEditAmount->setObjectName(QString::fromUtf8("lineEditAmount"));

        horizontalLayout->addWidget(lineEditAmount);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(DepositDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        comboBoxTerm = new QComboBox(DepositDialog);
        comboBoxTerm->setObjectName(QString::fromUtf8("comboBoxTerm"));

        horizontalLayout_2->addWidget(comboBoxTerm);


        verticalLayout->addLayout(horizontalLayout_2);

        buttonBox = new QDialogButtonBox(DepositDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(DepositDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), DepositDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DepositDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(DepositDialog);
    } // setupUi

    void retranslateUi(QDialog *DepositDialog)
    {
        DepositDialog->setWindowTitle(QApplication::translate("DepositDialog", "Dialog", nullptr));
        label_3->setText(QApplication::translate("DepositDialog", "\345\255\230\346\254\276\350\264\246\346\210\267\357\274\232", nullptr));
        label->setText(QApplication::translate("DepositDialog", "\350\257\267\350\276\223\345\205\245\345\255\230\346\254\276\351\207\221\351\242\235\357\274\232", nullptr));
        label_2->setText(QApplication::translate("DepositDialog", "\350\257\267\351\200\211\346\213\251\345\255\230\346\254\276\346\234\237\351\231\220\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DepositDialog: public Ui_DepositDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEPOSITDIALOG_H
