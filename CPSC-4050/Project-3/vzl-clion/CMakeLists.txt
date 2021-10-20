cmake_minimum_required(VERSION 3.19)
project(vzl_clion)

set(CMAKE_CXX_STANDARD 14)
add_executable(vzl_clion things/vzl.C include/Color.h include/Vector.h
        include/VzlViewer.h include/VzlThing.h base/VzlThing.C base/VzlViewer.C things/Box.C things/Box.h
        things/Plane.C things/Plane.h things/Triangle.cpp things/Triangle.h things/MyTriangleThing.cpp things/MyTriangleThing.h things/Ngon.cpp things/Ngon.h things/Face.cpp things/Face.h things/NgonThing.cpp things/NgonThing.h)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -Xclang -fopenmp")

find_package(OpenMP)
if(OpenMP_CXX_FOUND)
    target_link_libraries(vzl_clion OpenMP::OpenMP_CXX)
endif()

include_directories(${OPENMP_INCLUDE_DIRS})
include_directories(${OPENGL_INCLUDE_DIRS} ${GLUT_INCLUDE_DIRS})
target_link_libraries(vzl_clion ${OPENGL_LIBRARIES} ${GLUT_LIBRARY})