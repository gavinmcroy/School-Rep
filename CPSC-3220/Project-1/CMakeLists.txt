cmake_minimum_required(VERSION 3.19)
project(Project_1 C)

#find_library(SHIM /Users/gavintaylormcroy/Documents/GitHub/School-Rep/CPSC-3220/Project-1/shim.dylib)


set(CMAKE_C_STANDARD 99)
set(GCC_COVERAGE_COMPILE_FLAGS "-Wall")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}")

add_executable(Project_1 mallocTest.c)

#target_link_libraries(Project_1 ${SHIM})