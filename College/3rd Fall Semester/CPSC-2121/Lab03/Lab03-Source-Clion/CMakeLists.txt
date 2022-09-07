cmake_minimum_required(VERSION 3.17)
project(Lab03_Source_Clion)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Lab03_Source_Clion
        main.cpp
        Point.cpp
        Point.h
        PointMap.cpp
        PointMap.h)
