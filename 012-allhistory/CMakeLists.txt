#定义源码文件
set(SOURCES main.cpp
    mainwindow.h mainwindow.cpp mainwindow.ui
    res.qrc
    allhistory_zh_CN.ts)

source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" FILES ${SOURCES})

#添加可执行程序
add_executable(AllHistory ${SOURCES})

#TODO 翻译
