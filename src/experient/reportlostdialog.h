#ifndef REPORTLOSTDIALOG_H
#define REPORTLOSTDIALOG_H

#include <QDialog>

namespace Ui {
class ReportLostDialog;
}

class ReportLostDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ReportLostDialog(QWidget *parent = nullptr);
    ~ReportLostDialog();

private slots:
    void on_confirmButton_clicked();

    void on_cancelButton_clicked();

private:
    Ui::ReportLostDialog *ui;
};

#endif // REPORTLOSTDIALOG_H
