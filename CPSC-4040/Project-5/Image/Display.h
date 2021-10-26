//
// Created by Gavin Taylor Mcroy on 10/26/21.
//

#ifndef OPEN_TEST_DISPLAY_H
#define OPEN_TEST_DISPLAY_H

#define GL_SILENCE_DEPRECATION
#define GL_DEFINE_TEXT

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

class Display {
private:
    int state = 0;
    std::vector<unsigned char *> images;
    std::vector<ImageSpec> specs;

public:
    Display(int argc,char * argv[]);

    void openGLSetup(int argc, char *argv[]);

    void displayFunction();

    void reshapeFunction(int x, int y);

    void keyboardEvent(unsigned char key, int x, int y);

    void specialKeyboardEvent(int key, int x, int y);

    void loadImage(const std::string &inputFile);

    void writeImage(const std::string &outputFile);

    void invertImage();

    int getImagePixelTypeForGL();
};


#endif //OPEN_TEST_DISPLAY_H
