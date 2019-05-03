
QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DragDrop
TEMPLATE = app

#include(../Dialogs/FindDialog/FindDialog.pri)
#include(../Dialogs/GotoDialog/GotoDialog.pri)
#include(../Dialogs/SortDialog/SortDialog.pri)

#INCLUDEPATH+=../Dialogs/FindDialog  \
#    ../Dialogs/GotoDialog  \
#    ../Dialogs/SortDialog


SOURCES += main.cpp\
    listcontainer.cpp \
    dropbutton.cpp


HEADERS  +=  \
    listcontainer.h \
    dropbutton.h

SOURCES +=    window.cpp

HEADERS  +=     window.h

FORMS    += \
    window.ui
