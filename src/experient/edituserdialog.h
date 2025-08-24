#ifndef EDITUSERDIALOG_H
#define EDITUSERDIALOG_H

#include "customer.h"

#include <QDialog>

namespace Ui {
class EditUserDialog;
}

class EditUserDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EditUserDialog(Customer* customer,QWidget *parent = nullptr);
    ~EditUserDialog();

private slots:
    void on_saveButton_clicked();

private:
    Ui::EditUserDialog *ui;
    Customer* customer;
};

#endif // EDITUSERDIALOG_H
