cmake_minimum_required(VERSION 3.19)
project(Project_1)

set(CMAKE_CXX_STANDARD 14)

add_executable(Project_1 main.cpp Triangle.cpp Triangle.h ScreenSetup.cpp ScreenSetup.h)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
include_directories(${OPENGL_INCLUDE_DIRS} ${GLUT_INCLUDE_DIRS})
target_link_libraries(Project_1 ${OPENGL_LIBRARIES} ${GLUT_LIBRARY})