TEMPLATE = lib
CONFIG += plugin
TARGET = gradual

DESTDIR = $${PWD}/../bin/plugin
INCLUDEPATH += ../mainwindow

HEADERS += \
    gradual.h

SOURCES += \
    gradual.cpp
