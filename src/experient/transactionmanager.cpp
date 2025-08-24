#include "transactionmanager.h"

TransactionManager::TransactionManager(CustomerManager &custManager)
    :customerManager(custManager)
{

}

bool TransactionManager::performTransaction(const QString &accountNumber, const Transaction &transaction)
{
    Customer *customer= customerManager.findCustomerByAccountNumber(accountNumber);
    if(customer && !customer->isLost()){
        customer->addTransaction(transaction);
        return true;
    }
    return false;
}

