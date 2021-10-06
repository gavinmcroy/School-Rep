cmake_minimum_required(VERSION 3.19)
project(3220_Proj_2 C)

set(CMAKE_C_STANDARD 99)

SET(GCC_COVERAGE_COMPILE_FLAGS "-D_XOPEN_SOURCE=600 -O3 -Wall")

add_executable(3220_Proj_2 main.c   mythreads.h mythreads.c)