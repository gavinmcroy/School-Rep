#include "CSortingMain.h"

using namespace std;

int main(int argc, char **argv) {
    CSortingMain mySortingMain;

    auto success = mySortingMain.EnterMainLoop(argc, argv);
    return success ? 0 : 1;
}
