#include "filemanager.h"
#include "mainwindow.h"
#include "registerdialog.h"
#include "ui_registerdialog.h"

#include<QUuid>
#include<QMessageBox>

RegisterDialog::RegisterDialog(CustomerManager* manager,QWidget *parent) :
    QDialog(parent),
    manager(manager),
  ui(new Ui::RegisterDialog)
{
    ui->setupUi(this);
    setWindowTitle("注册");
    accountNumber = generateUniqueAccountNumber();
        displayAccountNumber();

    //connect(ui->buttonBox, &QDialogButtonBox::accepted, this, &RegisterDialog::on_buttonBox_accepted);
}

RegisterDialog::~RegisterDialog()
{
    delete ui;
}

QString RegisterDialog::generateUniqueAccountNumber()
{
    QString accountNumber;

    do {
        accountNumber = QUuid::createUuid().toString().remove('{').remove('}').remove('-').left(10);
    } while (manager->findCustomerByAccountNumber(accountNumber));

    return accountNumber;
}

void RegisterDialog::displayAccountNumber()
{
    ui->accountNumberLabel->setText("账号："+ accountNumber);
}

void RegisterDialog::on_buttonBox_accepted()
{
    // 获取用户输入的注册信息
       QString name = ui->setNameEdit->text();
       QString password = ui->setPasswordEdit->text();
       QString address = ui->setAddressEdit->text();

       // 检查输入是否为空
       if (name.isEmpty() || password.isEmpty() || address.isEmpty()) {
           QMessageBox::warning(this, tr("Input Error"), tr("Name, password, and address cannot be empty"));
           return;
       }

       // 打印调试信息
       qDebug() << "Name: " << name << ", Password: " << password << ", Address: " << address;

       // 生成唯一账号
       QString accountNumber = generateUniqueAccountNumber();
       qDebug() << "Generated Account Number: " << accountNumber;

       try {
           // 创建新客户
           Customer newCustomer(accountNumber, name, password, address, "xxx", 0, "user");
           qDebug() << "Customer Created: " << newCustomer.getName();

           // 将新客户添加到管理器
           manager->addCustomer(newCustomer);
           qDebug() << "Customer Added to Manager";

           // 使用 FileManager 保存客户数据
           FileManager fileManager;
           bool success = fileManager.saveData("customers.txt", *manager);

           if (success) {
               qDebug() << "Data Saved Successfully";
               QMessageBox::information(this, "Success", "Customer registered and data saved successfully!");

               // 关闭注册窗口，但不退出程序

               this->hide();
               //accept();
               MainWindow *mainwindow=new MainWindow(manager,false);
               mainwindow->show();
           } else {
               qDebug() << "Data Saving Failed";
               QMessageBox::warning(this, "Error", "Failed to save customer data.");
           }

       } catch (std::exception& e) {
           qDebug() << "Exception while processing registration: " << e.what();
           QMessageBox::critical(this, "Error", "An error occurred during registration.");
       }

    /*QString name = ui->setNameEdit->text();
        QString password = ui->setPasswordEdit->text();
        QString address = ui->setAddressEdit->text();

        if (name.isEmpty() || password.isEmpty() || address.isEmpty()) {
            QMessageBox::warning(this, tr("Input Error"), tr("Name, password, and address cannot be empty"));
            return;
        }

        QString accountNumber = generateUniqueAccountNumber();

        Customer newCustomer(accountNumber, name, password, address, "xxx", 0, "user");

        manager->addCustomer(newCustomer);

        // 使用FileManager将所有客户数据保存到文件
            FileManager fileManager;
            bool success = fileManager.saveData("customers.txt", *manager);
            if (success) {
                QMessageBox::information(this, "Success", "Customer registered and data saved successfully!");
            } else {
                QMessageBox::warning(this, "Error", "Failed to save customer data.");
            }
        accept();*/
}
