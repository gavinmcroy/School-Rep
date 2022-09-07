cmake_minimum_required(VERSION 3.17)
project(lk)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(lk

        main.cpp
        stringset.cpp
        stringset.h
        )
