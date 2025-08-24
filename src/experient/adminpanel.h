#ifndef ADMINPANEL_H
#define ADMINPANEL_H

#include "customermanager.h"
#include "mainwindow.h"

#include <QDialog>

namespace Ui {
class AdminPanel;
}

class AdminPanel : public QDialog
{
    Q_OBJECT

public:
    explicit AdminPanel(CustomerManager *manager,QWidget *parent = nullptr);
    ~AdminPanel();

private slots:
    void on_searchButton_clicked();

    void on_editButton_clicked();

    void on_backToLoginButton_clicked();

private:
    Ui::AdminPanel *ui;
    CustomerManager *manager;
    Customer* currentCustomer; // 用于保存当前选中的客户
};

#endif // ADMINPANEL_H
