##-------------------------
##学习 <pthread.h>
##-------------------------
TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
#        pthread.cpp \  #基本pthread
#        mutex.cpp   \  #互斥锁
#        rwlock.cpp  \  #读写锁
        condition.cpp   \  #条件变量

