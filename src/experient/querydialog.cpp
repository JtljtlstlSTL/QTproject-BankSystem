#include "querydialog.h"
#include "ui_querydialog.h"

QueryDialog::QueryDialog(Customer *customer,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QueryDialog)
  ,currentCustomer(customer)
{
    ui->setupUi(this);
        this->resize(1024, 768);

    setWindowTitle("查询");

        // 设置表格
        ui->transactionTableWidget->setColumnCount(6);
        QStringList headers;
        headers << "日期" << "金额" << "类型" << "员工ID" << "存款期限" << "利率";
        ui->transactionTableWidget->setHorizontalHeaderLabels(headers);
        ui->transactionTableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

        ui->transactionTableWidget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

        displayCustomerInfo();
}

QueryDialog::~QueryDialog()
{
    delete ui;
}

void QueryDialog::displayCustomerInfo()
{
    if (currentCustomer) {
            // 打印调试信息
            qDebug() << "Account Number:" << currentCustomer->getAccountNumber();
            qDebug() << "Name:" << currentCustomer->getName();
            qDebug() << "Balance:" << currentCustomer->getBalance();
            qDebug() << "Lost Status:" << (currentCustomer->isLost() ? "Lost" : "Normal");

            // 显示客户信息
            ui->accountNumberLabel->setText(currentCustomer->getAccountNumber());
            ui->nameLabel->setText(currentCustomer->getName());
            ui->balanceLabel->setText(QString::number(currentCustomer->getBalance(), 'f', 2));
            ui->lostStatusLabel->setText(currentCustomer->isLost() ? "已挂失" : "正常");
            double currentAccountTotal = currentCustomer->calculateCurrentAccountBalance();
            ui->currentAccountTotalLabel->setText(QString::number(currentAccountTotal, 'f', 2));

            ui->transactionTableWidget->setRowCount(0);

            // 显示交易明细
            for (const Transaction &transaction : currentCustomer->getTransactions()) {
                int row = ui->transactionTableWidget->rowCount();
                ui->transactionTableWidget->insertRow(row);

                ui->transactionTableWidget->setItem(row, 0, new QTableWidgetItem(transaction.getDate().toString("yyyy-MM-dd")));
                ui->transactionTableWidget->setItem(row, 1, new QTableWidgetItem(QString::number(transaction.getAmount(), 'f', 2)));
                ui->transactionTableWidget->setItem(row, 2, new QTableWidgetItem(transaction.getType()));
                ui->transactionTableWidget->setItem(row, 3, new QTableWidgetItem(transaction.getEmployeeID()));
                ui->transactionTableWidget->setItem(row, 4, new QTableWidgetItem(transaction.getTerm()));
                ui->transactionTableWidget->setItem(row, 5, new QTableWidgetItem(QString::number(transaction.getInterestRate(), 'f', 4)));

                qDebug() << "Transaction:" << transaction.getDate().toString("yyyy-MM-dd") << transaction.getAmount() << transaction.getType() << transaction.getEmployeeID() << transaction.getTerm() << transaction.getInterestRate();
            }

            // 调整字体和行高
            QFont font = ui->transactionTableWidget->font();
            font.setPointSize(10); // 可以调整字体大小
            ui->transactionTableWidget->setFont(font);
        }

    /*if (currentCustomer) {
            // 打印调试信息
            qDebug() << "Account Number:" << currentCustomer->getAccountNumber();
            qDebug() << "Name:" << currentCustomer->getName();
            qDebug() << "Balance:" << currentCustomer->getBalance();
            qDebug() << "Lost Status:" << (currentCustomer->isLost() ? "Lost" : "Normal");

            // 显示客户的详细信息
            ui->accountNumberLabel->setText(currentCustomer->getAccountNumber());
            ui->nameLabel->setText(currentCustomer->getName());
            ui->balanceLabel->setText(QString::number(currentCustomer->getBalance(), 'f', 2));
            ui->lostStatusLabel->setText(currentCustomer->isLost() ? "已挂失" : "正常");

            // 设置交易明细标题
            ui->transactionHeaderLabel->setText("日期 | 金额 | 类型 | 员工ID | 存款期限 | 利率");

            // 清空旧的交易记录
            ui->transactionListWidget->clear();

            // 显示交易明细
            QStringList transactionDetails;
            for (const Transaction &transaction : currentCustomer->getTransactions()) {
                QString transactionDetail = QString("%1 | %2 | %3 | %4 | %5 | %6")
                    .arg(transaction.getDate().toString("yyyy-MM-dd"))
                    .arg(transaction.getAmount(), 0, 'f', 2)
                    .arg(transaction.getType())
                    .arg(transaction.getEmployeeID())
                    .arg(transaction.getTerm())  // 存款期限
                    .arg(transaction.getInterestRate(), 0, 'f', 4);  // 利率

                transactionDetails << transactionDetail;

                // 打印调试信息
                qDebug() << "Transaction:" << transactionDetail;
            }
            ui->transactionListWidget->addItems(transactionDetails);

            // 调整字体和行高
                    QFont font = ui->transactionListWidget->font();
                    font.setPointSize(10); // 可以调整字体大小
                    ui->transactionListWidget->setFont(font);
        }*/
}
