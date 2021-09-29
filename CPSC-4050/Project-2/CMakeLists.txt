cmake_minimum_required(VERSION 3.19)
project(Project_2)

set(CMAKE_CXX_STANDARD 14)

add_executable(Project_2 main.cpp Camera.cpp Camera.h Vector.h ImagePlane.cpp ImagePlane.h Color.h Ray.cpp Ray.h Sphere.cpp Sphere.h Plane.cpp Plane.h Triangle.cpp Triangle.h Light.cpp Light.h Geometry.h Scene.cpp Scene.h)