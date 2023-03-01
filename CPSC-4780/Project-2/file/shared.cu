#include <vector>
#include <iostream>
#include <numeric>

typedef float real_t;

const size_t THREAD_PER_BLOCK = 512;

void random_ints(real_t *a, int size) {
    for (int i = 0; i < size; i++) {
        a[i] = drand48();
    }
}

__global__ void partial_dot(const real_t *v1, const real_t *v2, real_t *out, int N) {
    __shared__ real_t cache[THREAD_PER_BLOCK];
    int i = blockIdx.x * blockDim.x + threadIdx.x;
    cache[threadIdx.x] = 0.f;
    while (i < N) {
        cache[threadIdx.x] += v1[i] * v2[i];
        i += gridDim.x * blockDim.x;
    }
    __syncthreads();
    // required because later on the current thread is accessing
    // data written by another thread
    i = THREAD_PER_BLOCK / 2;
    while (i > 0) {
        if (threadIdx.x < i) cache[threadIdx.x] += cache[threadIdx.x + i];
        __syncthreads();
        i /= 2; //not sure bitwise operations are actually faster
    }

    if (threadIdx.x == 0) out[blockIdx.x] = cache[0];
}

//------------------------------------------------------------------------------
int main(int argc, char **argv) {

    const size_t ARRAY_SIZE = 16777216;
    const int BLOCKS = 64;
    const int THREADS_PER_BLOCK = THREAD_PER_BLOCK;
    const size_t SIZE = ARRAY_SIZE * sizeof(real_t);

    // device storage
    //real_t *dev_v1 = 0; // vector 1
    //real_t *dev_v2 = 0; // vector 2
  //  real_t *dev_vout = 0; // partial redution = number of blocks

    cudaMalloc((void **) &dev_v1, SIZE);
    cudaMalloc((void **) &dev_v2, SIZE);
    cudaMalloc((void **) &dev_vout, BLOCKS * sizeof(real_t));
    dev_v1 = (real_t *) malloc(size);
    dev_v2 = (real_t *) malloc(size);
    dev_vout = (real_t *) malloc(sizeof(real_t));

    // host storage
    std::vector <real_t> host_v1(ARRAY_SIZE);
    std::vector <real_t> host_v2(ARRAY_SIZE);
    std::vector <real_t> host_vout(BLOCKS);

    random_ints(dev_v1, ARRAY_SIZE);
    random_ints(dev_v2, ARRAY_SIZE);

    cudaEvent_t start1, stop1;
    cudaEventCreate(&start1);
    cudaEventRecord(start1, 0);
    float cputime;
    // execute kernel
    partial_dot<<<BLOCKS, THREADS_PER_BLOCK>>>(dev_v1, dev_v2, dev_vout, ARRAY_SIZE);

    // copy output data from device(gpu) to host(cpu)
    cudaMemcpy(&host_vout[0], dev_vout, BLOCKS * sizeof(real_t), cudaMemcpyDeviceToHost);

    // print dot product by summing up the partially reduced vectors
    std::cout << "GPU: " << std::accumulate(host_vout.begin(), host_vout.end(), real_t(0)) << std::endl;

    cudaEventCreate(&stop1);
    cudaEventRecord(stop1, 0);
    cudaEventSynchronize(stop1);
    cudaEventElapsedTime(&cputime, start1, stop1);
    cudaEventDestroy(start1);
    cudaEventDestroy(stop1);

    // free memory
    cudaFree(dev_v1);
    cudaFree(dev_v2);
    cudaFree(dev_vout);

    return 0;
}
