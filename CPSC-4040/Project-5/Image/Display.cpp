//
// Created by Gavin Taylor Mcroy on 10/26/21.
//

#include "Display.h"

Display::Display(int argc, char *argv[]) {
    if (argc > 1) {
        for (int i = 1; argv[i] != nullptr; i++) {
            loadImage(argv[i]);
        }
    }

    openGLSetup(argc, argv);

    /* Clear memory inside the vector */
    for (auto &image : images) {
        delete image;
    }
}

void Display::openGLSetup(int argc, char **argv) {
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

void Display::displayFunction() {
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

void Display::reshapeFunction(int x, int y) {

}

void Display::keyboardEvent(unsigned char key, int x, int y) {
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
            std::cin >> fileName;
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

void Display::specialKeyboardEvent(int key, int x, int y) {
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

void Display::loadImage(const std::string &inputFile) {
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

void Display::writeImage(const std::string &outputFile) {
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

void Display::invertImage() {
    unsigned char maxVal = 255;
    for (int i = 0; i < (specs[state].width * specs[state].height * specs[state].nchannels); i++) {
        images[state][i] = maxVal - images[state][i];
    }
}

int Display::getImagePixelTypeForGL() {
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
