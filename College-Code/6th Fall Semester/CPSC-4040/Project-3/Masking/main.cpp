#include <memory>
#include <iostream>
#include <OpenImageIO/imageio.h>
#include "Masking.h"

OIIO_NAMESPACE_USING

/* ./programName input.img output.png */
int main(int argc, char *argv[]) {
    const int EXPECTED_ARGS = 3;
    if (argc < EXPECTED_ARGS) {
        std::cerr << "Error, not enough arguments " << std::endl;
        exit(-1);
    }
    Masking masking(argv[1],argv[2]);
    return 0;
}
