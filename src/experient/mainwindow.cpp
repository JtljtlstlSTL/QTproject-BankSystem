#include "adminpanel.h"
#include "converttocurrentdialog.h"
#include "converttofixeddialog.h"
#include "depositdialog.h"
#include "editcustomerdialog.h"
#include "filemanager.h"
#include "loadingdialog.h"
#include "login.h"
#include "mainwindow.h"
#include "querydialog.h"
#include "registerdialog.h"
#include "reportlostdialog.h"
#include "transferdialog.h"
#include "ui_mainwindow.h"
#include "withdrawdialog.h"

#include <QMessageBox>
#include <QTimer>
#include<QInputDialog>
#include<QLineEdit>

MainWindow::MainWindow(CustomerManager* manager,bool isOnline,QWidget *parent)
    : QMainWindow(parent)
    ,ui(new Ui::MainWindow)
    , manager(manager)
    ,currentCustomer(nullptr)
    ,isOnline(isOnline)
{
    ui->setupUi(this);

    if (isOnline) {
        // 禁用存款和取款功能
           ui->depositButton->setEnabled(false);
           ui->withdrawButton->setEnabled(false);
           ui->registerButton->setEnabled(false);
           ui->inquireButton->setEnabled(false);
           ui->closeAccountButton->setEnabled(false);

           ui->depositButton->hide();
           ui->withdrawButton->hide();
           ui->registerButton->hide();
           ui->inquireButton->hide();
           ui->closeAccountButton->hide();
       }
    if (!isOnline){
        ui->convertToCurrentButton->setEnabled(false);
        ui->convertToFixedButton->setEnabled(false);
        ui->settingsButton->setEnabled(false);
        ui->queryButton->setEnabled(false);
        ui->reportLostButton->setEnabled(false);
        ui->transferButton->setEnabled(false);

        ui->convertToCurrentButton->hide();
        ui->convertToFixedButton->hide();
        ui->settingsButton->hide();
        ui->queryButton->hide();
        ui->reportLostButton->hide();
        ui->transferButton->hide();
    }

    setWindowTitle("主页面");

    this->resize(1024, 768);

    QPixmap pixmapa("C:/Users/LEGION/Desktop/logo");
    ui->logo->setPixmap(pixmapa);
    ui->logo->setScaledContents(true); // 自动缩放内容以适应 QLabel
    ui->logo->setFixedSize(300, 90);

    QPixmap pixmapa1("C:/Users/LEGION/Desktop/logo_2");
    ui->logo_2->setPixmap(pixmapa1);
    ui->logo_2->setScaledContents(true); // 自动缩放内容以适应 QLabel
    ui->logo_2->setFixedSize(400, 600);

    ui->depositButton->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    ui->withdrawButton->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    ui->convertToFixedButton->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    ui->convertToCurrentButton->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    ui->transferButton->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    ui->reportLostButton->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    ui->settingsButton->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    ui->queryButton->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    ui->exitButton->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);

    //connect(ui->depositButton, &QPushButton::clicked, this, &MainWindow::on_depositButton_clicked);
    //connect(ui->withdrawButton, &QPushButton::clicked, this, &MainWindow::on_withdrawButton_clicked);
    //connect(ui->convertToFixedButton, &QPushButton::clicked, this, &MainWindow::on_convertToFixedButton_clicked);
    //connect(ui->convertToCurrentButton, &QPushButton::clicked, this, &MainWindow::on_convertToCurrentButton_clicked);
}

MainWindow::~MainWindow()
{
    // 程序关闭前保存所有客户数据
        FileManager fileManager;
        //fileManager.saveData("customers.db", *manager); // 使用数据库文件路径
        fileManager.saveData("customers.txt", *manager);
        delete ui;
}

void MainWindow::setCurrentCustomer(Customer *customer)
{
    currentCustomer = customer;
    updateUI();
}


