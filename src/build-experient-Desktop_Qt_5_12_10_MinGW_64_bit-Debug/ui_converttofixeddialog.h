/********************************************************************************
** Form generated from reading UI file 'converttofixeddialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONVERTTOFIXEDDIALOG_H
#define UI_CONVERTTOFIXEDDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ConvertToFixedDialog
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QLineEdit *amountLineEdit;
    QComboBox *termComboBox;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *convertButton;
    QPushButton *pushButton;

    void setupUi(QDialog *ConvertToFixedDialog)
    {
        if (ConvertToFixedDialog->objectName().isEmpty())
            ConvertToFixedDialog->setObjectName(QString::fromUtf8("ConvertToFixedDialog"));
        ConvertToFixedDialog->resize(400, 300);
        verticalLayout_2 = new QVBoxLayout(ConvertToFixedDialog);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(ConvertToFixedDialog);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        amountLineEdit = new QLineEdit(ConvertToFixedDialog);
        amountLineEdit->setObjectName(QString::fromUtf8("amountLineEdit"));

        horizontalLayout->addWidget(amountLineEdit);

        termComboBox = new QComboBox(ConvertToFixedDialog);
        termComboBox->addItem(QString());
        termComboBox->addItem(QString());
        termComboBox->addItem(QString());
        termComboBox->setObjectName(QString::fromUtf8("termComboBox"));

        horizontalLayout->addWidget(termComboBox);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        convertButton = new QPushButton(ConvertToFixedDialog);
        convertButton->setObjectName(QString::fromUtf8("convertButton"));

        horizontalLayout_2->addWidget(convertButton);

        pushButton = new QPushButton(ConvertToFixedDialog);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout_2->addWidget(pushButton);


        verticalLayout->addLayout(horizontalLayout_2);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(ConvertToFixedDialog);

        QMetaObject::connectSlotsByName(ConvertToFixedDialog);
    } // setupUi

    void retranslateUi(QDialog *ConvertToFixedDialog)
    {
        ConvertToFixedDialog->setWindowTitle(QApplication::translate("ConvertToFixedDialog", "Dialog", nullptr));
        label->setText(QApplication::translate("ConvertToFixedDialog", "\350\257\267\350\276\223\345\205\245\351\207\221\351\242\235", nullptr));
        termComboBox->setItemText(0, QApplication::translate("ConvertToFixedDialog", "1\345\271\264", nullptr));
        termComboBox->setItemText(1, QApplication::translate("ConvertToFixedDialog", "3\345\271\264", nullptr));
        termComboBox->setItemText(2, QApplication::translate("ConvertToFixedDialog", "5\345\271\264", nullptr));

        convertButton->setText(QApplication::translate("ConvertToFixedDialog", "Confirm", nullptr));
        pushButton->setText(QApplication::translate("ConvertToFixedDialog", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ConvertToFixedDialog: public Ui_ConvertToFixedDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONVERTTOFIXEDDIALOG_H
