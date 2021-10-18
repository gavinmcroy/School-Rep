#include <memory>
#include <iostream>
#include <string>
#include <fstream>

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

void specialKeyboardEvent(int key, int x, int y);

void loadImage(const std::string &inputFile);

float *loadFilterFile(const std::string &fileName, int &kernelSize);

void writeImage(const std::string &outputFile);

void invertImage();

int getImagePixelTypeForGL();

float getFilterIndex(float *filter, int x, int y, int kernelSize);

int state = 0;
std::vector<unsigned char *> images;
std::vector<ImageSpec> specs;

int main(int argc, char *argv[]) {
    /* Means all third optional argument was passed into the program*/
    const int OUTPUT_PASSED = 4;

    /* TODO KNOWN PROBLEMS:
     * Images are displayed upside down
     * grey scale images are improperly displayed but properly outputted? */
    if (argc < 3) {
        std::cerr << "Not enough command line arguments" << std::endl;
        exit(1);
    }
    std::string filterFileName = argv[1];
    std::string imageFileName = argv[2];
    std::string outputFileName = "out.png";

    int kernelSize = 0;
    float *filter = loadFilterFile(filterFileName, kernelSize);
    std::cout << getFilterIndex(filter, 1, 1, kernelSize) << std::endl;

    if (argc == OUTPUT_PASSED) {
        outputFileName = argv[3];
    }

    loadImage(argv[2]);
    /* Local image points to the image stored inside the vector */
    unsigned char *localImage = images[0];
    ImageSpec localSpec = specs[0];
    auto *modifiedImage = new float[localSpec.height * localSpec.width * localSpec.nchannels];

    /* Normalize Image */
    for (int i = 0; i < localSpec.height * localSpec.width * localSpec.nchannels; i++) {
        modifiedImage[i] = localImage[i] / 255.0;
    }

    /* Grab the scaleFactor for filter by summing up all the weights */
    float scaleFactor = 0.0;
    for (int i = 0; i < kernelSize; i++) {
        for (int j = 0; j < kernelSize; j++) {
            scaleFactor += abs(getFilterIndex(filter, i, j, kernelSize));
        }
    }
    /* TODO Filter needs to be divided by weight or it will NOT WORK*/
    /* TODO kernel needs to be flipped horizontally and vertically */
    /* TODO currently this will only work on 3x3 kernels */
    /* Here is the actual convolution. Currently it is pseudo code */
    for (int i = 0; i < localSpec.width; i++) {
        for (int j = 0; j < localSpec.height; j++) {
            /* Boundary protection. 1 came from 3/2 = 1 so theres -1 0 1 to account for 3x3 */
            if (i - 1 >= 0 && i + 1 < localSpec.width && j - 1 >= 0 && j + 1 < localSpec.height) {
                int x = 0;
                int y = 0;
                float newPixelValueR = 0.0;
                float newPixelValueG = 0.0;
                float newPixelValueB = 0.0;
                /* This creates a 3x3 square around each pixel that is within bounds */
                for (int z = i - 1; z <= i + 1; z++) {
                    for (int v = j - 1; v <= j + 1; v++) {
                        /* Grabs the filter for corresponding pixel */
                        float weight = getFilterIndex(filter, x, y, kernelSize) / scaleFactor;

                        /* Corresponding pixel location inside image (draws 3x3) */
                        int address = (v * localSpec.width + z) * localSpec.nchannels;

                        /* This is the corresponding R, G, B values. Preforms modification to each channel */
                        /* TODO Add up actual pixels * weight */
                        newPixelValueR += modifiedImage[address + 0] * weight;
                        newPixelValueG += modifiedImage[address + 1] * weight;
                        newPixelValueB += modifiedImage[address + 2] * weight;

                        /* General Algorithm for 3x3 Kernel. -(size/2) and add till == kernel size */
                        /* [i-1 j+1],[i j+1], [i+1 j+1]
                         * [i-1 j]   [i j  ]  [i+1 j]
                         * [i-1 j-1] [i j-1]  [i+1 j-1] */
                        y++;
                    }

                    /* Think of this as the nested j loop. Reset j to 0, increment i */
                    y = 0;
                    x++;
                }
                /* This is where the modified pixel will be changed */
                int address = (j * localSpec.width + i) * localSpec.nchannels;
                modifiedImage[address + 0] = newPixelValueR;
                modifiedImage[address + 1] = newPixelValueG;
                modifiedImage[address + 2] = newPixelValueB;
            }else{
                /* We went out of bounds, so color the image black on the pixels that went out of bounds */
                int address = (j * localSpec.width + i) * localSpec.nchannels;
                modifiedImage[address + 0] = 255;
                modifiedImage[address + 1] = 255;
                modifiedImage[address + 2] = 255;
            }
        }
    }

    /* denormalize the modified image and replace the previous image */
    for (int i = 0; i < localSpec.height * localSpec.width * localSpec.nchannels; i++) {
        modifiedImage[i] = modifiedImage[i] * 255.0;
        localImage[i] = (unsigned char) modifiedImage[i];
    }

    /* Time to apply convolution */
    /* Step 1: Divide filter weights by maximum scaleFactor (Scale factor) */
    /* Step 2: Chose boundary mechanism */
    /* Step 3: Clamp pixel values to be only positive [0,255] */

    //openGLSetup(argc, argv);
    writeImage(outputFileName);

    /* Clear memory inside the vector */
    for (auto &image : images) {
        delete image;
    }
    delete[] modifiedImage;
    return 0;
}

