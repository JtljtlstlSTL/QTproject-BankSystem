#include "reportlostdialog.h"
#include "ui_reportlostdialog.h"

ReportLostDialog::ReportLostDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ReportLostDialog)
{
    ui->setupUi(this);
    setWindowTitle("挂失");
}

ReportLostDialog::~ReportLostDialog()
{
    delete ui;
}

void ReportLostDialog::on_confirmButton_clicked()
{
    accept();
}

void ReportLostDialog::on_cancelButton_clicked()
{
    reject();
}
