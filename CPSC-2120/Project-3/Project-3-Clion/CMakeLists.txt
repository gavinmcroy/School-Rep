cmake_minimum_required(VERSION 3.17)
project(New_Proj)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(New_Proj
        HalloweenOptimization.cpp
        HalloweenOptimization.h
        main.cpp)
