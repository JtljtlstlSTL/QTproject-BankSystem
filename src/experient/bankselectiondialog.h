#ifndef BANKSELECTIONDIALOG_H
#define BANKSELECTIONDIALOG_H

#include "login.h"

#include <QWidget>

namespace Ui {
class BankSelectionDialog;
}

class BankSelectionDialog : public QWidget
{
    Q_OBJECT

public:
    explicit BankSelectionDialog(CustomerManager* manager,QWidget *parent = nullptr);
    ~BankSelectionDialog();

private slots:
    void on_OfflineButton_clicked();

    void on_OnlineButton_clicked();

private:
    Ui::BankSelectionDialog *ui;
    CustomerManager* manager;
};

#endif // BANKSELECTIONDIALOG_H
