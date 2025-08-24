#include "transaction.h"

Transaction::Transaction(QDate d,double amt,QString type,QString empID, QString term, double rate, const QDate &maturityDate)
    :date(d),amount(amt),transactionType(type),employeeID(empID), term(term) ,interestRate(rate), maturityDate(maturityDate)
{

}

QDate Transaction::getDate() const
{
    return date;
}

double Transaction::getAmount() const
{
    return amount;
}

QString Transaction::getType() const
{
    return transactionType;
}

QString Transaction::getEmployeeID() const
{
    return employeeID;
}

QString Transaction::getTerm() const
{
    return term;
}

double Transaction::getInterestRate() const
{
    return interestRate;
}

QDate Transaction::getMaturityDate() const
{
    return maturityDate;
}

void Transaction::setMaturityDate(const QDate &date)
{
    maturityDate=date;
}

void Transaction::setAmount(double amt)
{
    amount = amt;
}

void Transaction::setType(const QString &type)
{
    transactionType = type;
}

void Transaction::setTerm(const QString &term)
{
    this->term = term;
}

void Transaction::setInterestRate(double interestRate)
{
    this->interestRate = interestRate;
}
