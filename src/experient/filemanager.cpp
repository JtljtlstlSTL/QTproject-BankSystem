#include "filemanager.h"

FileManager::FileManager()
{

}

bool FileManager::saveData(const QString &fileName, const CustomerManager &customerManager)
{
    QFile file(fileName);
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
            return false;

        QTextStream out(&file);

        for (const Customer &customer : customerManager.getAllCustomers()) {
            // 如果客户未挂失，则写入 "0000-00-00" 作为默认挂失日期
            QString reportLostDate = customer.isLost() ? customer.getReportLostDate().toString("yyyy-MM-dd") : "0000-00-00";

            out << customer.getAccountNumber() << "," << customer.getName() << ","
                << customer.getPassword() << "," << customer.getAddress() << ","
                << customer.getDepositType() << "," << customer.getInterestRate() << ","
                << customer.isLost() << "," << reportLostDate << ","
                << QString::number(customer.getBalance(), 'f', 2) << ","  // 格式化余额
                << customer.getTransactions().size() << "\n";

            for (const Transaction &transaction : customer.getTransactions()) {
                out << transaction.getDate().toString("yyyy-MM-dd") << ","
                    << transaction.getAmount() << "," << transaction.getType() << ","
                    << transaction.getEmployeeID() << "," << transaction.getTerm() << ","
                    << transaction.getInterestRate() << "," << transaction.getMaturityDate().toString("yyyy-MM-dd") << "\n";
            }
        }

        file.close();
        return true;
}

bool FileManager::loadData(const QString &fileName, CustomerManager &customerManager)
{
    QFile file(fileName);
       if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
           return false;

       QTextStream in(&file);
       bool hasError = false;

       while (!in.atEnd()) {
           QString line = in.readLine();
           QStringList fields = line.split(",");

           if (fields.size() >= 10) {  // 现在至少需要10个字段，不包括交易记录
               // 读取客户信息
               QString accountNumber = fields[0];
               QString name = fields[1];
               QString password = fields[2];
               QString address = fields[3];
               QString depositType = fields[4];
               double interestRate = fields[5].toDouble();

               bool isLost = fields[6].toInt();
               QDate reportLostDate = QDate::fromString(fields[7], "yyyy-MM-dd");
               if (!reportLostDate.isValid() && fields[7] != "0000-00-00") {
                   qDebug() << "Error: Invalid report lost date on line: " << line;
                   hasError = true;
                   continue;
               }

               // 读取余额字段并确保其有效性
               bool ok;
               double balance = fields[8].toDouble(&ok);
               if (!ok || balance < 0) {
                   qDebug() << "Error: Invalid balance on line: " << line;
                   hasError = true;
                   continue;
               }

               // 创建 Customer 对象
               Customer customer(accountNumber, name, password, address, depositType, interestRate, "");
               if (isLost) {
                   customer.reportLoss(reportLostDate);
               }
               customer.setBalance(balance);
               customerManager.addCustomer(customer);
               qDebug() << "customer number:"<< customerManager.getAllCustomers().size();

               // 读取交易记录数量
               int transactionCount = fields[9].toInt();
               if (transactionCount > 0) {
                   for (int i = 0; i < transactionCount; ++i) {
                       if (in.atEnd()) break;
                       line = in.readLine();
                       QStringList transactionFields = line.split(",");
                       if (transactionFields.size() == 7) {{
                           qDebug() << "Sccuess to reading transaction. ";
                           Transaction transaction(QDate::fromString(transactionFields[0], "yyyy-MM-dd"),
                                                   transactionFields[1].toDouble(),
                                                   transactionFields[2],
                                                   transactionFields[3],  // employeeID
                                                   transactionFields[4],  // term
                                                   transactionFields[5].toDouble(), // interestRate
                                                   QDate::fromString(transactionFields[6], "yyyy-MM-dd")); // maturityDate
                           customer.addTransaction(transaction);
                       }qDebug() << "transaction number:"<<customer.getTransactions().size(); }else {
                           qDebug() << "Error: Insufficient fields for transaction on line: " << line;
                           hasError = true;
                           break;
                       }
                   }
               }
           } else {
               qDebug() << "Error: Insufficient fields for customer data on line: " << line;
               hasError = true;
           }
       }

       file.close();
       return !hasError;
}


