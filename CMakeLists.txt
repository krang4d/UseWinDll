cmake_minimum_required(VERSION 3.12)

project(useDll)
set(CMAKE_CXX_STANDARD 14)
#set(CMAKE_EXE_LINKER_FLAGS "-megalib")
#set(HEADERS mega2lib.h)
set(SOURCES main.cpp lib/imegalib.h)

add_subdirectory(lib)
add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} libmega2lib)
#add_library(megalib)
