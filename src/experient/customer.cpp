#include "customer.h"
#include "depositselectiondialog.h"

#include <QUuid>
#include<QDebug>
#include <QMessageBox>

const double CURRENT_ACCOUNT_RATE = 0.00;  // 活期利率

Customer::Customer(QString acc,QString n,QString pwd,QString addr,QString depType="xxx",double rate=0.0,QString empID="user")
    :accountNumber(acc),name(n),password(pwd),address(addr),depositType(depType),interestRate(rate),isReportedLost(false),employeeID(empID)
{
    updateDeposits();
}

QString Customer::getAccountNumber() const
{
    return accountNumber;
}

void Customer::setAccountNumber(QString( &acc))
{
  accountNumber = acc;
}

QString Customer::getName() const
{
    return name;
}

void Customer::setName(const QString &n)
{
    name=n;
}

QString Customer::getPassword() const
{
    return password;
}

void Customer::setPassword(const QString &pwd)
{
    password=pwd;
}

QString Customer::getAddress() const
{
    return address;
}

void Customer::setAddress(const QString &addr)
{
    address=addr;
}

QString Customer::getDepositType() const
{
    return depositType;
}

double Customer::getInterestRate() const
{
    return interestRate;
}

bool Customer::isLost() const
{
    return isReportedLost;
}

void Customer::setLost(bool lost)
{
    isReportedLost = lost;
}

void Customer::reportLoss(QDate date)
{
    isReportedLost=true;
    reportLostDate=date;
}

QDate Customer::getReportLostDate() const
{
    return reportLostDate;
}

void Customer::addTransaction(const Transaction &transaction)
{
    transactions.append(transaction);
}

QList<Transaction> Customer::getTransactions() const
{
    return transactions;
}

double Customer::calculateInterest() const
{
    double totalInterest = 0.0;

        for (const Transaction &t : transactions) {
            if (t.getType() == "存款") {
                double principal = t.getAmount();
                double rate = t.getInterestRate();
                QString term = t.getTerm();
                double interest = 0.0;

                if (term == "活期") {
                    /*//每半年计算一次利息
                    double halfYearRate = CURRENT_ACCOUNT_RATE / 2;
                    QDate depositDate = t.getDate();
                    QDate currentDate = QDate::currentDate();

                    int yearsDiff = currentDate.year() - depositDate.year();
                    int monthsDiff = currentDate.month() - depositDate.month();
                    int totalMonths = yearsDiff * 12 + monthsDiff;
                    int halfYears = totalMonths / 6;
                    interest = principal * halfYearRate * halfYears;*/
                    interest=0;
                } else if (term == "1年") {
                    interest = principal * rate;
                } else if (term == "3年") {
                    interest = principal * rate * 3;
                } else if (term == "5年") {
                    interest = principal * rate * 5;
                }

                totalInterest += interest;
            }
        }

        return totalInterest;
}

double Customer::getBalance() const
{
    const_cast<Customer*>(this)->updateDeposits();  //更新
    return balance;
}

void Customer::setBalance(double balance)
{
    this->balance=balance;
}

void Customer::deposit(double amount, QString term, QString employeeID)
{
    updateDeposits();
    double rate = 0.0;
        QDate maturityDate;

        if (term == "活期") {
            rate = 0.00;
            maturityDate = QDate();
        } else if (term == "1年") {
            rate = 0.0198;
            maturityDate = QDate::currentDate().addYears(1);
        } else if (term == "3年") {
            rate = 0.0225;
            maturityDate = QDate::currentDate().addYears(3);
        } else if (term == "5年") {
            rate = 0.035;
            maturityDate = QDate::currentDate().addYears(5);
        }

        Transaction transaction(QDate::currentDate(), amount, "存款", employeeID, term, rate, maturityDate);
        addTransaction(transaction);

        balance += amount;
}

