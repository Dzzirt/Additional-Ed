cmake_minimum_required(VERSION 3.5)
project(FindMaxEx)

set (CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/CMake")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y")
include(cotire)

set(SOURCE_FILES main.cpp MathUtils.h)

add_executable(FindMaxEx ${SOURCE_FILES})


add_subdirectory(FindMaxTests)