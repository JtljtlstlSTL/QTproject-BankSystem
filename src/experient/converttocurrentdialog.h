#ifndef CONVERTTOCURRENTDIALOG_H
#define CONVERTTOCURRENTDIALOG_H

#include "customer.h"

#include <QDialog>
#include<QDebug>

namespace Ui {
class ConvertToCurrentDialog;
}

class ConvertToCurrentDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ConvertToCurrentDialog(QWidget *parent = nullptr,Customer *customer=nullptr);
    ~ConvertToCurrentDialog();

private slots:
    void on_convertButton_clicked();

    void on_pushButton_clicked();

    void populateDepositList();

private:
    Ui::ConvertToCurrentDialog *ui;
    Customer *customer;  // 用于存储客户信息的指针
};

#endif // CONVERTTOCURRENTDIALOG_H
