cmake_minimum_required(VERSION 3.5)

set (CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/CMake")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

include(cotire)

add_subdirectory(StringList)
add_subdirectory(StringListTests)

