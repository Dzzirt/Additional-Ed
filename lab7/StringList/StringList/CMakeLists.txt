cmake_minimum_required(VERSION 3.5)
project(StringList)



add_library(string_list StringList.cpp StringList.h StringListIterator.h)


set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${${PROJECT_NAME}_SOURCE_DIR}/bin)

add_executable(StringList main.cpp)

add_custom_target(V${PROJECT_NAME}
        ${PROJECT_NAME}
        COMMAND valgrind ${${PROJECT_NAME}_SOURCE_DIR}/bin/${PROJECT_NAME})

target_link_libraries(StringList string_list)

set_target_properties(StringList PROPERTIES COTIRE_CXX_PREFIX_HEADER_INIT "stdafx.h")

cotire(StringList)