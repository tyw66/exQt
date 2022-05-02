QT -= gui

TEMPLATE = lib
DEFINES += MYLIB_LIBRARY

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    mylib.cpp

HEADERS += \
    MyLib_global.h \
    mylib.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target

##添加hello的动态库
win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../hello/release/ -lhello
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../hello/debug/ -lhello
else:unix:!macx: LIBS += -L$$OUT_PWD/../hello/ -lhello

INCLUDEPATH += $$PWD/../hello
DEPENDPATH += $$PWD/../hello

#
CONFIG += link_prl
CONFIG += create_prl

##添加hello的静态库
#win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../hello/release/ -lhello
#else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../hello/debug/ -lhello
#else:unix:!macx: LIBS += -L$$OUT_PWD/../hello/ -lhello

#INCLUDEPATH += $$PWD/../hello
#DEPENDPATH += $$PWD/../hello

#win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../hello/release/libhello.a
#else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../hello/debug/libhello.a
#else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../hello/release/hello.lib
#else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../hello/debug/hello.lib
#else:unix:!macx: PRE_TARGETDEPS += $$OUT_PWD/../hello/libhello.a
