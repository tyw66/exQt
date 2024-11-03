##--------------------------------------------------------
##JSON校验器
##Create by tyw66 at 2024-10
##--------------------------------------------------------
#定义源码文件
set(SOURCES main.cpp
    mainwindow.h mainwindow.cpp mainwindow.ui
    jsonutils.h jsonutils.cpp)

source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" FILES ${SOURCES})

#添加可执行程序
add_executable(JsonUtils ${SOURCES})

#包含头文件-rapidJson
target_include_directories(JsonUtils PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
