//
// Created by Gavin Taylor Mcroy on 10/26/21.
//

#include "Warp.h"

Warp::Warp() {
    std::cout << "Warp constructor called" << std::endl;
}

/*  • read an input image from an image file
    • input a sequence of matrix specifications
    • multiply these matrices as you go to get a final transform matrix from all of the specified
      matrices
*/
void Warp::inputSequence(Matrix3D &M) {
    std::string cmd;
    /* prompt for user input */
    do {
        std::cout << "> ";
        std::cin >> cmd;
        if (cmd.length() != 1) {
            std::cout << "invalid command, enter r, s, t, h, f, p, d\n";
        } else {
            switch (cmd[0]) {
                case 'r':        /* Rotation, accept angle in degrees */
                    float theta;
                    std::cin >> theta;
                    if (std::cin) {
                        std::cout << "calling rotate\n";
                        rotate(M, theta);
                    } else {
                        std::cerr << "invalid rotation angle\n";
                        std::cin.clear();
                    }
                    break;
                case 's':        /* scale, accept scale factors */
                    break;
                case 't':        /* Translation, accept translations */
                    break;
                case 'h':        /* Shear, accept shear factors */
                    break;
                case 'f':        /* Flip, accept flip factors */
                    break;
                case 'p':        /* Perspective, accept perspective factors */
                    break;
                case 'd':        /* Done, that's all for now */
                    break;
                default:
                    std::cout << "invalid command, enter r, s, t, h, f, p, d\n";
            }
        }
    } while (cmd.compare("d") != 0);
}

void Warp::rotate(Matrix3D &M, float theta) {
    Matrix3D R;  // this initializes R to identity
    double rad = PI * theta / 180.0; // convert degrees to radians

    /* todo: populate the rotation matrix
    R[0][0] = ;
    R[0][1] = ;
    R[1][0] = ;
    R[1][1] = ;
    */

    M = R * M; //append the rotation to your transformation matrix
}

unsigned char *Warp::preformWarp(unsigned char *image, const ImageSpec &spec) {
    /* Essentially we are going to create our own local transformation */
    /* Shear */
    originalImage = image;
    double shear[3][3];
    shear[0][0] = 1;
    shear[0][1] = .5;
    shear[0][2] = 0;
    shear[1][0] = .5;
    shear[1][1] = 1;
    shear[1][2] = 0;
    shear[2][0] = 0;
    shear[2][1] = 0;
    shear[2][2] = 1;
    forwardMap = Matrix3D(shear);
    inverseMap = forwardMap.inverse();
    /* Transform 4 corners of image pair.first denotes width, pair.second denotes height */
    newImageResolution = toForwardMap(spec.width, spec.height);

    std::cout << "NEW RES: " << newImageResolution.first << " " << newImageResolution.second << std::endl;
    currentImageRes = u(newImageResolution.first, newImageResolution.second);
    std::cout << "INVERSE: X " << currentImageRes.first << " Y: " << currentImageRes.second << std::endl;

    /* Generate image with enough space */
    warpedImage = new unsigned char[newImageResolution.first * newImageResolution.second * spec.nchannels];
    int width = newImageResolution.first;
    int height = newImageResolution.second;

    /* Generate inverse matrix */

    /* Actual image warping */
    for (int x = 0; x < width; x++) {
        for (int y = 0; y < height; y++) {
            //return pixels(x + W*y);
            int address = (y * width + x) * spec.nchannels;
            std::pair<int, int> map = currentImageRes;
            /* (y * width + x) *specnChannels */
            int secondaryAddress = (map.second * spec.width + map.first) * spec.nchannels;

            /* RGB */
            warpedImage[address + 0] = image[secondaryAddress + 0];
            warpedImage[address + 1] = image[secondaryAddress + 1];
            warpedImage[address + 2] = image[secondaryAddress + 2];
        }
    }

    /* Display */

    /* transform four corners of image with forward transformation
     * generate image with enough space
     * calculate inverse transform by inverting final transformation matrix
     * warp image with inverse matrix (normalize image)
     * Display transform */

    return warpedImage;
}

/* Given a x,y coordinate, it will return the new x,y location */
std::pair<int, int> Warp::toForwardMap(int x, int y) {
    double x1 = x * forwardMap[0][0] + y * forwardMap[0][1] + 1 * inverseMap[0][2];
    double y1 = x * forwardMap[1][0] + y * forwardMap[1][1] + 1 * inverseMap[1][2];
    /* Note. First denotes width, second denotes height */
    return std::make_pair<int, int>((int) round(x1), (int) round(y1));
}

/* Given the output image X,Y coordinate, it will give the original image location */
std::pair<int, int> Warp::u(int x, int y) {
    double x1 = x * inverseMap[0][0] + y * inverseMap[0][1] + 1 * inverseMap[0][2];
    double y1 = x * inverseMap[1][0] + y * inverseMap[1][1] + 1 * inverseMap[1][2];
    return std::make_pair<int, int>((int) round(x1), (int) round(y1));
}

void Warp::writeImage() {
    std::string outFile = "Outfile.jpg";
    auto out = ImageOutput::create(outFile);
    ImageSpec specOut;
    //specOut = ImageSpec(newImageResolution.first, newImageResolution.second, 3, TypeDesc::UINT8);
    specOut = ImageSpec(currentImageRes.first,currentImageRes.second,3,TypeDesc::UINT8);
    out->open(outFile, specOut);
    out->write_image(TypeDesc::UINT8, originalImage);
    out->close();
}


//    std::pair<int, int> val1 = xY(1920, 0);
//    std::cout << val1.first << " " << val1.second << std::endl;
//    std::pair<int, int> val2 = xY(0, 1200);
//    std::cout << val2.first << " " << val2.second << std::endl;
//    std::pair<int, int> val3 = xY(0, 0);
//    std::cout << val3.first << " " << val3.second << std::endl;
/* Inverse system works */