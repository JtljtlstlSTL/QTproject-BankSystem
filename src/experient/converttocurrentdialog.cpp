#include "converttocurrentdialog.h"
#include "ui_converttocurrentdialog.h"

#include<QMessageBox>

ConvertToCurrentDialog::ConvertToCurrentDialog(QWidget *parent,Customer *customer) :
    QDialog(parent),
    ui(new Ui::ConvertToCurrentDialog),
    customer(customer)
{
    ui->setupUi(this);

    setWindowTitle("定期转活期");

    //this->resize(1024, 768);

    populateDepositList();

    //connect(ui->convertButton, &QPushButton::clicked, this, &ConvertToCurrentDialog::on_convertButton_clicked);
}

ConvertToCurrentDialog::~ConvertToCurrentDialog()
{
    delete ui;
}

void ConvertToCurrentDialog::on_convertButton_clicked()
{
    int selectedRow = ui->depositListWidget->currentRow();
        qDebug() << "Selected Row:" << selectedRow;

        if (selectedRow < 0) {
            QMessageBox::warning(this, "未选择存款", "请选择一个定期存款进行转换。");
            return;
        }

        QList<Transaction> transactions = customer->getTransactions();
        qDebug() << "Number of transactions:" << transactions.size();

        if (transactions.isEmpty()) {
            QMessageBox::warning(this, "错误", "没有找到任何存款记录。");
            return;
        }

        Transaction* selectedDeposit = nullptr;

        // 获取当前选中的项
        QListWidgetItem *currentItem = ui->depositListWidget->currentItem();
        if (!currentItem) {
            QMessageBox::warning(this, "错误", "获取当前选中的项失败。");
            return;
        }

        // 获取当前选中项的文本
        QString selectedText = currentItem->text();
        qDebug() << "Selected Text:" << selectedText;

        bool found = false;
        for (auto &t : transactions) {
            if (t.getTerm() != "活期" && t.getAmount() > 0 && !t.getIsConverted()) {
                QString depositInfo = QString("定期存款 - 金额: %1 - 期限: %2 - 存款日期: %3 - 状态: %4")
                                       .arg(t.getAmount())
                                       .arg(t.getTerm())
                                       .arg(t.getDate().toString(Qt::ISODate))
                                       .arg(t.getIsConverted() ? "已转换" : "未转换");

                qDebug() << "Checking deposit info:" << depositInfo;

                if (selectedText == depositInfo) {
                    selectedDeposit = &t;
                    found = true;
                    break;
                }
            }
        }

        if (!found) {
            QMessageBox::warning(this, "转换失败", "无法找到选中的定期存款。");
            return;
        }

        if (selectedDeposit) {
            double amount = selectedDeposit->getAmount();
            qDebug() << "Amount of selected deposit:" << amount;

            if (amount <= 0) {
                QMessageBox::warning(this, "转换失败", "定期存款的金额为零，无法转换。");
                return;
            }

            selectedDeposit->setIsConverted(true);  // 标记为已转换
            qDebug()<< (selectedDeposit->getIsConverted()? "已转换" : "未转换");

            try {
                Transaction newTransaction(QDate::currentDate(), amount, "定期转活期", "system", "活期", 0.00);
                customer->addTransaction(newTransaction);

                // customer->setBalance(customer->getBalance() + amount);
            } catch (const std::exception &e) {
                QMessageBox::critical(this, "错误", QString("添加交易记录失败: %1").arg(e.what()));
                return;
            }

            QMessageBox::information(this, "转活期成功", "定期存款已成功转为活期存款。");
            qDebug() << "Conversion successful.";
            accept();
        }
}

void ConvertToCurrentDialog::on_pushButton_clicked()
{
    reject();
}

void ConvertToCurrentDialog::populateDepositList()
{
    ui->depositListWidget->clear();

        QList<Transaction> transactions = customer->getTransactions();
        bool hasFixedDeposits = false;

        for (const Transaction &t : transactions) {
            if (t.getTerm() != "活期" && t.getAmount() > 0) {
                QString status = t.getIsConverted() ? "已转换" : "未转换";
                QString depositInfo = QString("定期存款 - 金额: %1 - 期限: %2 - 存款日期: %3 - 状态: %4")
                                       .arg(t.getAmount())
                                       .arg(t.getTerm())
                                       .arg(t.getDate().toString(Qt::ISODate))
                                       .arg(status);
                ui->depositListWidget->addItem(depositInfo);
                hasFixedDeposits = true;
            }
        }
        if (!hasFixedDeposits) {
            QMessageBox::warning(this, "无定期存款", "您没有可用于转换的定期存款。");
            reject();
        }
}
