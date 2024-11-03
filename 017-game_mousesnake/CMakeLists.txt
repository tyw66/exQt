##--------------------------------------------------------
##鼠标贪食蛇
##Create by tyw66 at 2022-09-20 
##--------------------------------------------------------
#定义源码文件
set(SOURCES main.cpp
    mainwindow.h mainwindow.cpp mainwindow.ui)

source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" FILES ${SOURCES})

#添加可执行程序
add_executable(Game_MouseSnake ${SOURCES})


