##--------------------------------------------------------
##滑稽表情
##Create by tyw66 at 2020-05-25
##--------------------------------------------------------
#定义源码文件
set(SOURCES main.cpp
    funnywidget.h funnywidget.cpp funnywidget.ui)

source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" FILES ${SOURCES})

#添加可执行程序
add_executable(FunnyFace ${SOURCES})