void MainWindow::on_exitButton_clicked()
{

    /*Login *l= new Login(manager,nullptr); // 传递 manager 指针
        l->show();
        close();*/
    BankSelectionDialog *b=new BankSelectionDialog(manager);
    b->show();
    hide();
}

void MainWindow::on_depositButton_clicked()
{
    /*if (!currentCustomer) {
            QMessageBox::warning(this, "错误", "当前没有登录的用户。");
            return;
        }

        LoadingDialog *loadingDialog = new LoadingDialog(this);
        loadingDialog->show();

        QTimer::singleShot(1000, [this, loadingDialog] {

            DepositDialog depositDialog(this);

            // 当用户完成存款操作时
            if (depositDialog.exec() == QDialog::Accepted) {
                double amount = depositDialog.getDepositAmount();
                QString term = depositDialog.getDepositTerm();

                if (amount > 0) {
                    QString employeeID = "system";
                    currentCustomer->deposit(amount, term, employeeID);

                    QMessageBox::information(this, "存款成功", "存款已成功处理。");
                } else {
                    QMessageBox::warning(this, "存款错误", "请输入有效的存款金额！");
                }
            }

            loadingDialog->accept();
            loadingDialog->deleteLater();
        });*/

    DepositDialog depositDialog(this);

       if (depositDialog.exec() == QDialog::Accepted) {
           QString accountNumber = depositDialog.getAccountNumber();
           double amount = depositDialog.getDepositAmount();
           QString term = depositDialog.getDepositTerm();

           if (accountNumber.isEmpty()) {
               QMessageBox::warning(this, "输入错误", "请输入有效的账户号码。");
               return;
           }

           if (amount > 0) {
               Customer* customer = manager->findCustomerByAccountNumber(accountNumber);

               if (customer) {
                   QString employeeID = "system"; // 假设操作员ID
                   customer->deposit(amount, term, employeeID); // 调用 deposit() 函数将存款添加到找到的账户
                   QMessageBox::information(this, "存款成功", "存款已成功处理。");

                   qDebug() << "存款成功，账户号：" << accountNumber << " 存款金额：" << amount << " 存款期限：" << term;
               } else {
                   QMessageBox::warning(this, "账户错误", "未找到对应的账户。");
               }
           } else {
               QMessageBox::warning(this, "存款错误", "请输入有效的存款金额！");
           }
       }
}

