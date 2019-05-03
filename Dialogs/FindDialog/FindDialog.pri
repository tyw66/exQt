QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
INCLUDEPATH+=.
TARGET = FindDialog
TEMPLATE = app


SOURCES +=$$PWD/dialog.cpp

HEADERS  +=$$PWD/dialog.h
