
#include <OpenCL/cl.h>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#define MAXIMUM_SIZE (0x100000)

int main(){
    
    auto *A = (double *) malloc(sizeof(double));
    
    size_t sourceSize;
    FILE *filePointer;
    char filename[] = "./kernel.cl";
    char *sourceString;
    
    cl_device_id deviceID = nullptr;
    cl_context context = nullptr;
    cl_command_queue commandQueue = nullptr;
    cl_program program = nullptr;
    cl_kernel kernel = nullptr;
    cl_platform_id platformId = nullptr;
    cl_uint retNumDevices;
    cl_uint retNumPlatforms;
    cl_int ret;
    

    
    filePointer = fopen(filename, "r");
    sourceString = (char *) malloc(MAXIMUM_SIZE);
    sourceSize = fread(sourceString, 1, MAXIMUM_SIZE, filePointer);
    
    ret = clGetPlatformIDs(1, &platformId, &retNumPlatforms);
    ret = clGetDeviceIDs(platformId, CL_DEVICE_TYPE_GPU, 1, &deviceID, &retNumDevices);
    
    context = clCreateContext(nullptr,1,&deviceID,nullptr,nullptr,&ret);
    
    cl_mem memoryObjectA = clCreateBuffer(context, CL_MEM_READ_WRITE,sizeof(float), nullptr, &ret);
    

    ret = clEnqueueWriteBuffer(commandQueue, memoryObjectA, CL_TRUE, 0,
                               width * width * sizeof(int), A, 0, nullptr, nullptr);
    
    program = clCreateProgramWithSource(context, 1, (const char **) &sourceString,
                                        (const size_t *) &sourceSize, &ret);
    ret = clBuildProgram(program,1,&deviceID,nullptr,nullptr,nullptr);
    kernel = clCreateKernel(program,"testing",&ret);
}
