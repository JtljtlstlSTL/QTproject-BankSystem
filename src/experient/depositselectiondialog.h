#ifndef DEPOSITSELECTIONDIALOG_H
#define DEPOSITSELECTIONDIALOG_H

#include "transaction.h"

#include <QDialog>
#include <QListWidget>

namespace Ui {
class DepositSelectionDialog;
}

class DepositSelectionDialog : public QDialog
{
    Q_OBJECT

public:
    explicit DepositSelectionDialog(const QList<Transaction>& deposits,QWidget *parent = nullptr);
    Transaction getSelectedDeposit() const;
    ~DepositSelectionDialog();

private:
    Ui::DepositSelectionDialog *ui;
    QListWidget *listWidget;
    QList<Transaction> depositList;
};

#endif // DEPOSITSELECTIONDIALOG_H
