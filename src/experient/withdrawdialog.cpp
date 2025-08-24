#include "withdrawdialog.h"
#include "ui_withdrawdialog.h"

WithdrawDialog::WithdrawDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WithdrawDialog)
{
    ui->setupUi(this);
    setWindowTitle("取款");
}

WithdrawDialog::~WithdrawDialog()
{
    delete ui;
}

double WithdrawDialog::getWithdrawAmount() const
{
    return ui->amountEdit->text().toDouble();
}

QString WithdrawDialog::getAccountNumber() const
{
    return ui->accountNumberEdit->text();
}
