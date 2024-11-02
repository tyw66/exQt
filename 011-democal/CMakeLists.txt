##------------------------------------------------------------------------------------
##题目：编写Qt界面程序，用户在界面输入参数，计算两种图形的面积和周长。
##要求：图形包括：矩形（输入长和宽）、圆形（输入半径）需要自行设计界面，使用ui文件或者手写界面均可。
##------------------------------------------------------------------------------------
#定义源码文件
set(SOURCES main.cpp
    mainwindow.h mainwindow.cpp mainwindow.ui
    objects.h objects.cpp
    viewerwidget.h viewerwidget.cpp)

source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" FILES ${SOURCES})

#添加可执行程序
#TODO 编译不过
# add_executable(DemoCal ${SOURCES})


