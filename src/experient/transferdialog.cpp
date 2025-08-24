#include "transferdialog.h"
#include "ui_transferdialog.h"

TransferDialog::TransferDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TransferDialog)
{
    ui->setupUi(this);

    setWindowTitle("转账");

    //connect(ui->okButton, &QPushButton::clicked, this, &TransferDialog::on_okButton_clicked);
    //connect(ui->cancelButton, &QPushButton::clicked, this, &TransferDialog::reject);
}

TransferDialog::~TransferDialog()
{
    delete ui;
}

QString TransferDialog::getReceiverID() const
{
    return ui->receiverIDLineEdit->text();
}

double TransferDialog::getTransferAmount() const
{
    return ui->amountLineEdit->text().toDouble();
}

void TransferDialog::on_okButton_clicked()
{
    if (ui->receiverIDLineEdit->text().isEmpty() || ui->amountLineEdit->text().toDouble() <= 0) {
            QMessageBox::warning(this, "错误", "请输入有效的客户 ID 和转账金额！");
            return;
        }

        accept();
}
