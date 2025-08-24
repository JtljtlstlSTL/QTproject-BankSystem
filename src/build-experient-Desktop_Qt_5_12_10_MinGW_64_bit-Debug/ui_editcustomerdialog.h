/********************************************************************************
** Form generated from reading UI file 'editcustomerdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITCUSTOMERDIALOG_H
#define UI_EDITCUSTOMERDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_EditCustomerDialog
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label_4;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *oldPasswordEdit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *newPasswordEdit;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *confirmPasswordEdit;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *changePasswordButton;
    QPushButton *cancelButton;

    void setupUi(QDialog *EditCustomerDialog)
    {
        if (EditCustomerDialog->objectName().isEmpty())
            EditCustomerDialog->setObjectName(QString::fromUtf8("EditCustomerDialog"));
        EditCustomerDialog->resize(400, 300);
        verticalLayout = new QVBoxLayout(EditCustomerDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_4 = new QLabel(EditCustomerDialog);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout->addWidget(label_4);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(EditCustomerDialog);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        oldPasswordEdit = new QLineEdit(EditCustomerDialog);
        oldPasswordEdit->setObjectName(QString::fromUtf8("oldPasswordEdit"));

        horizontalLayout->addWidget(oldPasswordEdit);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(EditCustomerDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        newPasswordEdit = new QLineEdit(EditCustomerDialog);
        newPasswordEdit->setObjectName(QString::fromUtf8("newPasswordEdit"));

        horizontalLayout_2->addWidget(newPasswordEdit);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(EditCustomerDialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_3->addWidget(label_3);

        confirmPasswordEdit = new QLineEdit(EditCustomerDialog);
        confirmPasswordEdit->setObjectName(QString::fromUtf8("confirmPasswordEdit"));

        horizontalLayout_3->addWidget(confirmPasswordEdit);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        changePasswordButton = new QPushButton(EditCustomerDialog);
        changePasswordButton->setObjectName(QString::fromUtf8("changePasswordButton"));

        horizontalLayout_4->addWidget(changePasswordButton);

        cancelButton = new QPushButton(EditCustomerDialog);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));

        horizontalLayout_4->addWidget(cancelButton);


        verticalLayout->addLayout(horizontalLayout_4);


        retranslateUi(EditCustomerDialog);

        QMetaObject::connectSlotsByName(EditCustomerDialog);
    } // setupUi

    void retranslateUi(QDialog *EditCustomerDialog)
    {
        EditCustomerDialog->setWindowTitle(QApplication::translate("EditCustomerDialog", "Dialog", nullptr));
        label_4->setText(QApplication::translate("EditCustomerDialog", "If you want to change your password", nullptr));
        label->setText(QApplication::translate("EditCustomerDialog", "\350\257\267\350\276\223\345\205\245\345\216\237\345\257\206\347\240\201", nullptr));
        label_2->setText(QApplication::translate("EditCustomerDialog", "\350\257\267\350\276\223\345\205\245\346\226\260\345\257\206\347\240\201", nullptr));
        label_3->setText(QApplication::translate("EditCustomerDialog", "\350\257\267\347\241\256\350\256\244\346\226\260\345\257\206\347\240\201", nullptr));
        changePasswordButton->setText(QApplication::translate("EditCustomerDialog", "Save", nullptr));
        cancelButton->setText(QApplication::translate("EditCustomerDialog", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EditCustomerDialog: public Ui_EditCustomerDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITCUSTOMERDIALOG_H
