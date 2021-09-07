##-------------------------------------------------------------------------------
##数据(状态)同步的解决方案
##-------------------------------------------------------------------------------
##系统状态改变的情形提炼成一个个信号，放在独立的一个公用模块中，
##各个模块实现自己的槽函数，并去连接这些信号。
##运行过程中，各个模块通过这个公用模块去发送相应信号。
##-------------------------------------------------------------------------------
QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11


DEFINES += QT_DEPRECATED_WARNINGS
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    signalhub.cpp

HEADERS += \
    mainwindow.h \
    signalhub.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
