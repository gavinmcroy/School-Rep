#ifndef CL_UTIL_H
#define CL_UTIL_H

#include <OpenCL/opencl.h>
#include <string>
#include <iostream>
#include <algorithm>

class CLUtil {
public:

    static size_t GetGlobalWorkSize(size_t DataElemCount, size_t LocalWorkSize);

    static bool LoadProgramSourceToMemory(const std::string &Path, std::string &SourceCode);

    static cl_program BuildCLProgramFromMemory(cl_device_id Device, cl_context Context, const std::string &SourceCode,
                                               const std::string &CompileOptions = "");

    static void PrintBuildLog(cl_program Program, cl_device_id Device);

    static const char *GetCLErrorString(cl_int CLErrorCode);
};

#define V_RETURN_FALSE_CL(expr, errmsg) do {cl_int e=(expr);if(CL_SUCCESS!=e){std::cerr<<"Error: "<<errmsg<<" ["<<CLUtil::GetCLErrorString(e)<<"]"<<std::endl; return false; }} while(0)
#define V_RETURN_CL(expr, errmsg) do {cl_int e=(expr);if(CL_SUCCESS!=e){std::cerr<<"Error: "<<errmsg<<" ["<<CLUtil::GetCLErrorString(e)<<"]"<<std::endl; return; }} while(0)

#define SAFE_DELETE_ARRAY(x) do {if(x){delete [] x; x = NULL;}} while(0)

#define SAFE_RELEASE_KERNEL(ptr)    do {if(ptr){ clReleaseKernel(ptr); ptr = NULL; }} while(0)
#define SAFE_RELEASE_PROGRAM(ptr)   do {if(ptr){ clReleaseProgram(ptr); ptr = NULL; }} while(0)
#define SAFE_RELEASE_MEMOBJECT(ptr) do {if(ptr){ clReleaseMemObject(ptr); ptr = NULL; }} while(0)

#endif // CL_UTIL_H
