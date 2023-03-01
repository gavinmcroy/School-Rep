cmake_minimum_required(VERSION 3.15)
project(lab10)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(lab10
        driver.cpp
        pixelArt.cpp
        pixelArt.h)
