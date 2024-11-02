##--------------------------------------------------------
##复利计算器
##Create by tyw66 at 2019-04-29
##--------------------------------------------------------
#定义源码文件
set(SOURCES main.cpp
    mainwindow.h mainwindow.cpp mainwindow.ui
    zh_cn.ts)

source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" FILES ${SOURCES})

#添加可执行程序
add_executable(FinancialCalculator ${SOURCES})

#TODO 翻译支持


