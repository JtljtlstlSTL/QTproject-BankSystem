#include "depositdialog.h"
#include "ui_depositdialog.h"

DepositDialog::DepositDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DepositDialog)
{
    ui->setupUi(this);

    //this->resize(1024, 768);

       setWindowTitle("存款");

       // 设置验证器以确保用户输入有效的数字
       QDoubleValidator *validator = new QDoubleValidator(0, 1000000, 2, this);
       ui->lineEditAmount->setValidator(validator);

       // 添加存款期限选项
       ui->comboBoxTerm->addItem("活期", 0.00);
       ui->comboBoxTerm->addItem("1年", 0.0198);  // 利率为1.98%
       ui->comboBoxTerm->addItem("3年", 0.0225); // 利率为2.25%
       ui->comboBoxTerm->addItem("5年", 0.035); // 利率为3.5%

       //connect(ui->buttonBox, &QDialogButtonBox::accepted, this, &QDialog::accept);
       //connect(ui->buttonBox, &QDialogButtonBox::rejected, this, &QDialog::reject);
}

DepositDialog::~DepositDialog()
{
    delete ui;
}

double DepositDialog::getDepositAmount() const
{
    return ui->lineEditAmount->text().toDouble();
}

QString DepositDialog::getDepositTerm() const
{
    return ui->comboBoxTerm->currentText();
}

QString DepositDialog::getAccountNumber() const
{
    return ui->lineEditAccount->text();
}
