#include "adminpanel.h"
#include "login.h"
#include "mainwindow.h"
#include "registerdialog.h"
#include "ui_login.h"

#include<memory>
#include <QDebug>

Login::Login(CustomerManager* manager,bool isOnline,QWidget *parent) :
    QWidget(parent),
    manager(manager),
    ui(new Ui::Login),
    isOnline(isOnline)
{
    ui->setupUi(this);

    setWindowTitle("登陆");

    // 设置窗口大小
        this->resize(824, 368);

    //QLabel* imageLabel = new QLabel(this); // 创建一个 QLabel
    QPixmap pixmap("C:/Users/LEGION/Desktop/pictrue01.png");
    ui->mylabel->setPixmap(pixmap);
    ui->mylabel->setScaledContents(true); // 自动缩放内容以适应 QLabel
    ui->mylabel->setFixedSize(275, 275); // 设置 QLabel 的固定大小

    QPixmap pixmapa("C:/Users/LEGION/Desktop/logo");
    ui->logo->setPixmap(pixmapa);
    ui->logo->setScaledContents(true);
    //ui->logo->setFixedSize(300, 90);

    //QMovie *movie = new QMovie("C:/Users/LEGION/Desktop/pictrue02.gif"); // 这里是GIF的路径
    //movie->setScaledSize(QSize(100, 100));  // 设置 GIF 尺寸为 200x200
    //ui->mylabel->setMovie(movie);
    //movie->start();  // 启动GIF动画

    // 设置密码输入框显示为点
     ui->passwordEdit->setEchoMode(QLineEdit::Password);

    //connect(ui->loginButton, &QPushButton::clicked, this, &Login::on_loginButton_clicked);
    //connect(ui->registerButton, &QPushButton::clicked, this, &Login::on_registerButton_clicked);

    // 设置控件的大小策略
        ui->mylabel->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        ui->logo->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        ui->accountEdit->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        ui->passwordEdit->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        ui->loginButton->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        ui->registerButton->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        ui->statusLabel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
}

Login::~Login()
{
    delete ui;
}

void Login::on_loginButton_clicked()
{
    QString account = ui->accountEdit->text();
    QString password = ui->passwordEdit->text();

       if (isOnline) {
           // 处理线上银行登录
           if (manager->onlineBankLogin(account, password)) {
               qDebug() << "Online bank login successful, opening MainWindow.";
               Customer* customer = manager->findCustomerByAccountNumber(account);
                  if (customer && customer->getPassword() == password) {
                   MainWindow *mainWindow = new MainWindow(manager,isOnline, this);
                   mainWindow->setCurrentCustomer(customer);
                   mainWindow->show();
                   this->hide();
               } else {
                   ui->statusLabel->setText("Login failed. Check your credentials.");
                   ui->passwordEdit->clear();
               }
           } else {
               ui->statusLabel->setText("Login failed. Check your credentials.");
               ui->passwordEdit->clear();
           }
       } else {
           // 处理线下银行登录
           if (manager->offlineBankLogin(account, password)) {
               qDebug() << "Offline bank login successful, opening MainWindow.";
               MainWindow *mainWindow = new MainWindow(manager,isOnline, this);
               mainWindow->show();
               this->hide();
           } else {
               ui->statusLabel->setText("Login failed. Check your credentials.");
               ui->passwordEdit->clear();
           }
       }

    /*QString account = ui->accountEdit->text();
    QString password = ui->passwordEdit->text();

    if( account=="manager" && password == "pass"){
        qDebug() << "Admin login successful, opening AdminPanel.";
               AdminPanel *adminPanel = new AdminPanel(manager, this);
               adminPanel->exec(); // 显示管理员面板对话框
               this->hide();
               return;
    }
    else {
               ui->statusLabel->setText("Login failed. Check your credentials.");
           }

    Customer* customer = manager->findCustomerByAccountNumber(account);
       if (customer && customer->getPassword() == password) {
          //ui->statusLabel->setText("Login successful!");
          qDebug() << "Login successful, opening MainWindow.";
          MainWindow *mainWindow = new MainWindow(manager, this); // 传递 manager 指针
          mainWindow->setCurrentCustomer(customer);  // 设置当前客户
          mainWindow->show();
          this->hide();
       } else {
           ui->statusLabel->setText("Login failed. Check your credentials.");
           ui->passwordEdit->clear();
       }*/
}

void Login::on_registerButton_clicked()
{
    /*ui->statusLabel->setText("Register button clicked.");
    RegisterDialog *registerDialog = new RegisterDialog(manager, this);
    registerDialog->exec();*/

    BankSelectionDialog *bankSelectionDialog = new BankSelectionDialog(manager); // 创建银行选择对话框
        bankSelectionDialog->show(); // 显示银行选择对话框
        this->hide(); // 隐藏当前登录对话框
}
