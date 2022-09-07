#ifndef _CSORT_TASK_H
#define _CSORT_TASK_H

#include "../Common/IComputeTask.h"

class CSortTask : public IComputeTask {
public:
    CSortTask(size_t ArraySize, size_t LocWorkSize[3]);

    ~CSortTask() override;

    bool InitResources(cl_device_id Device, cl_context Context) override;

    void ReleaseResources() override;

    void ComputeGPU(cl_context Context, cl_command_queue CommandQueue, size_t LocalWorkSize[3]) override;

    void ComputeCPU() override;

    bool ValidateResults() override;

protected:

    size_t getPaddedSize(size_t n);

    void Mergesort();

    void Sort_Mergesort(cl_context Context, cl_command_queue CommandQueue, size_t LocalWorkSize[3]);

    void Sort_SimpleSortingNetworkLocal(cl_context Context, cl_command_queue CommandQueue, size_t LocalWorkSize[3]);

    void Sort_BitonicMergesort(cl_context Context, cl_command_queue CommandQueue, size_t LocalWorkSize[3]);

    void ExecuteTask(cl_context Context, cl_command_queue CommandQueue, size_t LocalWorkSize[3], unsigned int task);

    void TestPerformance(cl_context Context, cl_command_queue CommandQueue, size_t LocalWorkSize[3], unsigned int task);

    size_t m_N;
    size_t m_N_padded;
    size_t LocalWorkSize[3];

    // input data
    unsigned int *m_hInput;
    // results
    unsigned int *m_resultCPU;
    unsigned int *m_resultGPU[3];

    cl_mem m_dPingArray;
    cl_mem m_dPongArray;

    //OpenCL program and kernels
    cl_kernel m_SimpleSortingNetworkKernel;
    cl_kernel m_SimpleSortingNetworkLocalKernel;
    cl_kernel m_BitonicStartKernel;
    cl_kernel m_BitonicGlobalKernel;
    cl_kernel m_BitonicLocalKernel;

    cl_program m_Program;
    cl_kernel m_MergesortStartKernel;
    cl_kernel m_MergesortGlobalSmallKernel;
    cl_kernel m_MergesortGlobalBigKernel;

};

#endif // _CSORT_TASK_H
