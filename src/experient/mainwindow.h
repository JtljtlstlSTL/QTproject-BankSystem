#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "customermanager.h"
#include"bankselectiondialog.h"

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(CustomerManager* manager,bool isOnline,QWidget *parent = nullptr);
    ~MainWindow();

    // 添加 setter 方法
        void setCurrentCustomer(Customer* customer);

private slots:
    void on_exitButton_clicked();

    void on_depositButton_clicked();

    void on_withdrawButton_clicked();

    void on_queryButton_clicked();

    void on_reportLostButton_clicked();

    void on_settingsButton_clicked();

    void on_convertToFixedButton_clicked();

    void on_convertToCurrentButton_clicked();

    void on_transferButton_clicked();

    void on_registerButton_clicked();

    void on_inquireButton_clicked();

    void on_closeAccountButton_clicked();

private:
    Ui::MainWindow *ui;
    CustomerManager* manager;
    Customer* currentCustomer;  // 当前登录的客户
    void updateUI();  // 更新界面显示
    bool isOnline;
};
#endif // MAINWINDOW_H
