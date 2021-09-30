cmake_minimum_required(VERSION 3.19)
project(Project_2)

set(CMAKE_CXX_STANDARD 14)

find_package(Boost COMPONENTS system filesystem REQUIRED)
find_package(Openimageio REQUIRED )

include_directories(${Boost_INCLUDE_DIRS})
include_directories(${OpenImageIO_INCLUDE_DIR})

add_executable(Project_2 main.cpp Camera.cpp Camera.h Vector.h ImagePlane.cpp ImagePlane.h Color.h
        Ray.cpp Ray.h Sphere.cpp Sphere.h Plane.cpp Plane.h Triangle.cpp Triangle.h Light.cpp Light.h
        Geometry.h Scene.cpp Scene.h)

target_link_libraries(Project_2
        ${Boost_FILESYSTEM_LIBRARY}
        ${Boost_SYSTEM_LIBRARY}
        )
target_link_libraries(Project_2 /usr/local/Cellar/openimageio/2.2.17.0/lib/libOpenImageIO.2.2.17.dylib)