/* Handles all of openGL's init functions */
void openGLSetup(int argc, char *argv[]) {
    glutInit(&argc, argv);
    glutInitWindowPosition(0, 0);
    if (images.empty()) {
        glutInitWindowSize(900, 900);
    } else {
        glutInitWindowSize(specs[state].width, specs[state].height);
    }
    glutCreateWindow("My amazing window");
    glutDisplayFunc(displayFunction);
    glutReshapeFunc(reshapeFunction);
    glutKeyboardFunc(keyboardEvent);
    glutSpecialFunc(specialKeyboardEvent);
    glutMainLoop();
}

/* Required openGL function that handles image display */
void displayFunction() {
    glClearColor(0, 0, 0, 0);
    glRasterPos2i(0, 0);
    glWindowPos2i(0, 0);
    if (!images.empty()) {
        glDrawPixels(specs[state].width, specs[state].height, getImagePixelTypeForGL(), GL_UNSIGNED_BYTE,
                     images[state]);
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
            glDrawPixels(specs[state].width, specs[state].height, getImagePixelTypeForGL(), GL_UNSIGNED_BYTE,
                         images[state]);
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

/* OpenGL function for handling arrow keys + function keys */
void specialKeyboardEvent(int key, int x, int y) {
    switch (key) {
        case GLUT_KEY_LEFT: {
            std::cout << "Left " << state << std::endl;
            if (state == 0) {
                state = 0;
            } else {
                state--;
            }
            displayFunction();
            glDrawPixels(specs[state].width, specs[state].height, getImagePixelTypeForGL(), GL_UNSIGNED_BYTE,
                         images[state]);
            glFlush();
            break;
        }
        case GLUT_KEY_RIGHT: {
            std::cout << "Right " << state << std::endl;
            if (state == images.size() - 1) {
                state = 0;
            } else {
                state++;
            }
            displayFunction();
            glDrawPixels(specs[state].width, specs[state].height, getImagePixelTypeForGL(), GL_UNSIGNED_BYTE,
                         images[state]);
            glFlush();
            break;
        }
        default:
            break;
    }
}

/* Loads the image and allocates required memory. Also prints the image statistics
 * and assigns the global value spec to hold all required image info */
void loadImage(const std::string &inputFile) {
    unsigned char *pixels = nullptr;
    auto input = ImageInput::open(inputFile);
    if (!input) {
        std::cerr << "Error with file. " << geterror();
        exit(-1);
    }

    specs.push_back(input->spec());
    int pos = specs.size() - 1;

    /* TODO Special case for gray scale images */
    if (specs[pos].nchannels == 1) {
        int RGB = 3;
        auto *pixelsTemp = new unsigned char[specs[pos].width * specs[pos].height];
        input->read_image(TypeDesc::UINT8, pixelsTemp);
        pixels = new unsigned char[specs[pos].width * specs[pos].height * RGB];
        int j = 0;
        /* First run ensures j++ does not happen immediately */
        bool firstRun = true;
        for (int i = 0; i < specs[pos].width * specs[pos].height * RGB; i++) {
            if (i % 3 == 0 && !firstRun) {
                j++;
            }
            pixels[i] = pixelsTemp[j];
            firstRun = false;
        }
        images.push_back(pixels);
    } else {
        pixels = new unsigned char[specs[pos].width * specs[pos].height * specs[pos].nchannels];
        input->read_image(TypeDesc::UINT8, pixels);
        images.push_back(pixels);
    }

    std::string displayType;
    for (auto &channelName : specs[pos].channelnames) {
        displayType += channelName;
    }

    std::cout << "Image information: " << std::endl;
    std::cout << "X RES   " << specs[pos].width << std::endl;
    std::cout << "Y RES   " << specs[pos].height << std::endl;
    std::cout << "CHANNEL " << specs[pos].nchannels << std::endl;
    std::cout << "TYPE    " << displayType << std::endl;
    input->close();
}

float *loadFilterFile(const std::string &fileName, int &kernelSize) {
    std::ifstream file(fileName);
    if (!file) {
        std::cerr << "File read error" << std::endl;
        exit(1);
    }
    file >> (kernelSize);
    auto *weights = new float[kernelSize * kernelSize];
    /* Initialize Weight */
    for (int i = 0; i < kernelSize * kernelSize; i++) {
        weights[i] = -255;
    }

    float temp = 0;
    int iter = 0;
    while (file >> temp) {
        // file >> temp;
        if (iter == kernelSize * kernelSize) break;
        weights[iter] = temp;
        //  std::cout<<temp<<" ,";//<<std::endl;
        iter++;
    }
    return weights;
}

/* Writes the image */
void writeImage(const std::string &outputFile) {
    auto out = ImageOutput::create("Output.jpg");
    ImageSpec specOut;
    if (specs[state].nchannels == 1) {
        specOut = ImageSpec(specs[state].width, specs[state].height, specs[state].nchannels * 3, TypeDesc::UINT8);
    } else {
        specOut = ImageSpec(specs[state].width, specs[state].height, specs[state].nchannels, TypeDesc::UINT8);
    }
    out->open(outputFile, specOut);
    std::cout << state << std::endl;
    auto *val = images[state];
    out->write_image(TypeDesc::UINT8, val);
    out->close();
}

/* Inverts the image by just subtracting max pixel value by current pixel value */
void invertImage() {
    unsigned char maxVal = 255;
    for (int i = 0; i < (specs[state].width * specs[state].height * specs[state].nchannels); i++) {
        images[state][i] = maxVal - images[state][i];
    }
}

/* Determines what type of image was read in, and returns the OpenGL macro
 * that is used for displaying images */
int getImagePixelTypeForGL() {
    std::string mainString;
    for (auto &channelName : specs[state].channelnames) {
        mainString += channelName;
    }
    if (mainString == "RGB") {
        return GL_RGB;
    } else if (mainString == "RGBA") {
        return GL_RGBA;
    } else {
        return GL_RGB;
    }
}

float getFilterIndex(float *filter, int x, int y, int kernelSize) {
    return filter[y * kernelSize + x];
}