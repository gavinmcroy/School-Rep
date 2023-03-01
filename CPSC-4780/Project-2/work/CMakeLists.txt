cmake_minimum_required(VERSION 3.19)
project(work CUDA)

set(CMAKE_CUDA_STANDARD 14)

add_executable(work atomic.cu shared.cu)

set_target_properties(
        work
        PROPERTIES
        CUDA_SEPARABLE_COMPILATION ON)