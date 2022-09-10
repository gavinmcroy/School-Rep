cmake_minimum_required(VERSION 3.17)
project(Bad3)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Bad3
        bad3.cpp
        BinarySearchT.cpp
        BinarySearchT.h)
