#========================================================================================
#定义源码文件
set(SOURCES_EasySkin skinlib/skinwidget_global.h
    skinlib/skinwidget.h  skinlib/skinwidget.cpp
    skinlib/lightblue.qrc  skinlib/darkorange.qrc )

source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" FILES ${SOURCES_EasySkin})

#添加库
add_library(EasySkin SHARED ${SOURCES_EasySkin})

#定义导出符号
set_target_properties(EasySkin PROPERTIES
    COMPILE_DEFINITIONS SKINWIDGET_LIBRARY
)


#TODO 将qrc文件编译打包为rcc资源文件输出到build目录供程序切换皮肤使用
# file(MAKE_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/rcc)
# qt5_add_resources(RESOURCES_VARIABLE LightBlue FILES skinlib/lightblue.qrc)
# qt5_add_resources(RESOURCES_VARIABLE DarkOrange FILES skinlib/darkorange.qrc)



#========================================================================================
#定义源码文件
set(SOURCES_Example example/main.cpp
    example/mainwindow.h  example/mainwindow.cpp  example/mainwindow.ui)

source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" FILES ${SOURCES_Example})

#添加可执行程序
add_executable(EasySkinExample ${SOURCES_Example})

#指定依赖
target_include_directories(EasySkinExample PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/skinlib)
target_link_libraries(EasySkinExample PUBLIC EasySkin)
