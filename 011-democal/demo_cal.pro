############################################################################################
##题目：编写Qt界面程序，用户在界面输入参数，计算两种图形的面积和周长。
##要求：图形包括：矩形（输入长和宽）、圆形（输入半径）需要自行设计界面，使用ui文件或者手写界面均可。
############################################################################################

QT       += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
DEFINES += QT_DEPRECATED_WARNINGS
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

HEADERS += \
    mainwindow.h \
    objects.h \
    viewerwidget.h


SOURCES += \
    main.cpp \
    mainwindow.cpp \
    objects.cpp \
    viewerwidget.cpp

FORMS += \
    mainwindow.ui

