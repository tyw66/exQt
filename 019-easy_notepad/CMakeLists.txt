##--------------------------------------------------------
##简易文本编辑器
##--------------------------------------------------------
#定义源码文件
set(SOURCES main.cpp
    mainwindow.h mainwindow.cpp mainwindow.ui)

source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" FILES ${SOURCES})

#添加可执行程序
add_executable(EasyNotepad ${SOURCES})