/*bool FileManager::saveData(const QString &fileName,const CustomerManager &customerManager)
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName(fileName); // 使用传入的 fileName
        if (!db.open()) {
            qWarning() << "Failed to open the database:" << db.lastError();
            return false;
        }

    QSqlQuery query;

       // 创建表
       query.exec("CREATE TABLE IF NOT EXISTS customers ("
                   "accountNumber TEXT PRIMARY KEY, "
                   "name TEXT, "
                   "password TEXT, "
                   "address TEXT, "
                   "depositType TEXT, "
                   "interestRate REAL, "
                   "isLost INTEGER, "
                   "reportLostDate TEXT, "
                   "balance REAL, "
                   "transactionCount INTEGER)");

       query.exec("CREATE TABLE IF NOT EXISTS transactions ("
                   "accountNumber TEXT, "
                   "date TEXT, "
                   "amount REAL, "
                   "type TEXT, "
                   "employeeID TEXT, "
                   "term TEXT, "
                   "interestRate REAL, "
                   "maturityDate TEXT, "
                   "FOREIGN KEY(accountNumber) REFERENCES customers(accountNumber))");

       query.prepare("INSERT INTO customers VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?)");
       foreach (const Customer &customer, customerManager.getAllCustomers()) {
           query.addBindValue(customer.getAccountNumber());
           query.addBindValue(customer.getName());
           query.addBindValue(customer.getPassword());
           query.addBindValue(customer.getAddress());
           query.addBindValue(customer.getDepositType());
           query.addBindValue(customer.getInterestRate());
           query.addBindValue(customer.isLost());
           query.addBindValue(customer.getReportLostDate().toString("yyyy-MM-dd"));
           query.addBindValue(customer.getBalance());
           query.addBindValue(customer.getTransactions().size());

           if (!query.exec()) {
               qWarning() << "Failed to insert customer data:" << query.lastError();
               return false;
           }

           foreach (const Transaction &transaction, customer.getTransactions()) {
               query.prepare("INSERT INTO transactions VALUES (?, ?, ?, ?, ?, ?, ?, ?)");
               query.addBindValue(customer.getAccountNumber());
               query.addBindValue(transaction.getDate().toString("yyyy-MM-dd"));
               query.addBindValue(transaction.getAmount());
               query.addBindValue(transaction.getType());
               query.addBindValue(transaction.getEmployeeID());
               query.addBindValue(transaction.getTerm());
               query.addBindValue(transaction.getInterestRate());
               query.addBindValue(transaction.getMaturityDate().toString("yyyy-MM-dd"));

               if (!query.exec()) {
                   qWarning() << "Failed to insert transaction data:" << query.lastError();
                   return false;
               }
           }
       }

       return true;
}

bool FileManager::loadData(const QString &fileName, CustomerManager &customerManager)
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName(fileName); // 使用传入的 fileName
        if (!db.open()) {
            qWarning() << "Failed to open the database:" << db.lastError();
            return false;
        }

    QSqlQuery query;

       if (!query.exec("SELECT * FROM customers")) {
           qWarning() << "Failed to execute query:" << query.lastError();
           return false;
       }

       while (query.next()) {
           Customer customer(query.value("accountNumber").toString(),
                             query.value("name").toString(),
                             query.value("password").toString(),
                             query.value("address").toString(),
                             query.value("depositType").toString(),
                             query.value("interestRate").toDouble(),
                             "");

           if (query.value("isLost").toBool()) {
               QDate reportLostDate = QDate::fromString(query.value("reportLostDate").toString(), "yyyy-MM-dd");
               customer.reportLoss(reportLostDate);
           }
           customer.setBalance(query.value("balance").toDouble());
           customerManager.addCustomer(customer);

           if (!query.exec("SELECT * FROM transactions WHERE accountNumber = '" + query.value("accountNumber").toString() + "'")) {
               qWarning() << "Failed to execute query:" << query.lastError();
               return false;
           }

           while (query.next()) {
               Transaction transaction(QDate::fromString(query.value("date").toString(), "yyyy-MM-dd"),
                                       query.value("amount").toDouble(),
                                       query.value("type").toString(),
                                       query.value("employeeID").toString(),
                                       query.value("term").toString(),
                                       query.value("interestRate").toDouble(),
                                       QDate::fromString(query.value("maturityDate").toString(), "yyyy-MM-dd"));
               customer.addTransaction(transaction);
           }
       }

       return true;
}*/
