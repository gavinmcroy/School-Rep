#include <memory>

#define GL_SILENCE_DEPRECATION

#ifdef __APPLE__

#include <OpenImageIO/imageio.h>
#include <GLUT/glut.h>
#include <OpenGL/gl.h>

#elif
#include <GL/glu.h>
#include <GL/gl.h>
#include <GL/glut.h>
#endif

OIIO_NAMESPACE_USING
using namespace std;

void openGLSetup(int argc, char *argv[]);

void displayFunction();

void reshapeFunction(int x, int y);

void keyboardEvent(unsigned char key, int x, int y);

void loadImage(const std::string &inputFile);

void writeImage(const std::string &outputFile);

void invertImage();

int getImagePixelTypeForGL();

int state = 0;
//unsigned char *pixels = nullptr;
std::vector<unsigned char*> images;
std::vector<ImageSpec> specs;
bool displayOn = true;
//ImageSpec spec;

int main(int argc, char *argv[]) {

    /* TODO KNOWN PROBLEMS:
     * Images are displayed upside down
     * grey scale images are improperly displayed
     * Implement Multiple Image Input/Output */

    if (argc > 1) {
        loadImage(argv[1]);
    }

    openGLSetup(argc, argv);
    for(int i = 0; i < images.size(); i++);
    delete pixels;
    return 0;
}

/* Handles all of openGL's init functions */
void openGLSetup(int argc, char *argv[]) {
    glutInit(&argc, argv);
    glutInitWindowPosition(0, 0);
    if (!pixels) {
        glutInitWindowSize(900, 900);
    } else {
        glutInitWindowSize(spec.width, spec.height);
    }
    glutCreateWindow("My amazing window");
    glutDisplayFunc(displayFunction);
    glutReshapeFunc(reshapeFunction);
    glutKeyboardFunc(keyboardEvent);
    glutMainLoop();
}

/* Required openGL function that handles image display */
void displayFunction() {
    glClearColor(0, 0, 0, 0);
    glRasterPos2i(0, 0);
    glWindowPos2i(0, 0);
    if (pixels != nullptr && displayOn) {
        glDrawPixels(spec.width, spec.height, getImagePixelTypeForGL(), GL_UNSIGNED_BYTE, pixels);
        glFlush();
    }
    glClear(GL_COLOR_BUFFER_BIT);
}

/* Required openGL function that handles window resizing */
void reshapeFunction(int x, int y) {
    /*do nothing */
}

/* Handles all related keyboard events
 * k = cleared input
 * r = read a given image and display
 * i = display the image loaded in memory but inverted
 * q = close the application
 * w = write the image loaded in memory to a file called output.jpg
 **/
void keyboardEvent(unsigned char key, int x, int y) {
    switch (key) {
        case 'k': {
            std::cout << "Image cleared from buffer" << std::endl;
            delete pixels;
            pixels = nullptr;
            displayFunction();
            glFlush();
            break;
        }
        case 'r': {
            std::string fileName;
            std::cout << "Enter a file name " << std::endl;
            cin >> fileName;
            loadImage(fileName);
            displayFunction();
            break;
        }
        case 'i': {
            std::cout << "i key pressed " << std::endl;
            invertImage();
            displayFunction();
            glDrawPixels(spec.width, spec.height, getImagePixelTypeForGL(), GL_UNSIGNED_BYTE, pixels);
            glFlush();
            break;
        }
        case 'q': {
            glutDestroyWindow(glutGetWindow());
            exit(0);
        }
        case 'w': {
            std::string myOutFile = "Output.jpg";
            std::cout << "Wrote " << myOutFile << std::endl;
            writeImage(myOutFile);
            break;
        }
        default:
            std::cout << "Empty" << std::endl;
            break;
    }
}

/* Loads the image and allocates required memory. Also prints the image statistics
 * and assigns the global value spec to hold all required image info */
void loadImage(const std::string &inputFile) {
    auto input = ImageInput::open(inputFile);
    if (!input) {
        std::cerr << "Error with file. " << geterror();
        exit(-1);
    }

    spec = input->spec();
    /* TODO Special case for gray scale images */
    if (getImagePixelTypeForGL() == GL_LUMINANCE) {
        int RGB = 3;
        pixels = new unsigned char[spec.width * spec.height * RGB];
        input->read_image(TypeDesc::UINT8, pixels);
    } else {
        pixels = new unsigned char[spec.width * spec.height * spec.nchannels];
        input->read_image(TypeDesc::UINT8, pixels);
    }

    std::string displayType;
    for (auto &channelName : spec.channelnames) {
        displayType += channelName;
    }

    std::cout << "Image information: " << std::endl;
    std::cout << "X RES   " << spec.width << std::endl;
    std::cout << "Y RES   " << spec.height << std::endl;
    std::cout << "CHANNEL " << spec.nchannels << std::endl;
    std::cout << "TYPE    " << displayType << std::endl;
    input->close();
}

/* Writes the image */
void writeImage(const std::string &outputFile) {
    auto out = ImageOutput::create("Output.jpg");
    ImageSpec specOut(spec.width, spec.height, spec.nchannels, TypeDesc::UINT8);
    out->open(outputFile, specOut);
    out->write_image(TypeDesc::UINT8, pixels);
    out->close();
}

/* Inverts the image */
void invertImage() {
    unsigned char maxVal = 255;
    for (int i = 0; i < (spec.width * spec.height * spec.nchannels); i++) {
        pixels[i] = maxVal - pixels[i];
    }
}

/* Determines what type of image was read in, and returns the OpenGL macro
 * that is used for displaying images */
int getImagePixelTypeForGL() {
    std::string mainString;
    for (auto &channelName : spec.channelnames) {
        mainString += channelName;
    }
    if (mainString == "RGB") {
        return GL_RGB;
    } else if (mainString == "RGBA") {
        return GL_RGBA;
    } else {
        return GL_LUMINANCE;
    }
}

