cmake_minimum_required(VERSION 3.5)
project(Calculator)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${${PROJECT_NAME}_SOURCE_DIR}/bin)

add_library(calc CalculatorUI.h CalculatorUI.cpp Calculator.h Calculator.cpp Value.h Value.cpp CFunction.cpp CFunction.h)
add_executable(Calculator main.cpp)



target_link_libraries(Calculator calc)
cotire(Calculator)

set_target_properties(Calculator PROPERTIES COTIRE_CXX_PREFIX_HEADER_INIT "stdafx.h")

