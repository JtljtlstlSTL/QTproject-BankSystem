/********************************************************************************
** Form generated from reading UI file 'reportlostdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REPORTLOSTDIALOG_H
#define UI_REPORTLOSTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ReportLostDialog
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *confirmButton;
    QPushButton *cancelButton;

    void setupUi(QDialog *ReportLostDialog)
    {
        if (ReportLostDialog->objectName().isEmpty())
            ReportLostDialog->setObjectName(QString::fromUtf8("ReportLostDialog"));
        ReportLostDialog->resize(400, 300);
        verticalLayout = new QVBoxLayout(ReportLostDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(ReportLostDialog);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        confirmButton = new QPushButton(ReportLostDialog);
        confirmButton->setObjectName(QString::fromUtf8("confirmButton"));

        horizontalLayout->addWidget(confirmButton);

        cancelButton = new QPushButton(ReportLostDialog);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));

        horizontalLayout->addWidget(cancelButton);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(ReportLostDialog);

        QMetaObject::connectSlotsByName(ReportLostDialog);
    } // setupUi

    void retranslateUi(QDialog *ReportLostDialog)
    {
        ReportLostDialog->setWindowTitle(QApplication::translate("ReportLostDialog", "Dialog", nullptr));
        label->setText(QApplication::translate("ReportLostDialog", "\346\230\257\345\220\246\347\241\256\350\256\244\346\214\202\345\244\261\357\274\237", nullptr));
        confirmButton->setText(QApplication::translate("ReportLostDialog", "Confirm", nullptr));
        cancelButton->setText(QApplication::translate("ReportLostDialog", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ReportLostDialog: public Ui_ReportLostDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REPORTLOSTDIALOG_H
