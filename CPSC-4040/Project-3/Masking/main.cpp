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

    char *image = nullptr;
    ImageSpec imageSpec = Masking::readImage(argv[1], image);
    Masking::writeImage(argv[2], imageSpec.width, imageSpec.height, image);
    return 0;
}
