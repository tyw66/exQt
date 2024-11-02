#-----------------------------------------------------------
# Qt小项目 @tyw66
#-----------------------------------------------------------
cmake_minimum_required(VERSION 3.5)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

#项目名称和版本
project(exQt VERSION 0.1 LANGUAGES CXX)

#设置程序的输出目录为当前构建目录下的bin文件夹
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
# 设置所有库的输出目录为构建目录下的lib文件夹
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib) #无效？？
#包含源文件目录
include_directories(${CMAKE_SOURCE_DIR})

#配置Qt
include(./use_qt.cmake)

#添加子项目
add_subdirectory(001-data_sync)
add_subdirectory(002-study_qsharedpointer)
add_subdirectory(003-financial_calculator)
add_subdirectory(004-justforfun)
add_subdirectory(005-coolbutton)
add_subdirectory(006-drawerbutton)
add_subdirectory(007-scrollbutton)
add_subdirectory(008-switch_skin)
add_subdirectory(009-game_card_tuolaji)
add_subdirectory(010-qss_designer)
add_subdirectory(011-democal)
add_subdirectory(012-allhistory)

