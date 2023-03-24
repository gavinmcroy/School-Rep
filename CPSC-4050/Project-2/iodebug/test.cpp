#include <iostream>
#include <OpenImageIO/imageio.h>

OIIO_NAMESPACE_USING

int main(){
    std::cout<<"Hello"<<std::endl;
    auto imageA = ImageInput::open("trash");
    return 0;
}
