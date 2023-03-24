cmake_minimum_required(VERSION 3.15)
project(L3)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(L3
        main.cpp
        stddev.cpp
        stddev.h)
