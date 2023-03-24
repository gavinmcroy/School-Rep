cmake_minimum_required(VERSION 3.19)
project(shared CUDA)

set(CMAKE_CUDA_STANDARD 14)

add_executable(shared main.cu)

set_target_properties(
        shared
        PROPERTIES
        CUDA_SEPARABLE_COMPILATION ON)