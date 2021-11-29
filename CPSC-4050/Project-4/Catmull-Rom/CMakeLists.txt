cmake_minimum_required(VERSION 3.19)
project(Catmull_Rom)

set(CMAKE_CXX_STANDARD 14)

add_executable(Catmull_Rom main.cpp Vector.h
        CatmullRom.cpp CatmullRom.h Curve.cpp Curve.h)