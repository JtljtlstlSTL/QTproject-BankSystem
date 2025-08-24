QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    adminpanel.cpp \
    bankselectiondialog.cpp \
    converttocurrentdialog.cpp \
    converttofixeddialog.cpp \
    customer.cpp \
    customermanager.cpp \
    depositdialog.cpp \
    depositselectiondialog.cpp \
    editcustomerdialog.cpp \
    edituserdialog.cpp \
    filemanager.cpp \
    loadingdialog.cpp \
    login.cpp \
    main.cpp \
    mainwindow.cpp \
    querydialog.cpp \
    registerdialog.cpp \
    reportlostdialog.cpp \
    transaction.cpp \
    transactionmanager.cpp \
    transferdialog.cpp \
    withdrawdialog.cpp

HEADERS += \
    adminpanel.h \
    bankselectiondialog.h \
    converttocurrentdialog.h \
    converttofixeddialog.h \
    customer.h \
    customermanager.h \
    depositdialog.h \
    depositselectiondialog.h \
    editcustomerdialog.h \
    edituserdialog.h \
    filemanager.h \
    loadingdialog.h \
    login.h \
    mainwindow.h \
    querydialog.h \
    registerdialog.h \
    reportlostdialog.h \
    transaction.h \
    transactionmanager.h \
    transferdialog.h \
    withdrawdialog.h

FORMS += \
    adminpanel.ui \
    bankselectiondialog.ui \
    converttocurrentdialog.ui \
    converttofixeddialog.ui \
    depositdialog.ui \
    depositselectiondialog.ui \
    editcustomerdialog.ui \
    edituserdialog.ui \
    loadingdialog.ui \
    login.ui \
    mainwindow.ui \
    querydialog.ui \
    registerdialog.ui \
    reportlostdialog.ui \
    transferdialog.ui \
    withdrawdialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
