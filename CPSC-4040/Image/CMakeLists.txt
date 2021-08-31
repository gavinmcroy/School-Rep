cmake_minimum_required(VERSION 3.20)
project(Open_Test)

#

set(CMAKE_CXX_STANDARD 17)

find_package(Boost COMPONENTS system filesystem REQUIRED)
find_package(Openimageio COMPONENTS imageio REQUIRED)

add_executable(Open_Test main.cpp)

if(Boost_FOUND)
    message(STATUS "Boost_INCLUDE_DIRS: ${Boost_INCLUDE_DIRS}")
    message(STATUS "Boost_LIBRARIES: ${Boost_LIBRARIES}")
    message(STATUS "Boost_VERSION: ${Boost_VERSION}")
    include_directories(${Boost_INCLUDE_DIRS})
endif()

if(Openimageio_FOUND)
    message(STATUS "Openimageio_INCLUDE_DIRS: ${Openimageio_INCLUDE_DIRS}")
    message(STATUS "Openimageio_LIBRARIES: ${Openimageio_LIBRARIES}")
    message(STATUS "Openimageio_VERSION: ${Openimageio_VERSION}")
    include_directories(${Openimageio_INCLUDE_DIRS})
endif()

target_link_libraries(Open_Test
        ${Boost_FILESYSTEM_LIBRARY}
        ${Boost_SYSTEM_LIBRARY})

#target_link_libraries(Open_Test ${Openimageio_detail_LIBRARY})






























#include_directories(${/usr/local/Cellar/openimageio/2.2.17.0/include})

#find_package(imath COMPONENTS system filesystem REQUIRED)
#find_package(openexr COMPONENTS system filesystem REQUIRED)
#find_package(zstd COMPONENTS system filesystem REQUIRED)

#find_package(snappy COMPONENTS system filesystem REQUIRED)
#find_package(sdl2 COMPONENTS system filesystem REQUIRED)
#find_package(msgpack COMPONENTS system filesystem REQUIRED)

#include_directories(${imath_INCLUDE_DIRS})
#include_directories(${openexr_INCLUDE_DIRS})
#include_directories(${zstd_INCLUDE_DIRS})
#include_directories(${openimageio_INCLUDE_DIRS})
#include_directories(${snappy_INCLUDE_DIRS})
#include_directories(${sdl2_INCLUDE_DIRS})
#include_directories(${msgpack_INCLUDE_DIRS})





#target_link_libraries(Open_Test ${imath})
#target_link_libraries(Open_Test ${openexr})
#target_link_libraries(Open_Test ${zstd})
#target_link_libraries(Open_Test ${snappy})
#target_link_libraries(Open_Test ${sdl2})
# target_link_libraries(Open_Test ${msgpack})


#find_package (my_library COMPONENTS REQUIRED component1 component2 OPTIONAL_COMPONENTS opt_component)