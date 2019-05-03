#-------------------------------------------------
#
# Project created by QtCreator 2017-08-21T21:09:11
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = test_of_qDellete
TEMPLATE = app
QMAKE_CXXFLAGS+=-std=c++11

SOURCES += main.cpp\
        dialog.cpp

HEADERS  += dialog.h

FORMS    += dialog.ui
