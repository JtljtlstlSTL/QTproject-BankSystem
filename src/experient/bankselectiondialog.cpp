#include "bankselectiondialog.h"
#include "login.h"
#include "ui_bankselectiondialog.h"

BankSelectionDialog::BankSelectionDialog(CustomerManager* manager,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BankSelectionDialog),
    manager(manager)
{
    ui->setupUi(this);

    this->resize(824, 368);

    QPixmap pixmap("C:/Users/LEGION/Desktop/logo_3");
    ui->label->setPixmap(pixmap);
    ui->label->setScaledContents(true);
    ui->label->setFixedSize(824, 375);

   // connect(ui->OfflineButton, &QPushButton::clicked, this, &BankSelectionDialog::on_OfflineButton_clicked);
   // connect(ui->OnlineButton, &QPushButton::clicked, this, &BankSelectionDialog::on_OnlineButton_clicked);
}

BankSelectionDialog::~BankSelectionDialog()
{
    delete ui;
}

void BankSelectionDialog::on_OfflineButton_clicked()
{
        bool isOnline = false; // 线下银行
        Login *login = new Login(manager, isOnline, nullptr);
        login->show();
        qDebug() << "Creating Login window";
        this->hide();
}

void BankSelectionDialog::on_OnlineButton_clicked()
{
        bool isOnline = true; // 线上银行
        Login *login = new Login(manager, isOnline, nullptr);
        login->show();
        qDebug() << "Creating Login window";
        this->hide();
}
