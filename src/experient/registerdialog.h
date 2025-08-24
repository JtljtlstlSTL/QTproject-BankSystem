#ifndef REGISTERDIALOG_H
#define REGISTERDIALOG_H

#include "customer.h"
#include "customermanager.h"

#include <QDialog>

namespace Ui {
class RegisterDialog;
}

class RegisterDialog : public QDialog
{
    Q_OBJECT

public:
    explicit RegisterDialog(CustomerManager* manager,QWidget *parent = nullptr);
    ~RegisterDialog();

    CustomerManager* manager;
    QString accountNumber;

    QString generateUniqueAccountNumber();
    void displayAccountNumber();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::RegisterDialog *ui;

signals:
    void registrationSuccess();
};

#endif // REGISTERDIALOG_H
