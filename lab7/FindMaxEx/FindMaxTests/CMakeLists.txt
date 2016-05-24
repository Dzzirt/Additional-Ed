cmake_minimum_required(VERSION 3.5)
project(FindMaxTests)


set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${${PROJECT_NAME}_SOURCE_DIR}/bin)


add_executable(FindMaxTests FindMaxTests.cpp TestsMain.cpp)

add_custom_target(V${PROJECT_NAME}
        ${PROJECT_NAME}
        COMMAND valgrind ${${PROJECT_NAME}_SOURCE_DIR}/bin/${PROJECT_NAME}
        )

set_target_properties(FindMaxTests PROPERTIES COTIRE_CXX_PREFIX_HEADER_INIT "stdafx.h")
cotire(FindMaxTests)

#target_link_libraries(FindMaxTests findMaxSrc)

cotire(FindMaxTests)