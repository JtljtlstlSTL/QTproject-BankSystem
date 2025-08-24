#include "adminpanel.h"
#include "edituserdialog.h"
#include "mainwindow.h"
#include "ui_adminpanel.h"

AdminPanel::AdminPanel(CustomerManager *manager,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AdminPanel),
    manager(manager),
    currentCustomer(nullptr)
{
    ui->setupUi(this);

    this->resize(1024, 768);

    // 控件的大小可以根据窗口动态调整
        ui->infoTextEdit->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

        // 设置文本编辑框自动换行和自动调整内容的宽度
        ui->infoTextEdit->setWordWrapMode(QTextOption::WrapAtWordBoundaryOrAnywhere);

    //connect(ui->searchButton, &QPushButton::clicked, this, &AdminPanel::on_searchButton_clicked);
    //connect(ui->editButton, &QPushButton::clicked, this, &AdminPanel::on_editButton_clicked);
    //connect(ui->backToLoginButton, &QPushButton::clicked, this, &AdminPanel::on_backToLoginButton_clicked);
}

AdminPanel::~AdminPanel()
{
    delete ui;
}

void AdminPanel::on_searchButton_clicked()
{
    QString accountNumber = ui->accountLineEdit->text();
       currentCustomer = manager->findCustomerByAccountNumber(accountNumber);

       if (currentCustomer) {
           QString info;
           double currentAccountTotal = currentCustomer->calculateCurrentAccountBalance();
           info += QString("账号: %1\n").arg(currentCustomer->getAccountNumber());
           info += QString("姓名: %1\n").arg(currentCustomer->getName());
           info += QString("地址: %1\n").arg(currentCustomer->getAddress());
           //info += QString("存款类型: %1\n").arg(currentCustomer->getDepositType());
           //info += QString("利率: %1\n").arg(currentCustomer->getInterestRate());
           info += QString("挂失状态: %1\n").arg(currentCustomer->isLost() ? "是" : "否");
           info += QString("余额: %1\n\n").arg(currentCustomer->getBalance());
           info += QString("活期存款总金额: %1\n\n").arg(currentAccountTotal, 0, 'f', 2);

           // 显示交易记录，包括日期、金额、类型、员工ID、存款期限和利率等信息
                   info += "交易记录:\n";
                   for (const Transaction &transaction : currentCustomer->getTransactions()) {
                       info += QString("日期: %1, 金额: %2, 类型: %3, 员工ID: %4, 存款期限: %5, 利率: %6\n")
                           .arg(transaction.getDate().toString("yyyy-MM-dd"))
                           .arg(transaction.getAmount(), 0, 'f', 2) // 金额格式为两位小数
                           .arg(transaction.getType())
                           .arg(transaction.getEmployeeID())
                           .arg(transaction.getTerm())  // 存款期限
                           .arg(transaction.getInterestRate(), 0, 'f', 4); // 利率格式为四位小数
           }

           ui->infoTextEdit->setPlainText(info);
       } else {
           ui->infoTextEdit->setPlainText("未找到该账号的用户！");
       }
}

void AdminPanel::on_editButton_clicked()
{
    if (currentCustomer) {
            EditUserDialog editUserDialog(currentCustomer, this);
            if (editUserDialog.exec() == QDialog::Accepted) {
                on_searchButton_clicked();
            }
        } else {
            ui->infoTextEdit->setPlainText("请先搜索用户！");
        }
}

void AdminPanel::on_backToLoginButton_clicked()
{
    this->hide();
    MainWindow *mainwindow=new MainWindow(manager,false);
    mainwindow->show();
}
