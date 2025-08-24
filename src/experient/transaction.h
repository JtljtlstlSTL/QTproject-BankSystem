#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <QDate>
#include <QString>



class Transaction
{
public:
    Transaction(QDate d,double amt,QString type,QString empID,QString term,double rate, const QDate &maturityDate = QDate());

    QDate getDate()const;
    double getAmount()const;
    QString getType()const;
    QString getEmployeeID()const;
    QString getTerm() const;   // 存款期限（活期、1年、3年等）
    double getInterestRate() const;  // 每笔存款的利率
    QDate getMaturityDate() const;  // 获取到期日期

    void setMaturityDate(const QDate &date);  // 设置到期日期
    void setAmount(double amt);
    void setType(const QString &type);
    void setTerm(const QString &term);
    void setInterestRate(double interestRate);

    bool operator==(const Transaction& other) const {
            return (date == other.date &&
                    amount == other.amount &&
                    transactionType == other.transactionType &&
                    term == other.term &&
                    interestRate == other.interestRate &&
                    maturityDate == other.maturityDate);};

    bool getIsConverted() const { return isConverted; }
    void setIsConverted(bool converted) { isConverted = converted; }

private:
    QDate date;
    double amount;
    QString transactionType;
    QString employeeID;
    QString term;
    double interestRate;
    QDate maturityDate;  // 到期日期

    bool isConverted = false;
};

#endif // TRANSACTION_H
