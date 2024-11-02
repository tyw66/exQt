#定义源码文件
set(SOURCES main.cpp
    drawerwidget.h drawerwidget.cpp drawerwidget.ui
    form.h form.cpp form.ui)

source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" FILES ${SOURCES})

#添加可执行程序
add_executable(DrawerWidget ${SOURCES})
