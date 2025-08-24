#ifndef EDITCUSTOMERDIALOG_H
#define EDITCUSTOMERDIALOG_H

#include "customer.h"

#include <QDialog>

namespace Ui {
class EditCustomerDialog;
}

class EditCustomerDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EditCustomerDialog(Customer *customer,QWidget *parent = nullptr);
    ~EditCustomerDialog();

private slots:
    void on_changePasswordButton_clicked();

    void on_cancelButton_clicked();

private:
    Ui::EditCustomerDialog *ui;
    Customer *customer;
};

#endif // EDITCUSTOMERDIALOG_H
