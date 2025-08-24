#ifndef TRANSACTIONMANAGER_H
#define TRANSACTIONMANAGER_H

#include "customermanager.h"



class TransactionManager
{
public:
    TransactionManager(CustomerManager &custManager);
    bool performTransaction(const QString &accountNumber,const Transaction &transaction);

private:
    CustomerManager &customerManager;
};

#endif // TRANSACTIONMANAGER_H

