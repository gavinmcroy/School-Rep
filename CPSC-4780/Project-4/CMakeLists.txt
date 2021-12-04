cmake_minimum_required(VERSION 3.21)
project(Project_4)

set(CMAKE_CXX_STANDARD 17)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
include_directories(${OPENGL_INCLUDE_DIRS} ${GLUT_INCLUDE_DIRS})
target_link_libraries(Project_4 ${OPENGL_LIBRARIES} ${GLUT_LIBRARY})
add_executable(Project_4 main.cpp)
