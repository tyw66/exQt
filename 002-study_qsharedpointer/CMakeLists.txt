##--------------------------------------------------------
##学习Qt智能指针
##Create by tyw66
##--------------------------------------------------------
#定义源码文件
set(SOURCES main.cpp)

source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" FILES ${SOURCES})

#添加可执行程序
add_executable(QSharedPointer ${SOURCES})
