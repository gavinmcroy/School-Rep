#include <string>
#include <iostream>
#include <OpenImageIO/imageio.h>
#include <GLUT/glut.h>

#ifndef FINAL_PROJECT_CARTOON_H
#define FINAL_PROJECT_CARTOON_H

OIIO_NAMESPACE_USING


struct Pixel { // defines a pixel structure
    unsigned char r;
    unsigned char g;
    unsigned char b;
    [[maybe_unused]] unsigned char a;
};

/* Bilateral Information */
double clamp(double lo, double hi, double x);

double clamp(int lo, int hi, int x);

void intensityImg();

void getRange(int i, int j);

void domainRange();

void applyIntensityKernel(int y, int x);

void applyBilateralFilter();

/* Sobel operators */

void print();

void flipKernel(double **kernelTemp);

void setKernel(double matrixTemp[][3]);

void applyKernel(Pixel **pix, Pixel **temp_pixel, double matrixTemp[][3], int y, int x);

void convolveImage(Pixel **pixmapTemp, double matrixTemp[][3]);

double calculateSobel(double colorH, double colorV);

void combineImg();

void combineBilateralSobel();

void destroy();

int readImage(const std::string &inFileName);

void writeImage(const std::string &out);

void handleDisplay();

void handleKey(unsigned char key, int x, int y);

void handleReshape(int w, int h);

void displayimage();

void runMainLoop(int argc, char *argv[]);

#endif //FINAL_PROJECT_CARTOON_H
