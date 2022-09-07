//
// Created by Gavin Taylor Mcroy on 10/26/21.
//

#ifndef OPEN_TEST_DISPLAY_H
#define OPEN_TEST_DISPLAY_H

#define GL_SILENCE_DEPRECATION
#define GL_DEFINE_TEXT

#include "Warp.h"

#ifdef __APPLE__

#include <OpenImageIO/imageio.h>
#include <GLUT/glut.h>
#include <OpenGL/gl.h>

#elif
#include <OpenImageIO/imageio.h>
#include <GL/glu.h>
#include <GL/gl.h>
#include <GL/glut.h>
#endif

OIIO_NAMESPACE_USING

void init(int argc, char *argv[]);

void openGLSetup(int argc, char *argv[]);

void loadImage(const std::string &inputFile);

void writeImage(const std::string &outputFile);

void invertImage();

int getImagePixelTypeForGL();

void displayFunction();

void reshapeFunction(int x, int y);

void keyboardEvent(unsigned char key, int x, int y);

void specialKeyboardEvent(int key, int x, int y);


#endif //OPEN_TEST_DISPLAY_H
