#配置Qt
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt5 REQUIRED COMPONENTS Core Widgets LinguistTools)

link_libraries(Qt5::Core)
link_libraries(Qt5::Widgets)
