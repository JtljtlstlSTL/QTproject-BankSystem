#ifndef CUSTOMERMANAGER_H
#define CUSTOMERMANAGER_H

#include "customer.h"

#include <QList>
#include <QString>
#include<QDebug>

class CustomerManager
{
public:
    CustomerManager();

    // 线上银行的登录验证方法
        bool onlineBankLogin(const QString& username, const QString& password);

    // 线下银行的登录验证方法
        bool offlineBankLogin(const QString& username, const QString& password);
    void addCustomer(const Customer &customer);
    Customer* findCustomerByAccountNumber(const QString &accountNumber);
    QList<Customer>getAllCustomers()const;
    bool removeCustomer(const QString& accountNumber);
    bool updateCustomerFile();

private:
    QList<Customer>customers;
};

#endif // CUSTOMERMANAGER_H
