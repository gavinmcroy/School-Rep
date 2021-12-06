#include <string>
#include <iostream>
#include <OpenImageIO/imageio.h>
#include <GLUT/glut.h>

#ifndef FINAL_PROJECT_CARTOON_H
#define FINAL_PROJECT_CARTOON_H

OIIO_NAMESPACE_USING


struct Pixel {
    unsigned char r;
    unsigned char g;
    unsigned char b;
    [[maybe_unused]] unsigned char a;
};

/* OpenGL Operators */

void handleDisplay();

void handleKey(unsigned char key, int x, int y);

void handleReshape(int w, int h);

void displayImage();

void runMainLoop(int argc, char *argv[]);

/* Bilateral Information */
double clamp(double lo, double hi, double x);

double clamp(int lo, int hi, int x);

void intensityImage();

void getRange(int i, int j);

void domainRange();

void applyIntensityKernel(int y, int x);

void applyBilateralFilter();

/* Sobel operators */

void flipKernel(double kernelTemp[][3]);

void setKernel(double matrixTemp[][3]);

void applyKernel(Pixel **pixel, Pixel **tempPixel, double matrixTemp[][3], int y, int x);

void convolveImage(Pixel **pixmapTemp, double matrixTemp[][3]);

double calculateSobel(double colorH, double colorV);

void combineImg();

void combineBilateralSobel();

void destroy();

int readImage(const std::string &inFileName);

void writeImage(const std::string &out);

#endif //FINAL_PROJECT_CARTOON_H
