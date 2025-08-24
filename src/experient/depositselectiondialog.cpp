#include "depositselectiondialog.h"
#include "ui_depositselectiondialog.h"

#include <QPushButton>
#include <QVBoxLayout>

DepositSelectionDialog::DepositSelectionDialog(const QList<Transaction>& deposits, QWidget *parent)
    : QDialog(parent), ui(new Ui::DepositSelectionDialog), depositList(deposits)
{
    ui->setupUi(this);

    this->resize(1024, 768);

    listWidget = new QListWidget(this);

        // 将定期存款信息添加到列表中
        for (const Transaction& deposit : depositList) {
            listWidget->addItem(deposit.getDate().toString("yyyy-MM-dd") + " | " +
                                QString::number(deposit.getAmount()) + " | " + deposit.getTerm());
        }

        QPushButton *okButton = new QPushButton("确定", this);
        QVBoxLayout *layout = new QVBoxLayout(this);
        layout->addWidget(listWidget);
        layout->addWidget(okButton);

        connect(okButton, &QPushButton::clicked, this, &DepositSelectionDialog::accept);
}

Transaction DepositSelectionDialog::getSelectedDeposit() const
{
    int currentRow = listWidget->currentRow();
        return depositList[currentRow];
}

DepositSelectionDialog::~DepositSelectionDialog()
{
    delete ui;
}
