#include <memory>
#include <iostream>
#include <OpenImageIO/imageio.h>
#include "Masking.h"

OIIO_NAMESPACE_USING

/* ./programName input.img output.png */
int main(int argc, char *argv[]) {
    if (argc < 3) {
        std::cerr << "Error, not enough arguments " << std::endl;
        exit(-1);
    }
    Masking masking(argv[1],argv[2]);
    return 0;
}
