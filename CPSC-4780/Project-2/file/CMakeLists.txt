cmake_minimum_required(VERSION 3.19)
project(file)

set(CMAKE_CXX_STANDARD 14)

add_executable(file main.cpp shared.cu atomic.cu)