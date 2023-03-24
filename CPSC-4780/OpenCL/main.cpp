#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <OpenCL/cl.h>

#define N 40
#define MAXIMUM_SIZE (0x100000)
#define BLOCK_SIZE 1

int main() {
    int width = N;
    auto *A = (float *) malloc(sizeof(float) * width * width);
    auto *B = (float *) malloc(sizeof(float) * width * width);
    auto *Res = (float *) malloc(sizeof(float) * width * width);
    auto *D = (float *) malloc(sizeof(float) * width * width);
    printf("Generating Matrices\n");
    int data = 0;
    data = 0;
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < width; j++) {
            *((B + i * width + j)) = (float) data;
            *(A + i * width + j) = (float) data;
            data++;
        }
    }

    cl_event prof_event;
    __attribute__((unused)) cl_command_queue comm;


    cl_device_id deviceID = nullptr;
    cl_context context = nullptr;
    cl_command_queue commandQueue = nullptr;
    cl_program program = nullptr;
    cl_kernel kernel = nullptr;
    cl_platform_id platformId = nullptr;
    cl_uint retNumDevices;
    cl_uint retNumPlatforms;
    cl_int ret;

    cl_mem memoryObjectA = nullptr;
    cl_mem memoryObjectB = nullptr;
    cl_mem memoryObjectC = nullptr;
    cl_mem rowA = nullptr;
    cl_mem colC = nullptr;

    size_t sourceSize;
    int row = width;
    int col = width;
    FILE *filePointer;
    char filename[] = "./multiply.cl";
    char *sourceString;

    /* Load the source code containing the kernel*/

    filePointer = fopen(filename, "r");
    sourceString = (char *) malloc(MAXIMUM_SIZE);
    sourceSize = fread(sourceString, 1, MAXIMUM_SIZE, filePointer);
    fclose(filePointer);

    /* Get Platform and Device Info */
    ret = clGetPlatformIDs(1, &platformId, &retNumPlatforms);
    ret = clGetDeviceIDs(platformId, CL_DEVICE_TYPE_GPU, 1, &deviceID, &retNumDevices);

    /* Create OpenCL context */
    context = clCreateContext(nullptr, 1, &deviceID, nullptr, nullptr, &ret);

    /* Create Command Queue */
    commandQueue = clCreateCommandQueue(context, deviceID, CL_QUEUE_PROFILING_ENABLE, &ret);

    /* Create Memory Buffer */
    memoryObjectA = clCreateBuffer(context, CL_MEM_READ_WRITE, width * width * sizeof(float), nullptr, &ret);
    memoryObjectB = clCreateBuffer(context, CL_MEM_READ_WRITE, width * width * sizeof(float), nullptr, &ret);
    memoryObjectC = clCreateBuffer(context, CL_MEM_READ_WRITE, width * width * sizeof(float), nullptr, &ret);
    rowA = clCreateBuffer(context, CL_MEM_READ_WRITE, sizeof(int), nullptr, &ret);
    colC = clCreateBuffer(context, CL_MEM_READ_WRITE, sizeof(int), nullptr, &ret);

    // Copy the lists A and B to their respective memory buffers
    ret = clEnqueueWriteBuffer(commandQueue, memoryObjectA, CL_TRUE, 0,
                               width * width * sizeof(int), A, 0, nullptr, nullptr);
    ret = clEnqueueWriteBuffer(commandQueue, memoryObjectB, CL_TRUE, 0,
                               width * width * sizeof(int), B, 0, nullptr, nullptr);
    ret = clEnqueueWriteBuffer(commandQueue, rowA, CL_TRUE, 0, sizeof(int), &row, 0, nullptr, nullptr);
    ret = clEnqueueWriteBuffer(commandQueue, colC, CL_TRUE, 0, sizeof(int), &col, 0, nullptr, nullptr);

    /* Create Kernel Program from the source */
    program = clCreateProgramWithSource(context, 1, (const char **) &sourceString,
                                        (const size_t *) &sourceSize, &ret);

    /* Build Kernel */
    ret = clBuildProgram(program, 1, &deviceID, nullptr, nullptr, nullptr);

    /* Create the OpenCL Kernel */
    kernel = clCreateKernel(program, "matrixMultiplication", &ret);

    /* Set Kernel Args */
    ret = clSetKernelArg(kernel, 0, sizeof(cl_mem), (void *) &memoryObjectA);
    ret = clSetKernelArg(kernel, 1, sizeof(cl_mem), (void *) &memoryObjectB);
    ret = clSetKernelArg(kernel, 2, sizeof(cl_mem), (void *) &memoryObjectC);
    ret = clSetKernelArg(kernel, 3, sizeof(int), (void *) &row);
    ret = clSetKernelArg(kernel, 4, sizeof(int), (void *) &col);
    /* Execute Kernel */
    size_t global[2] = {static_cast<size_t>(width), static_cast<size_t>(width)};
    size_t local[2] = {BLOCK_SIZE, BLOCK_SIZE};


    clEnqueueNDRangeKernel(commandQueue, kernel, 2, nullptr, global, local, 0, nullptr, &prof_event);

    clFinish(commandQueue);
    clWaitForEvents(1, &prof_event);

    cl_ulong endTime;
    size_t returnBytes;
    double runTime;
    cl_ulong startTime;


    clGetEventProfilingInfo(prof_event, CL_PROFILING_COMMAND_START, sizeof(cl_ulong), &startTime, &returnBytes);
    clGetEventProfilingInfo(prof_event, CL_PROFILING_COMMAND_END, sizeof(cl_ulong), &endTime, &returnBytes);

    runTime = (double) (endTime - startTime);

    printf("\nOpenCl Execution time is: %0.6f milliseconds \n", runTime / 1000000);

    ret = clEnqueueReadBuffer(commandQueue, memoryObjectC, CL_TRUE, 0,
                              width * width * sizeof(float), Res, 0, nullptr, nullptr);

    printf("\nThe Matrix Result is Below : \n");
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < width; j++) {

            printf("%f ", *(Res + i * width + j));

        }
    }

    ret = clFlush(commandQueue);
    ret = clFinish(commandQueue);
    ret = clReleaseKernel(kernel);
    ret = clReleaseProgram(program);
    ret = clReleaseMemObject(memoryObjectA);
    ret = clReleaseMemObject(memoryObjectB);
    ret = clReleaseMemObject(memoryObjectC);
    ret = clReleaseCommandQueue(commandQueue);
    ret = clReleaseContext(context);

    free(sourceString);

    float sum;

    for (int i = 0; i < width; i++) {
        for (int j = 0; j < width; j++) {
            sum = 0;
            for (int k = 0; k < width; k++) {
                sum += A[i * col + k] * B[k * row + j];
            }
            D[i * width + j] = sum;
        }

    }
    printf("\nResults : \n");
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < width; j++) {
            printf("%f ", *(D + i * width + j));

        }
    }

    printf("The OpenCl Execution time is: %0.6f milliseconds \n", runTime / 1000000);
    return 0;
}
