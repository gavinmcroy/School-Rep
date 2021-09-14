#include <iostream>

__global__ void MatrixMulKernel(float * Md,float * Nd, float * Pd, int width);

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

__global__ void MatrixMulKernel(float * Md,float * Nd, float * Pd, int width){

}