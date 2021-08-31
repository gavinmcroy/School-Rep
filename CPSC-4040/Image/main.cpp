#include <iostream>
#include <memory>
#include <OpenImageIO/imageio.h>
#include <boost/config.hpp>

using namespace OIIO;

using namespace std;

int main(int argc, char* argv[]) {
    if (argc < 2)
    {
        std::cout << "Usage: tut1 path\n";
        std::cout<<__cplusplus<<std::endl;
        return 1;
    }

   // std::cout << argv[1] << " " << file_size(argv[1]) << '\n';
    TypeDesc::UINT8;
    std::string myFile = "Hello.jpg";
    auto out = ImageOutput::create (myFile);
    const int xres = 640, yres = 480;
    const int channels = 3;  // RGB
    unsigned char pixels[xres*yres*channels];
    return 0;
//    std::string myString = "Hello";
//    std::unique_ptr<ImageInput> in = ImageInput::open(myString);
//    if(!in){
//        std::cerr<<"Could not create: "<<geterror()<<std::endl;
//    }
//    std::cout << "Hello, World!" << std::endl;
//    const ImageSpec spec = in->spec();
//    int xres = spec.width;
//    int yres = spec.height;
//    int channel = spec.nchannels;
//
//    auto * pixels = new unsigned char[xres*yres*channel];
//    in->read_image(TypeDesc::UINT8,pixels);
//    in->close();
//    return 0;
}
