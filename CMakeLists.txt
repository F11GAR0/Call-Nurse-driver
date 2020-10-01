cmake_minimum_required(VERSION 2.8.12)

project(orangepidriver LANGUAGES CXX)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -pthread")
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt5 COMPONENTS Core Quick REQUIRED)

file(GLOB source_files
    "main.cpp"
    "qml.qrc"
    "main.h"
    "udp/*.cpp"
    "udp/*.h"
    "bytestream/*.cpp"
    "bytestream/*.h"
    "query/*cpp"
    "query/*h"
)

include_directories(${YOUR_DIRECTORY}/udp)
link_directories(${YOUR_DIRECTORY}/udp)

include_directories(${YOUR_DIRECTORY}/bytestream)
link_directories(${YOUR_DIRECTORY}/bytestream)

include_directories(${YOUR_DIRECTORY}/query)
link_directories(${YOUR_DIRECTORY}/query)

add_executable( ${PROJECT_NAME} ${source_files} )

target_link_libraries(${PROJECT_NAME} Qt5::Core Qt5::Quick)

