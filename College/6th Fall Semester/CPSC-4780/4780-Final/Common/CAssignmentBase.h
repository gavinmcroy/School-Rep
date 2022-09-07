#ifndef _CASSIGNMENT_BASE_H
#define _CASSIGNMENT_BASE_H

#include "IComputeTask.h"

class CAssignmentBase {
public:
    CAssignmentBase();

    virtual ~CAssignmentBase();

    virtual bool EnterMainLoop(int argc, char **argv);

    virtual bool DoCompute() = 0;

protected:
    virtual bool InitCLContext();

    virtual void ReleaseCLContext();

    virtual bool RunComputeTask(IComputeTask &Task, size_t LocalWorkSize[3]);

    cl_platform_id m_CLPlatform;
    cl_device_id m_CLDevice;
    cl_context m_CLContext;
    cl_command_queue m_CLCommandQueue;
};

#endif // _CASSIGNMENT_BASE_H
