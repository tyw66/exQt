QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = tr
TEMPLATE = app

CONFIG(warn_on | c++11)

SOURCES += \
        main.cpp \
        mainwindow.cpp

HEADERS += \
        mainwindow.h

FORMS += \
        mainwindow.ui

DESTDIR =$$PWD

TRANSLATIONS +=  \
	test_zh.ts \