bool Customer::withdraw(double amount, QString employeeID)
{
    updateDeposits();
        double remainingAmount = amount;
        double initialBalance = getBalance();  // 获取取款前的总余额
        qDebug() << "Initial Balance:" << initialBalance;

        // 先从活期存款中取款
        double currentAccountBalance = calculateCurrentAccountBalance();
        qDebug() << "Current Account Balance:" << currentAccountBalance;

        if (currentAccountBalance >= remainingAmount) {
            Transaction withdrawal(QDate::currentDate(), -remainingAmount, "取款", employeeID, "活期", CURRENT_ACCOUNT_RATE);
            addTransaction(withdrawal);  // 记录取款交易
            setBalance(initialBalance - remainingAmount);  // 更新余额
            qDebug() << "Withdrawal successful. Amount:" << remainingAmount;
            return true;
        } else {
            // 活期存款不足时，弹出确认对话框
            QMessageBox::StandardButton reply;
            reply = QMessageBox::question(nullptr, "取款提示",
                                          "活期存款不足，是否要从定期存款中取出？",
                                          QMessageBox::Yes | QMessageBox::No);
            if (reply == QMessageBox::No) {
                qDebug() << "Withdrawal cancelled by user.";
                return false;  // 用户选择取消取款
            }

            // 弹出选择窗口，选择定期存款
            QList<Transaction> fixedDeposits;
            for (const Transaction &t : transactions) {
                if (t.getType() == "存款" && t.getTerm() != "活期" && t.getAmount() > 0) {
                    fixedDeposits.append(t);
                }
            }

            qDebug() << "Fixed Deposits Count:" << fixedDeposits.size();
            if (remainingAmount > 0 && !fixedDeposits.isEmpty()) {
                DepositSelectionDialog dialog(fixedDeposits);  // 弹出选择窗口
                if (dialog.exec() == QDialog::Accepted) {
                    Transaction selectedDeposit = dialog.getSelectedDeposit();  // 获取用户选择的定期存款
                    qDebug() << "Selected Deposit:" << selectedDeposit.getAmount() << selectedDeposit.getTerm() << selectedDeposit.getInterestRate();

                    // 从定期存款中扣除相应金额
                    Transaction withdrawal(QDate::currentDate(), -remainingAmount, "取款", employeeID, selectedDeposit.getTerm(), selectedDeposit.getInterestRate());
                    addTransaction(withdrawal);  // 记录取款交易

                    bool updated = false;
                    // 更新所选定期存款记录为活期
                    for (Transaction &t : transactions) {
                        if (t.getDate() == selectedDeposit.getDate() &&
                            t.getAmount() == selectedDeposit.getAmount() &&
                            t.getTerm() == selectedDeposit.getTerm() &&
                            t.getInterestRate() == selectedDeposit.getInterestRate()) {

                            // 只更新用户选择的定期存款
                            t.setAmount(t.getAmount() - remainingAmount);
                            t.setTerm("活期");
                            t.setInterestRate(CURRENT_ACCOUNT_RATE);

                            qDebug() << "Updated Selected Deposit to Current Account. New Amount:" << t.getAmount() << "Term:" << t.getTerm();
                            updated = true;
                            break;  // 只更新所选定期存款
                        }
                    }

                    if (updated) {
                        // 更新余额
                        setBalance(initialBalance - amount);  // 更新余额
                        qDebug() << "Withdrawal completed. Amount:" << amount;
                        return true;
                    } else {
                        qDebug() << "Failed to update selected deposit.";
                    }
                } else {
                    qDebug() << "Deposit selection dialog was not accepted.";
                }
            }

            qDebug() << "Withdrawal failed. Remaining Amount:" << remainingAmount;
            return false;
        }

}

bool Customer::transfer(double amount, Customer &receiver, QString employeeID)
{
    updateDeposits();
    if (amount <= 0) {
            qDebug() << "Transfer amount must be positive.";
            return false;
        }

        // 检查余额是否足够
        if (balance < amount) {
            qDebug() << "Insufficient balance for transfer.";
            return false;
        }

        // 先从活期存款中扣款
        double currentAccountBalance = calculateCurrentAccountBalance();
        if (currentAccountBalance < amount) {
            qDebug() << "Insufficient current account balance for transfer.";
            return false;
        }

        // 扣除转出方的金额
        Transaction transferOut(QDate::currentDate(), -amount, "转出", employeeID, "活期", CURRENT_ACCOUNT_RATE);
        addTransaction(transferOut);  // 记录转出交易
        setBalance(balance - amount);  // 更新余额

        // 增加接收方的金额，并将其作为“活期”存款
        Transaction transferIn(QDate::currentDate(), amount, "转入", employeeID, "活期", CURRENT_ACCOUNT_RATE);
        receiver.addTransaction(transferIn);
        receiver.setBalance(receiver.getBalance() + amount);

        qDebug() << "Transfer successful! Transferred" << amount << "from" << getName() << "to" << receiver.getName();
        return true;
}

