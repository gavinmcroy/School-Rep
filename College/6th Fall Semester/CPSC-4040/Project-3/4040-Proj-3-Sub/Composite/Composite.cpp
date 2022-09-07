//
// Created by Gavin Taylor Mcroy on 10/1/21.
//
#include <iostream>
#include <OpenImageIO/imageio.h>
#include "Composite.h"

OIIO_NAMESPACE_USING

Composite::Composite(int argc, char *argv[]) {
    if (argc < 3) {
        std::cerr << "Not enough arguments" << std::endl;
        exit(-1);
    }
    if (argc == NO_OUTPUT_NAMED) {
        outFile = "out.png";
    } else if (argc == OUTPUT_NAMED) {
        outFile = argv[3];
    }
    readImage(argv, argc);

}

void Composite::readImage(char *argv[], int argc) {
    auto inputA = ImageInput::open(argv[1]);
    auto inputB = ImageInput::open(argv[2]);

    if (!inputA || !inputB) {
        std::cerr << "File open error" << std::endl;
    }

    imageSpecA = inputA->spec();
    imageSpecB = inputB->spec();
    imageA = new unsigned char[imageSpecA.height * imageSpecA.width * imageSpecA.nchannels];
    imageB = new unsigned char[imageSpecB.height * imageSpecB.width * imageSpecB.nchannels];
    inputA->read_image(TypeDesc::UINT8, imageA);
    inputB->read_image(TypeDesc::UINT8, imageB);

    if (imageSpecB.nchannels != ALPHA_CHANNEL) {
        std::cerr << "Warning background image does not contain alpha channel. Adding alpha to image" << std::endl;
        int secondaryCounter = 0;
        auto *temporary = new unsigned char[imageSpecB.width * imageSpecB.height * ALPHA_CHANNEL];
        for (int i = 0; i < imageSpecB.width * imageSpecB.height * ALPHA_CHANNEL; i++) {
            if (i % ALPHA_CHANNEL == 0) {
                temporary[i] = imageB[secondaryCounter];
                secondaryCounter++;
            } else if (i % ALPHA_CHANNEL == 1) {
                temporary[i] = imageB[secondaryCounter];
                secondaryCounter++;
            } else if (i % ALPHA_CHANNEL == 2) {
                temporary[i] = imageB[secondaryCounter];
                secondaryCounter++;
            }
                /* Alpha channel */
            else if (i % ALPHA_CHANNEL == 3) {
                temporary[i] = 255;
            }
        }
        delete[] imageB;
        imageB = temporary;
    }

    /* Check if mask is larger than background */
    if (imageSpecA.width > imageSpecB.width || imageSpecA.height > imageSpecB.height) {
        std::cerr << "Error masked image is larger than background which can cause undefined behavior";
        exit(-1);
    }


    inputA->close();
    inputB->close();
}

void Composite::preformOperation() {
    /* Actual A over B operation */
    //a_0 = A_a + A_b(1 - A_a)
    // C_0 = (C_a * A_a + C_b*A_b(1-A_a)) / A_0
    /* Its better to loop over the smaller image.*/
    finalImage = new unsigned char[imageSpecB.width * imageSpecB.height * imageSpecB.nchannels];
    double alphaA = imageA[3] / 255.0;
    double alphaB = imageB[3] / 255.0;
    double A0 = alphaA + (1 - alphaA) * alphaB;

    for (int i = 0; i < imageSpecA.width * imageSpecA.height * imageSpecA.nchannels; i++) {
        if (i % ALPHA_CHANNEL == 3) {
            alphaA = imageA[i] / 255.0;
            alphaB = imageB[i] / 255.0;
            A0 = ((alphaA) + (alphaB) * (1 - alphaA));
            finalImage[i] = (unsigned char) (A0 * 255.0);
            //finalImage[i] = 255;
        }

       // double colorPixel = ((((imageA[i] / 255.0) * alphaA) + ((imageB[i] / 255.0) * alphaB)) * (1 -alphaA)) / A0;

        double colorPixel = ((imageA[i] / 255.0) * alphaA) + (1-alphaA) * (imageB[i]/255.0); // ((imageB[i] / 255.0) * alphaB)) * (1 -alphaA)) / A0;
        auto temp = (unsigned char) (colorPixel * 255.0);
        finalImage[i] = temp;
    }
}

void Composite::outputFile() {
    ImageSpec outSpec = ImageSpec(imageSpecB.width, imageSpecB.height, ALPHA_CHANNEL, TypeDesc::UINT8);
    auto output = ImageOutput::create(outFile);
    output->open(outFile, outSpec);
    if (!output) {
        std::cerr << "Image write error" << std::endl;
    }
    output->write_image(TypeDesc::UINT8, finalImage);
    output->close();
    std::cout << "Image saved" << std::endl;

}
