##--------------------------------------------------------
##学习Qt翻译
##Create by tyw66
##--------------------------------------------------------
#定义源码文件
set(SOURCES main.cpp
    mainwindow.h mainwindow.cpp mainwindow.ui
    langwidget.h  langwidget.cpp
    zh-cn.ts   en-us.ts  ja-jp.ts)

source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" FILES ${SOURCES})

#添加可执行程序
add_executable(SwitchLangEx ${SOURCES})


