cmake_minimum_required(VERSION 3.17)
project(part2)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(part2
        main.cpp
        StringIntMap.cpp
        StringIntMap.h
        WordGraph.cpp
        WordGraph.h)