void MainWindow::on_withdrawButton_clicked()
{
    // 创建一个对话框，用于输入取款账号和金额
       WithdrawDialog withdrawDialog(this);

       // 当用户完成取款操作时
       if (withdrawDialog.exec() == QDialog::Accepted) {
           QString accountNumber = withdrawDialog.getAccountNumber();
           double amount = withdrawDialog.getWithdrawAmount();

           if (accountNumber.isEmpty()) {
               QMessageBox::warning(this, "输入错误", "请输入有效的账户号码。");
               return;
           }

           if (amount <= 0) {
               QMessageBox::warning(this, "取款错误", "请输入有效的取款金额！");
               return;
           }

           // 使用 CustomerManager 查找账户
           Customer* customer = manager->findCustomerByAccountNumber(accountNumber);

           if (customer) {
               if (amount <= customer->getBalance()) {
                   QString employeeID = "system";  // 假设操作员ID
                   bool success = customer->withdraw(amount, employeeID); // 调用 withdraw() 函数进行取款操作

                   if (success) {
                       QMessageBox::information(this, "取款成功", "取款已成功处理。");
                       qDebug() << "取款成功，账户号：" << accountNumber << " 取款金额：" << amount;

                       // 更新余额标签
                       //ui->balanceLabel->setText(QString("余额: %1").arg(customer->getBalance(), 0, 'f', 2));
                   } else {
                       QMessageBox::warning(this, "取款错误", "取款失败。请检查账户状态或余额。");
                   }
               } else {
                   QMessageBox::warning(this, "取款错误", "余额不足！");
               }
           } else {
               QMessageBox::warning(this, "账户错误", "未找到对应的账户。");
           }
       }

    /*if (!currentCustomer) {
            QMessageBox::warning(this, "错误", "当前没有登录的用户。");
            return;
        }

        LoadingDialog *loadingDialog = new LoadingDialog(this);
        loadingDialog->show();

        QTimer::singleShot(1000, [this, loadingDialog] {
            WithdrawDialog withdrawDialog(this);

            // 当用户完成取款操作时
            if (withdrawDialog.exec() == QDialog::Accepted) {
                double amount = withdrawDialog.getWithdrawAmount();

                if (amount > 0 && amount <= currentCustomer->getBalance()) {
                    QString employeeID = "system";
                    currentCustomer->withdraw(amount, employeeID);

                    // 更新余额标签
                    // ui->balanceLabel->setText(QString("余额: %1").arg(currentCustomer->getBalance(), 0, 'f', 2));
                    QMessageBox::information(this, "取款成功", "取款已成功处理。");
                } else if (amount > currentCustomer->getBalance()) {
                    QMessageBox::warning(this, "取款错误", "余额不足！");
                } else {
                    QMessageBox::warning(this, "取款错误", "请输入有效的取款金额！");
                }
            }

            loadingDialog->accept();
        });*/

    /*// 创建一个对话框，用于输入取款账号
       WithdrawDialog withdrawDialog(this);

       // 当用户完成取款操作时
       if (withdrawDialog.exec() == QDialog::Accepted) {
           QString accountNumber = withdrawDialog.getAccountNumber();
           double amount = withdrawDialog.getWithdrawAmount();

           if (accountNumber.isEmpty()) {
               QMessageBox::warning(this, "输入错误", "请输入有效的账户号码。");
               return;
           }

           if (amount <= 0) {
               QMessageBox::warning(this, "取款错误", "请输入有效的取款金额！");
               return;
           }

           // 使用 CustomerManager 查找账户
           Customer* customer = manager->findCustomerByAccountNumber(accountNumber);

           if (customer) {
               if (amount <= customer->getBalance()) {
                   QString employeeID = "system";  // 假设操作员ID
                   customer->withdraw(amount, employeeID); // 调用 withdraw() 函数进行取款操作
                   QMessageBox::information(this, "取款成功", "取款已成功处理。");

                   qDebug() << "取款成功，账户号：" << accountNumber << " 取款金额：" << amount;
               } else {
                   QMessageBox::warning(this, "取款错误", "余额不足！");
               }
           } else {
               QMessageBox::warning(this, "账户错误", "未找到对应的账户。");
           }
       }*/
}

void MainWindow::on_queryButton_clicked()
{
    if (!currentCustomer) {
            QMessageBox::warning(this, "错误", "当前没有登录的用户。");
            return;
        }

        LoadingDialog *loadingDialog = new LoadingDialog(this);
        loadingDialog->show();

        QTimer::singleShot(1000, [this, loadingDialog] {
            QueryDialog queryDialog(currentCustomer, this);
            queryDialog.exec();
            loadingDialog->accept();
        });
}

void MainWindow::on_reportLostButton_clicked()
{
    if (!currentCustomer) {
            QMessageBox::warning(this, "错误", "当前没有登录的用户。");
            return;
        }

        LoadingDialog *loadingDialog = new LoadingDialog(this);
        loadingDialog->show();

        QTimer::singleShot(1000, [this, loadingDialog] {
            ReportLostDialog dialog(this);

            if (dialog.exec() == QDialog::Accepted) {
                currentCustomer->reportLoss(QDate::currentDate());

                currentCustomer->setLost(true);

                ui->depositButton->setEnabled(false);
                ui->withdrawButton->setEnabled(false);
                ui->convertToFixedButton->setEnabled(false);
                ui->convertToCurrentButton->setEnabled(false);
                ui->transferButton->setEnabled(false);
                ui->reportLostButton->setEnabled(false);

                updateUI();

                QMessageBox::information(this, "挂失成功", "您的账户已挂失。");
            }

            loadingDialog->accept();
        });
}

