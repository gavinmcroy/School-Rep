cmake_minimum_required(VERSION 3.19)
project(planetclose)

set(CMAKE_CXX_STANDARD 17)

find_package(Boost COMPONENTS system filesystem REQUIRED)
find_package(Openimageio REQUIRED )

add_executable(Open_Test main.cpp)

if(Boost_FOUND)
    message(STATUS "Boost_INCLUDE_DIRS: ${Boost_INCLUDE_DIRS}")
    message(STATUS "Boost_LIBRARIES: ${Boost_LIBRARIES}")
    message(STATUS "Boost_VERSION: ${Boost_VERSION}")
    message(${Boost_SYSTEM_LIBRARY})
    include_directories(${Boost_INCLUDE_DIRS})
endif()

if(Openimageio_FOUND)
    message(STATUS "OpenImageIO_INCLUDE_DIR: ${OpenImageIO_INCLUDE_DIR}")
    message(STATUS "Openimageio_LIBRARIES: ${OpenImageIO_LIB_DIR}")
    message(STATUS "Openimageio_VERSION: ${Openimageio_VERSION}")
    include_directories(${OpenImageIO_INCLUDE_DIR})
endif()

target_link_libraries(Open_Test
        ${Boost_FILESYSTEM_LIBRARY}
        ${Boost_SYSTEM_LIBRARY}
        )
target_link_libraries(Open_Test /usr/local/Cellar/openimageio/2.2.18.0/lib/libOpenImageIO.2.2.18.dylib)

SET(GXX_COVERAGE_COMPILE_FLAGS "-O3 -Wall")

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
include_directories(${OPENGL_INCLUDE_DIRS} ${GLUT_INCLUDE_DIRS})
target_link_libraries(Open_Test ${OPENGL_LIBRARIES} ${GLUT_LIBRARY})