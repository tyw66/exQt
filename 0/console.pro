

QT -= gui
CONFIG += c++11 console
CONFIG -= app_bundle


DEFINES += QT_DEPRECATED_WARNINGS
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    serialize.cpp
