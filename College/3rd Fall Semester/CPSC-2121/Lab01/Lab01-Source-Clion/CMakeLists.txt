cmake_minimum_required(VERSION 3.17)
project(lab01_dean)

set(CMAKE_CXX_STANDARD 14)

include_directories(lab01)

add_executable(lab01_dean
        lab01/intset.cpp
        lab01/intset.h
        lab01/main.cpp)
