#ifndef LOGIN_H
#define LOGIN_H

#include "customermanager.h"

#include <QWidget>
#include <QPixmap>
#include <QLabel>
#include <QMovie>

namespace Ui {
class Login;
}

class Login : public QWidget
{
    Q_OBJECT

public:
    explicit Login(CustomerManager* manager,bool isOnline,QWidget *parent = nullptr);
    ~Login();

    CustomerManager* manager;

private slots:
    void on_loginButton_clicked();

    void on_registerButton_clicked();

private:
    Ui::Login *ui;
    bool isOnline;             // 区分线上银行和线下银行
};

#endif // LOGIN_H
