/********************************************************************************
** Form generated from reading UI file 'transferdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRANSFERDIALOG_H
#define UI_TRANSFERDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_TransferDialog
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *receiverIDLineEdit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *amountLineEdit;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *okButton;
    QPushButton *cancelButton;

    void setupUi(QDialog *TransferDialog)
    {
        if (TransferDialog->objectName().isEmpty())
            TransferDialog->setObjectName(QString::fromUtf8("TransferDialog"));
        TransferDialog->resize(400, 300);
        verticalLayout_2 = new QVBoxLayout(TransferDialog);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(TransferDialog);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        receiverIDLineEdit = new QLineEdit(TransferDialog);
        receiverIDLineEdit->setObjectName(QString::fromUtf8("receiverIDLineEdit"));

        horizontalLayout->addWidget(receiverIDLineEdit);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(TransferDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        amountLineEdit = new QLineEdit(TransferDialog);
        amountLineEdit->setObjectName(QString::fromUtf8("amountLineEdit"));

        horizontalLayout_2->addWidget(amountLineEdit);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        okButton = new QPushButton(TransferDialog);
        okButton->setObjectName(QString::fromUtf8("okButton"));

        horizontalLayout_3->addWidget(okButton);

        cancelButton = new QPushButton(TransferDialog);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));

        horizontalLayout_3->addWidget(cancelButton);


        verticalLayout->addLayout(horizontalLayout_3);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(TransferDialog);

        QMetaObject::connectSlotsByName(TransferDialog);
    } // setupUi

    void retranslateUi(QDialog *TransferDialog)
    {
        TransferDialog->setWindowTitle(QApplication::translate("TransferDialog", "Dialog", nullptr));
        label->setText(QApplication::translate("TransferDialog", "\346\216\245\346\224\266\346\226\271\345\256\242\346\210\267ID:", nullptr));
        label_2->setText(QApplication::translate("TransferDialog", "\350\275\254\350\264\246\351\207\221\351\242\235:", nullptr));
        okButton->setText(QApplication::translate("TransferDialog", "Ok", nullptr));
        cancelButton->setText(QApplication::translate("TransferDialog", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TransferDialog: public Ui_TransferDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRANSFERDIALOG_H
