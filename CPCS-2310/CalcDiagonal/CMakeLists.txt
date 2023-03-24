cmake_minimum_required(VERSION 3.17)
project(CalcDiagonal C)

set(CMAKE_C_STANDARD 99)

add_executable(CalcDiagonal driver.c diagonal.c diagonal.h)