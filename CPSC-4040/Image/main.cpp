#include <memory>
#include <OpenImageIO/imageio.h>

OIIO_NAMESPACE_USING
using namespace std;

int main(int argc, char* argv[]) {

    std::string myFile = "Hello.jpg";
    auto out = ImageOutput::create (myFile);
    return 0;
}

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

