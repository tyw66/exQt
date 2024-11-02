##--------------------------------------------------------
##模仿WPS工具栏面板太窄时，两侧出现按钮，点击起到滚动作用
##Create by tyw66 at 2020-05-07
##--------------------------------------------------------
#定义源码文件
set(SOURCES main.cpp
    mainwindow.h mainwindow.cpp mainwindow.ui)

source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" FILES ${SOURCES})

#添加可执行程序
add_executable(ScrollButton ${SOURCES})
