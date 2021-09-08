##-------------------------------------------------------------------------------
##数据(状态)同步的解决方案
##Create by tyw66 at 2021-9-7
##-------------------------------------------------------------------------------
##问题：
##当某个组件使得整个系统的某个状态变化后，其余各个组件如何及时做出相应的变化响应。
##-------------------------------------------------------------------------------
##解决方案：
##系统状态改变的情形提炼成一个个信号，放在独立的一个公用模块中，
##运行过程中，各个模块通调用这个公用模块去发送相应信号。
##各个模块对象实现自己的槽函数，并去连接这些信号，做出相应的响应。
##注意[重要]：为了避免在对象的槽函数中改变状态导致又触发信号，这时需要把阻断对象的信号发送
##在槽函数开始时使用函数blockSignals(true)阻断.在槽函数响应结束时再恢复。
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
