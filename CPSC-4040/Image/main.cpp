#include <memory>

#define GL_SILENCE_DEPRECATION

#include <OpenImageIO/imageio.h>
#include <GLUT/glut.h>
#include <OpenGL/gl.h>

OIIO_NAMESPACE_USING
using namespace std;

void openGLSetup(int argc, char *argv[]);

void displayFunction();

unsigned char* pixels = nullptr;

int main(int argc, char *argv[]) {
    std::string myFile = "lightning.jpg";
    auto input = ImageInput::open(myFile);

    if (!input) {
        std::cerr << "Error with file. " << geterror();
        return -1;
    }

    const ImageSpec spec = input->spec();
    int xRes = spec.width;
    int yRes = spec.height;
    int channels = spec.nchannels;

    pixels = new unsigned char[xRes * yRes * channels];
    input->read_image(TypeDesc::UINT8, pixels);

    std::cout << "Image information: " << std::endl;
    std::cout << "X RES " << xRes << std::endl;
    std::cout << "Y RES " << yRes << std::endl;
    std::cout << "CHANNEL " << channels << std::endl;

    openGLSetup(argc, argv);
    input->close();
    delete pixels;

    return 0;
}

void openGLSetup(int argc, char *argv[]) {
    glutInit(&argc, argv);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(1920, 1200);
    glutCreateWindow("My amazing window");
    glutDisplayFunc(displayFunction);
    glutMainLoop();
}

void displayFunction() {
    glClearColor(1, 1, 1, 1);
    glRasterPos2i(0, 0);
    glDrawPixels(1920, 1200, GL_RGB, GL_UNSIGNED_BYTE, pixels);
    glClear(GL_COLOR_BUFFER_BIT);
    glFlush();
}


