#include <memory>

#define GL_SILENCE_DEPRECATION

#include <OpenImageIO/imageio.h>
#include <GLUT/glut.h>
#include <OpenGL/gl.h>

OIIO_NAMESPACE_USING
using namespace std;

void openGLSetup(int argc, char *argv[]);

void displayFunction();

void keyboardEvent(unsigned char key, int x, int y);

void loadImage(const std::string &inputFile);

void writeImage(const std::string &outputFile);

unsigned char *pixels = nullptr;
ImageSpec spec;

int main(int argc, char *argv[]) {
    /* TODO program must take an optional command line arg for image file
     * TODO If no arg is passed then draw a blank black window*/
    /* TODO also test for what type of image (RGB vs RGBA) */
    /* TODO add code documentation */
    std::string myFile = "lightning.jpg";
    loadImage(myFile);
    //openGLSetup(argc, argv);
    delete pixels;
    return 0;
}

void openGLSetup(int argc, char *argv[]) {
    glutInit(&argc, argv);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(1920, 1200);
    glutCreateWindow("My amazing window");
    glutDisplayFunc(displayFunction);
    glutKeyboardFunc(keyboardEvent);
    glutMainLoop();
}

void displayFunction() {
    glClearColor(1, 1, 1, 1);
    glRasterPos2i(0, 0);
    glWindowPos2i(0, 0);
    glDrawPixels(1920, 1200, GL_RGB, GL_UNSIGNED_BYTE, pixels);
    glFlush();
}

void keyboardEvent(unsigned char key, int x, int y) {
    switch (key) {
        case 'k': {
            glClearColor(1.0, 0.0, 0.0, 0.0);
            std::cout << "Input detected " << std::endl;
            glClear(GL_COLOR_BUFFER_BIT);
            break;
        }
        case 'r':{
            /* TODO Read in image */
            break;
        }
        case 'i':{
            /* TODO Invert colors */
            break;
        }
        case 'q': {
            glutDestroyWindow(glutGetWindow());
            exit(0);
        }
        case 'w': {
            std::string myOutFile = "Output.jpg";
            writeImage(myOutFile);
            break;
        }
        default:
            break;
    }
}

void loadImage(const std::string &inputFile) {
    auto input = ImageInput::open(inputFile);
    if (!input) {
        std::cerr << "Error with file. " << geterror();
        exit(-1);
    }

    spec = input->spec();
    int xRes = spec.width;
    int yRes = spec.height;
    int channels = spec.nchannels;

    pixels = new unsigned char[xRes * yRes * channels];
    input->read_image(TypeDesc::UINT8, pixels);

    std::cout << "Image information: " << std::endl;
    std::cout << "X RES " << xRes << std::endl;
    std::cout << "Y RES " << yRes << std::endl;
    std::cout << "CHANNEL " << channels << std::endl;
    input->close();
}

void writeImage(const std::string &outputFile) {
    auto out = ImageOutput::create("Output.jpg");
    ImageSpec specOut(spec.width, spec.height, spec.nchannels, TypeDesc::UINT8);
    out->open(outputFile, specOut);
    out->write_image(TypeDesc::UINT8, pixels);
    out->close();
}
