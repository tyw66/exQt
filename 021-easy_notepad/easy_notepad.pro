##--------------------------------------------------------
##简易文本编辑器
##--------------------------------------------------------
QT       += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = EasyNotepad
TEMPLATE = app

FORMS += \
    $$PWD/mainwindow.ui

HEADERS += \
    $$PWD/mainwindow.h

SOURCES += \
    $$PWD/main.cpp \
    $$PWD/mainwindow.cpp

RESOURCES += \
    $$PWD/src/easynotepad_src.qrc

message($$INCLUDEPATH)
message($$DEPENDPATH)
