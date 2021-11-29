cmake_minimum_required(VERSION 3.19)
project(Test)

set(CMAKE_CXX_STANDARD 14)

add_executable(Test main.cpp subdivisioncurve.cpp subdivisioncurve.h CurveEvaluator.cpp CurveEvaluator.h Curve.cpp Curve.h Point.cpp Point.h)