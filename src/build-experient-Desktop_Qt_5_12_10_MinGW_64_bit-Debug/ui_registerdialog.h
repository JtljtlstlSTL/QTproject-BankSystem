/********************************************************************************
** Form generated from reading UI file 'registerdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTERDIALOG_H
#define UI_REGISTERDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_RegisterDialog
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *accountNumberLabel;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *setPasswordEdit;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *setNameEdit;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QLineEdit *setAddressEdit;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *RegisterDialog)
    {
        if (RegisterDialog->objectName().isEmpty())
            RegisterDialog->setObjectName(QString::fromUtf8("RegisterDialog"));
        RegisterDialog->resize(400, 300);
        verticalLayout = new QVBoxLayout(RegisterDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        accountNumberLabel = new QLabel(RegisterDialog);
        accountNumberLabel->setObjectName(QString::fromUtf8("accountNumberLabel"));

        horizontalLayout->addWidget(accountNumberLabel);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(RegisterDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        setPasswordEdit = new QLineEdit(RegisterDialog);
        setPasswordEdit->setObjectName(QString::fromUtf8("setPasswordEdit"));

        horizontalLayout_2->addWidget(setPasswordEdit);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(RegisterDialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_3->addWidget(label_3);

        setNameEdit = new QLineEdit(RegisterDialog);
        setNameEdit->setObjectName(QString::fromUtf8("setNameEdit"));

        horizontalLayout_3->addWidget(setNameEdit);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_4 = new QLabel(RegisterDialog);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_4->addWidget(label_4);

        setAddressEdit = new QLineEdit(RegisterDialog);
        setAddressEdit->setObjectName(QString::fromUtf8("setAddressEdit"));

        horizontalLayout_4->addWidget(setAddressEdit);


        verticalLayout->addLayout(horizontalLayout_4);

        buttonBox = new QDialogButtonBox(RegisterDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(RegisterDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), RegisterDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), RegisterDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(RegisterDialog);
    } // setupUi

    void retranslateUi(QDialog *RegisterDialog)
    {
        RegisterDialog->setWindowTitle(QApplication::translate("RegisterDialog", "Dialog", nullptr));
        accountNumberLabel->setText(QString());
        label_2->setText(QApplication::translate("RegisterDialog", "\350\256\276\347\275\256\345\257\206\347\240\201\357\274\232", nullptr));
        label_3->setText(QApplication::translate("RegisterDialog", "\345\247\223\345\220\215\357\274\232", nullptr));
        label_4->setText(QApplication::translate("RegisterDialog", "\345\234\260\345\235\200\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RegisterDialog: public Ui_RegisterDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTERDIALOG_H
