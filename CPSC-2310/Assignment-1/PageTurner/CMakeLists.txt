cmake_minimum_required(VERSION 3.17)
project(PageTurner C)

set(CMAKE_C_STANDARD 99)

add_executable(PageTurner driver.c functions.c functions.h)