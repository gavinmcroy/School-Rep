#include <iostream>
#include "CSortingMain.h"
#include "CSortTask.h"

using namespace std;

bool CSortingMain::DoCompute() {
    //parallel reduction
    cout << "########################################" << endl;
    cout << "Running sort task..." << endl << endl;
    {
        // set work size and size of input array
        size_t LocalWorkSize[3] = {256, 1, 1};
        unsigned int arraySize = 1024 * 1024;

        // info output
        cout << "Start sorting array of size " << arraySize;
        cout << " using LocalWorkSize " << LocalWorkSize[0] << endl << endl;

        // create sorting task and start it
        CSortTask sorting(arraySize, LocalWorkSize);
        RunComputeTask(sorting, LocalWorkSize);
    }

    return true;
}