double Customer::calculateCurrentAccountBalance() const
{
    double balance = 0.0;
        for (const Transaction &t : transactions) {
            /*if (t.getType() == "存款" && t.getTerm() == "活期") {
                balance += t.getAmount();
            } else if (t.getType() == "取款") {
                balance += t.getAmount();
            }else if (t.getType()=="定期转活期"&& t.getTerm() == "活期") {
                balance += t.getAmount();
            }else if (t.getType()=="活期转定期") {
                balance -= t.getAmount();
            }*/
            if(t.getTerm()=="活期")balance += t.getAmount();
            if(t.getType()=="活期转定期")balance-=t.getAmount();
        }
        return balance;
}

void Customer::updateDeposits()
{
    /*QDate currentDate = QDate::currentDate();

        for (Transaction &t : transactions) {
            // 检查定期存款是否到期
            if (t.getType() == "存款" && t.getTerm() != "活期") {
                if (t.getMaturityDate().isValid() && t.getMaturityDate() <= currentDate) {
                    // 定期存款到期，计算利息
                    double principal = t.getAmount();
                    double rate = t.getInterestRate();
                    double interest = principal * rate;

                    // 更新本金加利息存入活期账户
                    double newAmount = principal + interest;
                    //t.setAmount(newAmount);
                    t.setTerm("活期");
                    t.setInterestRate(CURRENT_ACCOUNT_RATE);

                    // 输出调试信息
                    qDebug() << "Deposit matured. Principal:" << principal << "Interest:" << interest
                             << "New amount with interest:" << newAmount << "Converted to current account.";

                    // 记录此变化为新的存款交易
                    Transaction maturedTransaction(QDate::currentDate(), interest, "存款利息", employeeID, "活期", CURRENT_ACCOUNT_RATE);
                    addTransaction(maturedTransaction);
                }
            }
        }

        //setBalance(calculateCurrentAccountBalance());*/

        QDate currentDate = QDate::currentDate();
            double totalInterest = 0.0;  // 计算总利息

            for (Transaction &t : transactions) {
                // 检查定期存款是否到期
                if (t.getType() == "存款" && t.getTerm() != "活期") {
                    if (t.getMaturityDate().isValid() && t.getMaturityDate() <= currentDate) {
                        // 定期存款到期，计算利息
                        double principal = t.getAmount();
                        double rate = t.getInterestRate();
                        QString term = t.getTerm();
                        //double interest = principal * rate;

                        double interest=0;
                        if (term == "1年") {
                               interest = principal * rate;
                        } else if (term == "3年") {
                               interest = principal * rate * 3;
                        } else if (term == "5年") {
                               interest = principal * rate * 5;
                        }

                        // 计算新的活期存款金额
                        double newAmount = principal + interest;

                        totalInterest += interest;

                        // 更新定期存款为活期存款
                        //t.setAmount(newAmount);
                        t.setTerm("活期");
                        t.setInterestRate(CURRENT_ACCOUNT_RATE);

                        qDebug() << "Deposit matured. Principal:" << principal << "Interest:" << interest
                                 << "New amount with interest:" << newAmount << "Converted to current account.";
                    }
                }
            }

            // 利息添加到余额中
            if (totalInterest > 0.0) {
                Transaction interestTransaction(QDate::currentDate(), totalInterest, "存款利息", employeeID, "活期", CURRENT_ACCOUNT_RATE);
                addTransaction(interestTransaction);

                setBalance(getBalance() + totalInterest);
                qDebug() << "Interest added to balance. Total interest:" << totalInterest;
            }
}
