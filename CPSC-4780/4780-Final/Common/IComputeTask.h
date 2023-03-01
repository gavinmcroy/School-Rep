#ifndef _ICOMPUTE_TASK_H
#define _ICOMPUTE_TASK_H

#include <OpenCL/opencl.h>


class IComputeTask {
public:

    virtual ~IComputeTask() {};

    virtual bool InitResources(cl_device_id Device, cl_context Context) = 0;

    virtual void ReleaseResources() = 0;

    virtual void ComputeGPU(cl_context Context, cl_command_queue CommandQueue, size_t LocalWorkSize[3]) = 0;

    virtual void ComputeCPU() = 0;

    virtual bool ValidateResults() = 0;
};

#endif // _ICOMPUTE_TASK_H
