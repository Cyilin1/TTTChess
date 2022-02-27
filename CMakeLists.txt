cmake_minimum_required(VERSION 3.21)

project(simple VERSION 0.1)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 COMPONENTS Widgets REQUIRED)

add_executable(simple
    main.cpp
    MainWindow.cpp
    MainWindow.hpp
    MainWindow.ui
    Grid.cpp
    Grid.h
    PaintedWidget.cpp
    PaintedWidget.h
)

target_link_libraries(simple PRIVATE Qt5::Widgets)
