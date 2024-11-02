##--------------------------------------------------------
##桌面小工具
##Create by tyw66 at 2022-03-20
##--------------------------------------------------------
#定义源码文件
set(SOURCES main.cpp
    mainwindow.h mainwindow.cpp mainwindow.ui
    res.qrc)

source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" FILES ${SOURCES})

#添加可执行程序
add_executable(Justforfun ${SOURCES})

#TODO 添加app的图标
# RC_ICONS = res/my_ico.ico
