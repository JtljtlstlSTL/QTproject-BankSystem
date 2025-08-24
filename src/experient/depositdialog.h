#ifndef DEPOSITDIALOG_H
#define DEPOSITDIALOG_H

#include <QDialog>

namespace Ui {
class DepositDialog;
}

class DepositDialog : public QDialog
{
    Q_OBJECT

public:
    explicit DepositDialog(QWidget *parent = nullptr);
    ~DepositDialog();

    double getDepositAmount() const;
    QString getDepositTerm() const;
    QString getAccountNumber() const;

private:
    Ui::DepositDialog *ui;
};

#endif // DEPOSITDIALOG_H
