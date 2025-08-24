#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "transaction.h"

#include <QDate>
#include <QString>

class Customer
{
public:
    Customer(QString acc,QString n,QString pwd,QString addr,QString depType,double rate,QString empID);

    QString getAccountNumber()const;
    void setAccountNumber(QString& acc);
    QString getName()const;
    void setName(const QString &name);
    QString getPassword()const;
    void setPassword(const QString &pwd);
    QString getAddress()const;
    void setAddress(const QString &addr);
    QString getDepositType()const;
    double getInterestRate()const;
    bool isLost()const;
    void setLost(bool lost);
    void reportLoss(QDate date);
    QDate getReportLostDate()const;

    void addTransaction(const Transaction &transaction);
    QList<Transaction> getTransactions()const;

    double calculateInterest() const;
    double getBalance()const;
    void setBalance(double balance);

    // 增加两个新的方法用于存款和取款操作
        void deposit(double amount, QString term, QString employeeID);
        bool withdraw(double amount, QString employeeID);
        bool transfer(double amount, Customer &receiver, QString employeeID);

    double calculateCurrentAccountBalance() const;
        void updateDeposits();  // 更新到期的定期存款利息

private:
    QString accountNumber;
    QString name;
    QString password;
    QString address;
    QString depositType;
    double interestRate;
    bool isReportedLost;
    QDate reportLostDate;
    QString employeeID;
    QList<Transaction>transactions;
    double balance;
};

#endif // CUSTOMER_H
