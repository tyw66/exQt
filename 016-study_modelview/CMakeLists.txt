##--------------------------------------------------------
##学习Qt项视图
##Create by tyw66 at 2018-10-08
##--------------------------------------------------------
#定义源码文件
set(SOURCES main.cpp
    widget.h widget.cpp widget.ui
    mydelegate.h mydelegate.cpp)

source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" FILES ${SOURCES})

#添加可执行程序
add_executable(ModelViewEx ${SOURCES})


