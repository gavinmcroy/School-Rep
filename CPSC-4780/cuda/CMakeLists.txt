cmake_minimum_required(VERSION 3.19)
project(cuda CUDA)

set(CMAKE_CUDA_STANDARD 14)

add_executable(cuda main.cu)

set_target_properties(
        cuda
        PROPERTIES
        CUDA_SEPARABLE_COMPILATION ON)