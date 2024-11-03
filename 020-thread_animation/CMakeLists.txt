##--------------------------------------------------------
##线程动画
##Create by tyw66 at 2019-12-10
##--------------------------------------------------------
#定义源码文件
set(SOURCES main.cpp
    widget.h widget.cpp widget.ui)

source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" FILES ${SOURCES})

#添加可执行程序
add_executable(ThreadAnimation ${SOURCES})


