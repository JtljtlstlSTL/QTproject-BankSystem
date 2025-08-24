#include "edituserdialog.h"
#include "ui_edituserdialog.h"

EditUserDialog::EditUserDialog(Customer* customer,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditUserDialog),
    customer(customer)
{
    ui->setupUi(this);

    //this->resize(1024, 768);

        ui->accountLabel->setText(customer->getAccountNumber());
        ui->nameLabel->setText(customer->getName());
        ui->addressLineEdit->setText(customer->getAddress());
        ui->passwordLineEdit->setText(customer->getPassword());
        ui->depositTypeLabel->setText(customer->getDepositType());
        ui->interestRateLabel->setText(QString::number(customer->getInterestRate()));
        ui->isLostCheckBox->setChecked(customer->isLost());

        //connect(ui->saveButton, &QPushButton::clicked, this, &EditUserDialog::on_saveButton_clicked);
}

EditUserDialog::~EditUserDialog()
{
    delete ui;
}

void EditUserDialog::on_saveButton_clicked()
{
    customer->setPassword(ui->passwordLineEdit->text());
    customer->getPassword();
    customer->setAddress(ui->addressLineEdit->text());
    customer->setLost(ui->isLostCheckBox->isChecked());

       accept(); // 关闭对话框并接受
}
