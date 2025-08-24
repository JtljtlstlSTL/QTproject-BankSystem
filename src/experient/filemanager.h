#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include "customermanager.h"

#include <QTextStream>
//#include <QtSql/QSqlDatabase>
//#include <QtSql/QSqlQuery>
//#include<QtSql/QSqlError>
#include <QDebug>

class FileManager
{
public:
    FileManager();
    bool saveData(const QString &fileName,const CustomerManager &customerManager);
    bool loadData(const QString &fileName,CustomerManager &customerManager);

private:
    //QSqlDatabase db;
};

#endif // FILEMANAGER_H
