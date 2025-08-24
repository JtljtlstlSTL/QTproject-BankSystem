#include "filemanager.h"
#include "login.h"
#include "mainwindow.h"
#include<bankselectiondialog.h>

#include <QApplication>
#include <QPushButton>
#include <QLineEdit>
#include <QStyleFactory>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // 设置全局样式表
       QString styleSheet = R"(
           QPushButton {
               background-color: #4CAF50;
               color: white;
               border-radius: 5px;
               padding: 10px;
               border: none;
           }
           QPushButton:hover {
               background-color: #45a049;
           }
           QLineEdit {
               border: 2px solid #4CAF50;
               border-radius: 5px;
               padding: 5px;
           }
           QLineEdit:focus {
               border-color: #45a049;
           }
       )";
       a.setStyle(QStyleFactory::create("Fusion"));
       a.setStyleSheet(styleSheet);

       CustomerManager manager; // 创建 CustomerManager 对象


          FileManager fileManager;

          /*// 尝试从数据库文件加载数据
          QString dbFileName = "customers.db"; // 更新为数据库文件名
          bool loaded = fileManager.loadData(dbFileName, manager);
          if (!loaded) {
              qWarning() << "Failed to load customer data from file:" << dbFileName;
          } else {
              qDebug() << "Success to load customer data from file:" << dbFileName;
          }*/

             bool loaded = fileManager.loadData("customers.txt", manager);
             if (!loaded) {
                 qWarning("Failed to load customer data from file.");
             }
             else qDebug("Success to load customer data from file.");

        BankSelectionDialog b(&manager);
        b.show();
    return a.exec();
}
