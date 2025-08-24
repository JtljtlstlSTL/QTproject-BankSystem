#ifndef CONVERTTOFIXEDDIALOG_H
#define CONVERTTOFIXEDDIALOG_H

#include "customer.h"

#include <QDialog>

namespace Ui {
class ConvertToFixedDialog;
}

class ConvertToFixedDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ConvertToFixedDialog(QWidget *parent = nullptr,Customer *customer=nullptr);
    ~ConvertToFixedDialog();

private slots:
    void on_convertButton_clicked();

    void on_pushButton_clicked();

private:
    Ui::ConvertToFixedDialog *ui;
    Customer *customer;
};

#endif // CONVERTTOFIXEDDIALOG_H
