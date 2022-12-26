##-------------------------
##学习 <pthread.h>
##-------------------------
TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
#        pthread.cpp \       #pthread基础
#        mutex.cpp   \       #互斥锁
#        rwlock.cpp  \       #读写锁
#        condition.cpp   \   #条件变量
        semaphore.cpp   \   #信号量

