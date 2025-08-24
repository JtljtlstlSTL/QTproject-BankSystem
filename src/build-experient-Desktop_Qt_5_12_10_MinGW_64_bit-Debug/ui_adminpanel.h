/********************************************************************************
** Form generated from reading UI file 'adminpanel.ui'
**
** Created by: Qt User Interface Compiler version 5.12.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINPANEL_H
#define UI_ADMINPANEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_AdminPanel
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *accountLineEdit;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *searchButton;
    QPushButton *editButton;
    QTextEdit *infoTextEdit;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QPushButton *backToLoginButton;

    void setupUi(QDialog *AdminPanel)
    {
        if (AdminPanel->objectName().isEmpty())
            AdminPanel->setObjectName(QString::fromUtf8("AdminPanel"));
        AdminPanel->resize(400, 300);
        verticalLayout_2 = new QVBoxLayout(AdminPanel);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(AdminPanel);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        accountLineEdit = new QLineEdit(AdminPanel);
        accountLineEdit->setObjectName(QString::fromUtf8("accountLineEdit"));

        horizontalLayout->addWidget(accountLineEdit);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        searchButton = new QPushButton(AdminPanel);
        searchButton->setObjectName(QString::fromUtf8("searchButton"));

        horizontalLayout_2->addWidget(searchButton);

        editButton = new QPushButton(AdminPanel);
        editButton->setObjectName(QString::fromUtf8("editButton"));

        horizontalLayout_2->addWidget(editButton);


        verticalLayout->addLayout(horizontalLayout_2);

        infoTextEdit = new QTextEdit(AdminPanel);
        infoTextEdit->setObjectName(QString::fromUtf8("infoTextEdit"));

        verticalLayout->addWidget(infoTextEdit);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        backToLoginButton = new QPushButton(AdminPanel);
        backToLoginButton->setObjectName(QString::fromUtf8("backToLoginButton"));

        horizontalLayout_3->addWidget(backToLoginButton);


        verticalLayout->addLayout(horizontalLayout_3);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(AdminPanel);

        QMetaObject::connectSlotsByName(AdminPanel);
    } // setupUi

    void retranslateUi(QDialog *AdminPanel)
    {
        AdminPanel->setWindowTitle(QApplication::translate("AdminPanel", "Dialog", nullptr));
        label->setText(QApplication::translate("AdminPanel", "\347\224\250\346\210\267\350\264\246\345\217\267\357\274\232", nullptr));
        searchButton->setText(QApplication::translate("AdminPanel", "Search", nullptr));
        editButton->setText(QApplication::translate("AdminPanel", "Edit", nullptr));
        backToLoginButton->setText(QApplication::translate("AdminPanel", "Back", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AdminPanel: public Ui_AdminPanel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINPANEL_H