void MainWindow::on_settingsButton_clicked()
{
    if (currentCustomer) {
            LoadingDialog *loadingDialog = new LoadingDialog(this);
            loadingDialog->show();

            QTimer::singleShot(1000, [this, loadingDialog] {
                EditCustomerDialog editDialog(currentCustomer, this);

                if (editDialog.exec() == QDialog::Accepted) {
                    QMessageBox::information(this, "编辑成功", "客户信息已成功更新。");
                }

                loadingDialog->accept();
            });
        } else {
            QMessageBox::warning(this, "错误", "当前没有选中的客户。");
        }
}

void MainWindow::updateUI()
{
    if (currentCustomer) {
            if (currentCustomer->isLost()) {
                ui->depositButton->setEnabled(false);
                ui->withdrawButton->setEnabled(false);
                ui->convertToFixedButton->setEnabled(false);
                ui->convertToCurrentButton->setEnabled(false);
                ui->transferButton->setEnabled(false);
                ui->reportLostButton->setEnabled(false);

                // 设置禁用按钮的样式
                QString disabledStyle = "background-color: lightgray; color: gray;";
                ui->depositButton->setStyleSheet(disabledStyle);
                ui->withdrawButton->setStyleSheet(disabledStyle);
                ui->convertToFixedButton->setStyleSheet(disabledStyle);
                ui->convertToCurrentButton->setStyleSheet(disabledStyle);
                ui->transferButton->setStyleSheet(disabledStyle);
                ui->reportLostButton->setStyleSheet(disabledStyle);
            } else {
                ui->depositButton->setEnabled(true);
                ui->withdrawButton->setEnabled(true);
                ui->convertToFixedButton->setEnabled(true);
                ui->convertToCurrentButton->setEnabled(true);
                ui->transferButton->setEnabled(true);
                ui->reportLostButton->setEnabled(true);

                // 恢复按钮的样式
                QString enabledStyle = ""; // 清除样式表，恢复默认样式
                ui->depositButton->setStyleSheet(enabledStyle);
                ui->withdrawButton->setStyleSheet(enabledStyle);
                ui->convertToFixedButton->setStyleSheet(enabledStyle);
                ui->convertToCurrentButton->setStyleSheet(enabledStyle);
                ui->transferButton->setStyleSheet(enabledStyle);
                ui->reportLostButton->setStyleSheet(enabledStyle);
            }
        } else {
            ui->depositButton->setEnabled(false);
            ui->withdrawButton->setEnabled(false);
            ui->convertToFixedButton->setEnabled(false);
            ui->convertToCurrentButton->setEnabled(false);
            ui->transferButton->setEnabled(false);
            ui->reportLostButton->setEnabled(false);

            // 设置禁用按钮的样式
            QString disabledStyle = "background-color: lightgray; color: gray;";
            ui->depositButton->setStyleSheet(disabledStyle);
            ui->withdrawButton->setStyleSheet(disabledStyle);
            ui->convertToFixedButton->setStyleSheet(disabledStyle);
            ui->convertToCurrentButton->setStyleSheet(disabledStyle);
            ui->transferButton->setStyleSheet(disabledStyle);
            ui->reportLostButton->setStyleSheet(disabledStyle);
        }
}

void MainWindow::on_convertToFixedButton_clicked()
{
    if (!currentCustomer) {
            QMessageBox::warning(this, "错误", "当前没有登录的用户。");
            return;
        }

        LoadingDialog *loadingDialog = new LoadingDialog(this);
        loadingDialog->show();

        QTimer::singleShot(1000, [this, loadingDialog] {
            ConvertToFixedDialog dialog(this, currentCustomer);

            if (dialog.exec() == QDialog::Accepted) {
                QMessageBox::information(this, "转换成功", "活期存款已成功转换为定期存款。");
            }

            loadingDialog->accept();
        });
}

