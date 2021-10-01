//
// Created by Gavin Taylor Mcroy on 10/1/21.
//
#include <string>
#include <OpenImageIO/imageio.h>
#ifndef COMPOSITION_COMPOSITE_H
#define COMPOSITION_COMPOSITE_H

OIIO_NAMESPACE_USING

class Composite {
private:
    const int NO_OUTPUT_NAMED = 3;
    const int OUTPUT_NAMED = 4;
    const int ALPHA_CHANNEL = 4;
    std::string outFile;
    unsigned char * imageA;
    unsigned char * imageB;
    ImageSpec imageSpecA;
    ImageSpec imageSpecB;

    void readImage(char *argv[], int argc);

public:
    Composite(int argc, char* argv[]);

    void preformOperation();

    void outputFile();
};


#endif //COMPOSITION_COMPOSITE_H
