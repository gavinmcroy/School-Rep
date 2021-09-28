cmake_minimum_required(VERSION 3.19)
project(Masking)

set(CMAKE_CXX_STANDARD 14)
find_package(Openimageio REQUIRED )
find_package(Boost COMPONENTS system filesystem REQUIRED)
include_directories(${OpenImageIO_INCLUDE_DIR})
include_directories(${Boost_INCLUDE_DIRS})


add_executable(Masking main.cpp Masking.cpp Masking.h)
target_link_libraries(Masking /usr/local/Cellar/openimageio/2.2.17.0/lib/libOpenImageIO.2.2.17.dylib)
target_link_libraries(Masking
        ${Boost_FILESYSTEM_LIBRARY}
        ${Boost_SYSTEM_LIBRARY}
        )