void MainWindow::on_convertToCurrentButton_clicked()
{
    if (!currentCustomer) {
            QMessageBox::warning(this, "错误", "当前没有登录的用户。");
            return;
        }

    // 检查用户是否有定期存款
        QList<Transaction> fixedDeposits;
        for (const Transaction &t : currentCustomer->getTransactions()) {
            if (t.getTerm() != "活期" && t.getAmount() > 0) {
                fixedDeposits.append(t);
            }
        }

        if (fixedDeposits.isEmpty()) {
            QMessageBox::warning(this, "无定期存款", "您没有可用于转换的定期存款。");
            return;
        }

        LoadingDialog *loadingDialog = new LoadingDialog(this);
        loadingDialog->show();

        QTimer::singleShot(1000, [this, loadingDialog] {
            ConvertToCurrentDialog dialog(this, currentCustomer);

            if (dialog.exec() == QDialog::Accepted) {
                QMessageBox::information(this, "转换成功", "定期存款已成功转换为活期存款。");
            }

            loadingDialog->accept();
        });
}

void MainWindow::on_transferButton_clicked()
{
    if (!currentCustomer) {
            QMessageBox::warning(this, "错误", "当前没有登录的用户。");
            return;
        }

        LoadingDialog *loadingDialog = new LoadingDialog(this);
        loadingDialog->show();

        QTimer::singleShot(1000, [this, loadingDialog] {
            TransferDialog transferDialog(this);

            if (transferDialog.exec() == QDialog::Accepted) {
                double amount = transferDialog.getTransferAmount();
                QString receiverAccount = transferDialog.getReceiverID();

                if (amount <= 0) {
                    QMessageBox::warning(this, "转账错误", "请输入有效的转账金额！");
                    loadingDialog->accept();
                    return;
                }

                Customer* receiver = manager->findCustomerByAccountNumber(receiverAccount);
                if (!receiver) {
                    QMessageBox::warning(this, "转账错误", "接收方账户不存在！");
                    loadingDialog->accept(); // 关闭加载动画对话框
                    return;
                }

                QString employeeID = "system";  // 假设从系统获取
                if (currentCustomer->transfer(amount, *receiver, employeeID)) {
                    QMessageBox::information(this, "转账成功", "转账已成功处理。");
                } else {
                    QMessageBox::warning(this, "转账错误", "余额不足或其他错误！");
                }
            }

            loadingDialog->accept();
        });
}

void MainWindow::on_registerButton_clicked()
{
    RegisterDialog *registerDialog = new RegisterDialog(manager, this);
    registerDialog->show();
    this->hide();
}

void MainWindow::on_inquireButton_clicked()
{
    AdminPanel *adminPanel = new AdminPanel(manager, this);
    adminPanel->exec();
    this->hide();
}

void MainWindow::on_closeAccountButton_clicked()
{
    bool ok;
       QString accountNumber = QInputDialog::getText(this, tr("注销账户"),
                                                     tr("请输入要注销的账号:"),
                                                     QLineEdit::Normal, "", &ok);

       if (ok && !accountNumber.isEmpty()) {
           // 调用 CustomerManager 的方法查找用户
           Customer* customerToDelete = manager->findCustomerByAccountNumber(accountNumber);
           if (customerToDelete) {
               // 确认用户是否要注销账户
               int ret = QMessageBox::warning(this, tr("注销账户"),
                                              tr("您确定要注销账号 %1 吗？该操作无法撤销。").arg(accountNumber),
                                              QMessageBox::Yes | QMessageBox::No);
               if (ret == QMessageBox::Yes) {
                   // 删除用户并给出提示
                   if (manager->removeCustomer(accountNumber)) {
                       QMessageBox::information(this, tr("注销成功"), tr("账户 %1 已成功注销。").arg(accountNumber));
                   } else {
                       QMessageBox::warning(this, tr("注销失败"), tr("账户注销失败，请稍后再试。"));
                   }
               }
           } else {
               QMessageBox::warning(this, tr("账户不存在"), tr("账户号码 %1 不存在。").arg(accountNumber));
           }
       }
}
