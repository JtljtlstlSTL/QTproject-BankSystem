/********************************************************************************
** Form generated from reading UI file 'edituserdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITUSERDIALOG_H
#define UI_EDITUSERDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_EditUserDialog
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLabel *accountLabel;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLabel *nameLabel;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *addressLineEdit;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QLineEdit *passwordLineEdit;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QLabel *depositTypeLabel;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_6;
    QLabel *interestRateLabel;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_7;
    QCheckBox *isLostCheckBox;
    QHBoxLayout *horizontalLayout_8;
    QSpacerItem *horizontalSpacer;
    QPushButton *saveButton;
    QPushButton *cancelButton;

    void setupUi(QDialog *EditUserDialog)
    {
        if (EditUserDialog->objectName().isEmpty())
            EditUserDialog->setObjectName(QString::fromUtf8("EditUserDialog"));
        EditUserDialog->resize(400, 300);
        verticalLayout_2 = new QVBoxLayout(EditUserDialog);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(EditUserDialog);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        accountLabel = new QLabel(EditUserDialog);
        accountLabel->setObjectName(QString::fromUtf8("accountLabel"));

        horizontalLayout->addWidget(accountLabel);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(EditUserDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        nameLabel = new QLabel(EditUserDialog);
        nameLabel->setObjectName(QString::fromUtf8("nameLabel"));

        horizontalLayout_2->addWidget(nameLabel);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(EditUserDialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_3->addWidget(label_3);

        addressLineEdit = new QLineEdit(EditUserDialog);
        addressLineEdit->setObjectName(QString::fromUtf8("addressLineEdit"));

        horizontalLayout_3->addWidget(addressLineEdit);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_4 = new QLabel(EditUserDialog);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_4->addWidget(label_4);

        passwordLineEdit = new QLineEdit(EditUserDialog);
        passwordLineEdit->setObjectName(QString::fromUtf8("passwordLineEdit"));

        horizontalLayout_4->addWidget(passwordLineEdit);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_5 = new QLabel(EditUserDialog);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_5->addWidget(label_5);

        depositTypeLabel = new QLabel(EditUserDialog);
        depositTypeLabel->setObjectName(QString::fromUtf8("depositTypeLabel"));

        horizontalLayout_5->addWidget(depositTypeLabel);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_6 = new QLabel(EditUserDialog);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_6->addWidget(label_6);

        interestRateLabel = new QLabel(EditUserDialog);
        interestRateLabel->setObjectName(QString::fromUtf8("interestRateLabel"));

        horizontalLayout_6->addWidget(interestRateLabel);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_7 = new QLabel(EditUserDialog);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout_7->addWidget(label_7);

        isLostCheckBox = new QCheckBox(EditUserDialog);
        isLostCheckBox->setObjectName(QString::fromUtf8("isLostCheckBox"));

        horizontalLayout_7->addWidget(isLostCheckBox);


        verticalLayout->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer);

        saveButton = new QPushButton(EditUserDialog);
        saveButton->setObjectName(QString::fromUtf8("saveButton"));

        horizontalLayout_8->addWidget(saveButton);

        cancelButton = new QPushButton(EditUserDialog);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));

        horizontalLayout_8->addWidget(cancelButton);


        verticalLayout->addLayout(horizontalLayout_8);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(EditUserDialog);

        QMetaObject::connectSlotsByName(EditUserDialog);
    } // setupUi

    void retranslateUi(QDialog *EditUserDialog)
    {
        EditUserDialog->setWindowTitle(QApplication::translate("EditUserDialog", "Dialog", nullptr));
        label->setText(QApplication::translate("EditUserDialog", "Account:", nullptr));
        accountLabel->setText(QApplication::translate("EditUserDialog", "TextLabel", nullptr));
        label_2->setText(QApplication::translate("EditUserDialog", "Name:", nullptr));
        nameLabel->setText(QApplication::translate("EditUserDialog", "TextLabel", nullptr));
        label_3->setText(QApplication::translate("EditUserDialog", "Address:", nullptr));
        label_4->setText(QApplication::translate("EditUserDialog", "Password:", nullptr));
        label_5->setText(QApplication::translate("EditUserDialog", "DepositType:", nullptr));
        depositTypeLabel->setText(QApplication::translate("EditUserDialog", "TextLabel", nullptr));
        label_6->setText(QApplication::translate("EditUserDialog", "InterestRate:", nullptr));
        interestRateLabel->setText(QApplication::translate("EditUserDialog", "TextLabel", nullptr));
        label_7->setText(QApplication::translate("EditUserDialog", "Status:", nullptr));
        isLostCheckBox->setText(QApplication::translate("EditUserDialog", "isLost", nullptr));
        saveButton->setText(QApplication::translate("EditUserDialog", "Save", nullptr));
        cancelButton->setText(QApplication::translate("EditUserDialog", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EditUserDialog: public Ui_EditUserDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITUSERDIALOG_H
