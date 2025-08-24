#ifndef TRANSFERDIALOG_H
#define TRANSFERDIALOG_H

#include "customermanager.h"

#include <QDialog>
#include<QMessageBox>

namespace Ui {
class TransferDialog;
}

class TransferDialog : public QDialog
{
    Q_OBJECT

public:
    explicit TransferDialog(QWidget *parent = nullptr);
    ~TransferDialog();

    QString getReceiverID() const;
    double getTransferAmount() const;

private slots:
    void on_okButton_clicked();

private:
    Ui::TransferDialog *ui;
    //CustomerManager* manager;
    //Customer* sender;
};

#endif // TRANSFERDIALOG_H
