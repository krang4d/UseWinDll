cmake_minimum_required(VERSION 2.8)

project(CreateDll)
set(HEADERS mega2lib.h imegalib.h)
set(SOURCES mega2lib.cpp)
add_executable(${PROJECT_NAME} main.cpp)
add_library(mega2lib SHARED ${HEADERS} ${SOURCES})

target_link_libraries(${PROJECT_NAME} mega2lib)
