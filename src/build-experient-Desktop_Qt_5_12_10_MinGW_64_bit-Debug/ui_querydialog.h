/********************************************************************************
** Form generated from reading UI file 'querydialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QUERYDIALOG_H
#define UI_QUERYDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_QueryDialog
{
public:
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_3;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *accountNumberLabel;
    QLabel *nameLabel;
    QLabel *balanceLabel;
    QLabel *lostStatusLabel;
    QLabel *currentAccountTotalLabel;
    QTableWidget *transactionTableWidget;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *QueryDialog)
    {
        if (QueryDialog->objectName().isEmpty())
            QueryDialog->setObjectName(QString::fromUtf8("QueryDialog"));
        QueryDialog->resize(287, 341);
        verticalLayout_4 = new QVBoxLayout(QueryDialog);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label = new QLabel(QueryDialog);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout_3->addWidget(label);

        label_2 = new QLabel(QueryDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_3->addWidget(label_2);

        label_3 = new QLabel(QueryDialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout_3->addWidget(label_3);

        label_4 = new QLabel(QueryDialog);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout_3->addWidget(label_4);

        label_5 = new QLabel(QueryDialog);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        verticalLayout_3->addWidget(label_5);


        horizontalLayout->addLayout(verticalLayout_3);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        accountNumberLabel = new QLabel(QueryDialog);
        accountNumberLabel->setObjectName(QString::fromUtf8("accountNumberLabel"));

        verticalLayout->addWidget(accountNumberLabel);

        nameLabel = new QLabel(QueryDialog);
        nameLabel->setObjectName(QString::fromUtf8("nameLabel"));

        verticalLayout->addWidget(nameLabel);

        balanceLabel = new QLabel(QueryDialog);
        balanceLabel->setObjectName(QString::fromUtf8("balanceLabel"));

        verticalLayout->addWidget(balanceLabel);

        lostStatusLabel = new QLabel(QueryDialog);
        lostStatusLabel->setObjectName(QString::fromUtf8("lostStatusLabel"));

        verticalLayout->addWidget(lostStatusLabel);


        verticalLayout_2->addLayout(verticalLayout);

        currentAccountTotalLabel = new QLabel(QueryDialog);
        currentAccountTotalLabel->setObjectName(QString::fromUtf8("currentAccountTotalLabel"));

        verticalLayout_2->addWidget(currentAccountTotalLabel);


        horizontalLayout->addLayout(verticalLayout_2);


        verticalLayout_4->addLayout(horizontalLayout);

        transactionTableWidget = new QTableWidget(QueryDialog);
        transactionTableWidget->setObjectName(QString::fromUtf8("transactionTableWidget"));

        verticalLayout_4->addWidget(transactionTableWidget);

        buttonBox = new QDialogButtonBox(QueryDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout_4->addWidget(buttonBox);


        retranslateUi(QueryDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), QueryDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), QueryDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(QueryDialog);
    } // setupUi

    void retranslateUi(QDialog *QueryDialog)
    {
        QueryDialog->setWindowTitle(QApplication::translate("QueryDialog", "Dialog", nullptr));
        label->setText(QApplication::translate("QueryDialog", "\350\264\246\345\217\267\357\274\232", nullptr));
        label_2->setText(QApplication::translate("QueryDialog", "\345\247\223\345\220\215\357\274\232", nullptr));
        label_3->setText(QApplication::translate("QueryDialog", "\344\275\231\351\242\235\357\274\232", nullptr));
        label_4->setText(QApplication::translate("QueryDialog", "\347\212\266\346\200\201\357\274\232", nullptr));
        label_5->setText(QApplication::translate("QueryDialog", "\346\264\273\346\234\237\357\274\232", nullptr));
        accountNumberLabel->setText(QApplication::translate("QueryDialog", "222222", nullptr));
        nameLabel->setText(QApplication::translate("QueryDialog", "222222", nullptr));
        balanceLabel->setText(QApplication::translate("QueryDialog", "222222", nullptr));
        lostStatusLabel->setText(QApplication::translate("QueryDialog", "222222", nullptr));
        currentAccountTotalLabel->setText(QApplication::translate("QueryDialog", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QueryDialog: public Ui_QueryDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QUERYDIALOG_H
