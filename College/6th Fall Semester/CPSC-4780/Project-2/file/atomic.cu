#include <iostream>

#define N 16777216
#define THREADS_PER_BLOCK 512

typedef float real_t;

void random_ints(real_t *a, int size) {
    for (int i = 0; i < size; i++) {
        a[i] = drand48();
    }
}

__global__ void dot(real_t *a, real_t *b, real_t *c) {
    __shared__ real_t temp[THREADS_PER_BLOCK];
    int index = threadIdx.x + blockIdx.x * blockDim.x;
    temp[threadIdx.x] = a[index] * b[index];
    __syncthreads();
    if (0 == threadIdx.x) {
        real_t sum = 0;
        for (int i = 0; i < THREADS_PER_BLOCK; i++)
            sum += temp[i];
        atomicAdd(c, sum);
    }
}

int main(void) {
    real_t *a, *b, *c; // host copies of a, b, c
    real_t *dev_a, *dev_b, *dev_c; // device copies of a, b, c
    int size = N * sizeof(real_t); // we need space for N ints
// allocate device copies of a, b, c
    cudaMalloc((void **) &dev_a, size);
    cudaMalloc((void **) &dev_b, size);
    cudaMalloc((void **) &dev_c, sizeof(real_t));
    a = (real_t *) malloc(size);
    b = (real_t *) malloc(size);
    c = (real_t *) malloc(sizeof(real_t));
    random_ints(a, N);
    random_ints(b, N);

    // copy inputs to device
    cudaMemcpy(dev_a, a, size, cudaMemcpyHostToDevice);
    cudaMemcpy(dev_b, b, size, cudaMemcpyHostToDevice);

    // launch dot() kernel
    cudaEvent_t start1, stop1;
    cudaEventCreate(&start1);
    cudaEventRecord(start1, 0);
    float cputime;
    dot<<< N / THREADS_PER_BLOCK, THREADS_PER_BLOCK >>>(dev_a, dev_b, dev_c);

    // copy device result back to host copy of c
    cudaMemcpy(c, dev_c, sizeof(real_t), cudaMemcpyDeviceToHost);
    std::cout << *c << std::endl;

    cudaEventCreate(&stop1);
    cudaEventRecord(stop1, 0);
    cudaEventSynchronize(stop1);
    cudaEventElapsedTime(&cputime, start1, stop1);
    cudaEventDestroy(start1);
    cudaEventDestroy(stop1);

    free(a);
    free(b);
    free(c);
    cudaFree(dev_a);
    cudaFree(dev_b);
    cudaFree(dev_c);
    return 0;
}
