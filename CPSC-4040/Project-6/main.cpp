#include <iostream>
#include <OpenImageIO/imageio.h>
#include <memory>

OIIO_NAMESPACE_USING

int main(int argc, char *argv[]) {
    const int EXPECTED_ARGS = 3;
    if (argc < EXPECTED_ARGS) {
        std::cerr << "Not enough arguments provided " << std::endl;
        exit(1);
    }

    std::string fileInput = argv[1];
    std::string fileOutput = argv[2];
    auto inputFile = ImageInput::open(fileInput);

    if (!inputFile) {
        std::cerr << "File input error" << std::endl;
        exit(1);
    }

    ImageSpec spec = inputFile->spec();
    std::unique_ptr<unsigned char> image = std::unique_ptr<unsigned char>
            (new unsigned char[spec.height * spec.width * spec.nchannels]);
    image.get()[1] = 3;
    inputFile->read_image(TypeDesc::UINT8,image.get());

    inputFile->close();
    return 0;
}










/* width = col. height = row */
//    auto **pixmap = new RGB_PIXEL *[spec.height];
//    pixmap[0] = new RGB_PIXEL[spec.width * spec.height];
//    for(int i = 1; i < spec.height; i++){
//        pixmap[i] = pixmap[i-1]+spec.width;
//    }
