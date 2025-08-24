/********************************************************************************
** Form generated from reading UI file 'depositselectiondialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEPOSITSELECTIONDIALOG_H
#define UI_DEPOSITSELECTIONDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_DepositSelectionDialog
{
public:

    void setupUi(QDialog *DepositSelectionDialog)
    {
        if (DepositSelectionDialog->objectName().isEmpty())
            DepositSelectionDialog->setObjectName(QString::fromUtf8("DepositSelectionDialog"));
        DepositSelectionDialog->resize(400, 300);

        retranslateUi(DepositSelectionDialog);

        QMetaObject::connectSlotsByName(DepositSelectionDialog);
    } // setupUi

    void retranslateUi(QDialog *DepositSelectionDialog)
    {
        DepositSelectionDialog->setWindowTitle(QApplication::translate("DepositSelectionDialog", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DepositSelectionDialog: public Ui_DepositSelectionDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEPOSITSELECTIONDIALOG_H
