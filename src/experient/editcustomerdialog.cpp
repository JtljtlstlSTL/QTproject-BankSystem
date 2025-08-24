#include "editcustomerdialog.h"
#include "ui_editcustomerdialog.h"

#include <QMessageBox>

EditCustomerDialog::EditCustomerDialog(Customer *customer,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditCustomerDialog),
    customer(customer)
{
    ui->setupUi(this);

    //this->resize(1024, 768);

    //connect(ui->changePasswordButton, &QPushButton::clicked, this, &EditCustomerDialog::on_changePasswordButton_clicked);
}

EditCustomerDialog::~EditCustomerDialog()
{
    delete ui;
}

void EditCustomerDialog::on_changePasswordButton_clicked()
{
    QString oldPassword = ui->oldPasswordEdit->text();
    QString newPassword = ui->newPasswordEdit->text();
    QString confirmPassword = ui->confirmPasswordEdit->text();

        // 验证原密码是否正确
        if (oldPassword != customer->getPassword()) {
            QMessageBox::warning(this, "错误", "原密码不正确！");
            return;
        }

        // 验证新密码是否匹配
        if (newPassword != confirmPassword) {
            QMessageBox::warning(this, "错误", "新密码不匹配！");
            return;
        }

        // 更新客户密码
        customer->setPassword(newPassword);
        QMessageBox::information(this, "成功", "密码已成功更改！");
}

void EditCustomerDialog::on_cancelButton_clicked()
{
    reject();
}
