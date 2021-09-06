cmake_minimum_required(VERSION 3.19)
project(Project_1)

set(CMAKE_CXX_STANDARD 14)

add_executable(Project_1 main.cpp Triangle.cpp Triangle.h ScreenSetup.cpp
        ScreenSetup.h VzlViewer.cpp VzlViewer.h
        VzlThing.C VzlViewer.h)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -Xclang -fopenmp")

find_package(OpenMP)
if(OpenMP_CXX_FOUND)
    target_link_libraries(Project_1 OpenMP::OpenMP_CXX)
endif()

include_directories(${OPENGL_INCLUDE_DIRS} ${GLUT_INCLUDE_DIRS} ${OPENMP_INCLUDE_DIRS})
target_link_libraries(Project_1 ${OPENGL_LIBRARIES} ${GLUT_LIBRARY})