##--------------------------------------------------------
##学习Qt项视图
##Create by tyw66 at 2018-10-08
##--------------------------------------------------------
QT       += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
TARGET = item
TEMPLATE = app

SOURCES += \
        main.cpp \
        widget.cpp \
	mydelegate.cpp

HEADERS += \
        widget.h \
	mydelegate.h

FORMS += \
        widget.ui
