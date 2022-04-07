TEMPLATE=lib
QT += widgets
DEFINES+=SKINWIDGET_LIBRARY

TARGET=skinlib
DESTDIR=$${PWD}/../../build-skinLib

HEADERS += \
    skinwidget.h \
    skinwidget_global.h

SOURCES += \
    skinwidget.cpp

#每一套皮肤（QSS+图标）都是一个qrc
RESOURCES += \
    darkorange.qrc \
    lightblue.qrc


#将qrc文件编译打包为rcc资源文件输出到build目录供程序切换皮肤使用
system(cd $$DESTDIR && mkdir rcc)
system(rcc --binary lightblue.qrc -o $${DESTDIR}/rcc/lightblue.rcc)
system(rcc --binary darkorange.qrc -o $${DESTDIR}/rcc/darkorange.rcc)



