#ifndef QUERYDIALOG_H
#define QUERYDIALOG_H

#include "customer.h"

#include <QDialog>
#include<QDebug>

namespace Ui {
class QueryDialog;
}

class QueryDialog : public QDialog
{
    Q_OBJECT

public:
    explicit QueryDialog(Customer *customer,QWidget *parent = nullptr);
    ~QueryDialog();

private:
    Ui::QueryDialog *ui;
    Customer *currentCustomer;
    void displayCustomerInfo();  // 用于显示客户信息的函数
};

#endif // QUERYDIALOG_H
