QT       += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
DESTDIR=$${PWD}/../../build-skinLib

DEFINES += QT_DEPRECATED_WARNINGS
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH+=$${PWD}/../skinlib/

LIBS+= -L$${DESTDIR}\
            -lskinlib


HEADERS += \
    mainwindow.h

SOURCES += \
    main.cpp \
    mainwindow.cpp

FORMS += \
    mainwindow.ui


OTHER_FILES+=""

