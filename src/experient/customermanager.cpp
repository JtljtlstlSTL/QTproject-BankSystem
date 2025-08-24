#include "customermanager.h"

CustomerManager::CustomerManager()
{

}

bool CustomerManager::onlineBankLogin(const QString &username, const QString &password)
{
    // 查找是否存在线下银行用户并匹配密码
        for (const Customer& customer : customers) {
            if (customer.getAccountNumber() == username && customer.getPassword() == password) {
                qDebug() << "线下银行用户登录成功: " << customer.getName();
                return true;
            }
        }
        qDebug() << "线下银行用户登录失败";
        return false;
}

bool CustomerManager::offlineBankLogin(const QString &username, const QString &password)
{
    // 查找是否存在线上银行用户并匹配密码
            if (username == "system" && password == "password") {
                qDebug() << "线上银行用户登录成功: " <<
                            "system";
                return true;
            }
            else {
                qDebug() << "线上银行用户登录失败";
                return false;
            }
}

void CustomerManager::addCustomer(const Customer &customer)
{
    customers.append(customer);
}

Customer *CustomerManager::findCustomerByAccountNumber(const QString &accountNumber)
{
    for (Customer &customer : customers) {
            if (customer.getAccountNumber() == accountNumber) {
                qDebug() << "找到客户: " << customer.getName() << " 账户号: " << accountNumber;
                return &customer;
            }
        }
        qDebug() << "未找到账户号为 " << accountNumber << " 的客户。";
        return nullptr;
}

QList<Customer> CustomerManager::getAllCustomers() const
{
    return customers;
}

bool CustomerManager::removeCustomer(const QString &accountNumber)
{
    for (int i = 0; i < customers.size(); ++i) {
           if (customers[i].getAccountNumber() == accountNumber) {
               customers.removeAt(i); // 从内存中删除用户

               // 更新文件，删除对应的账户记录
               if (updateCustomerFile()) {
                   return true;  // 删除成功
               } else {
                   return false; // 文件更新失败
               }
           }
       }
       return false;  // 没有找到用户
}

bool CustomerManager::updateCustomerFile() {
    QFile file("customers.txt");  // 假设用户数据保存在 customers.txt 文件中
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        return false; // 无法打开文件
    }

    QTextStream out(&file);

    // 将所有用户信息重新写入文件
    for (const Customer& customer : customers) {
        out << customer.getAccountNumber() << "," << customer.getName() << "," << customer.getBalance() << "\n";
    }

    file.close();
    return true;  // 文件更新成功
}
