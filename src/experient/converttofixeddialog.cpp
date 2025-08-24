#include "converttofixeddialog.h"
#include "ui_converttofixeddialog.h"

#include<QMessageBox>

ConvertToFixedDialog::ConvertToFixedDialog(QWidget *parent,Customer *customer) :
    QDialog(parent),
    ui(new Ui::ConvertToFixedDialog),
    customer(customer)
{
    ui->setupUi(this);

    setWindowTitle("活期转定期");

    //this->resize(1024, 768);

    //connect(ui->convertButton, &QPushButton::clicked, this, &ConvertToFixedDialog::on_convertButton_clicked);
}

ConvertToFixedDialog::~ConvertToFixedDialog()
{
    delete ui;
}

void ConvertToFixedDialog::on_convertButton_clicked()
{
        double amount = ui->amountLineEdit->text().toDouble();
        QString term = ui->termComboBox->currentText();

        // 检查活期账户余额是否足够
        double currentBalance = customer->calculateCurrentAccountBalance();
        if (amount > currentBalance) {
            // 如果余额不足，提示错误并返回
            QMessageBox::warning(this, "余额不足", "活期账户余额不足以转为定期存款。");
            return;
        }

        double rate = 0.0;
        if (term == "1年") {
            rate = 0.0198;
        } else if (term == "3年") {
            rate = 0.0225;
        } else if (term == "5年") {
            rate = 0.035;
        }

        //customer->setBalance(customer->getBalance() - amount);

        Transaction depositTransaction(QDate::currentDate(), amount, "活期转定期", "system", term, rate);
        customer->addTransaction(depositTransaction);

        QMessageBox::information(this, "转定期成功", "您已成功将活期存款转为定期存款。");

        accept();
}

void ConvertToFixedDialog::on_pushButton_clicked()
{
    reject();
}
