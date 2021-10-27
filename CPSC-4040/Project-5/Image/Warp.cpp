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


    /* pair.first denotes width, pair.second denotes height */
    std::pair<int, int> val = xY(1920, 1080);
    std::cout << val.first << " " << val.second << std::endl;
    std::pair<int, int> val1 = xY(1920, 0);
    std::cout << val1.first << " " << val1.second << std::endl;
    std::pair<int, int> val2 = xY(0, 1080);
    std::cout << val2.first << " " << val2.second << std::endl;
    std::pair<int, int> val3 = xY(0, 0);
    std::cout << val3.first << " " << val3.second << std::endl;
    std::cout<<"INVERSE: "<<u(val.first,val.second)<<std::endl;

    auto *warpedImage = new unsigned char[val.first * val.second * spec.nchannels];
    int width = val.first;
    int height = val.second;
    for (int x = 0; x < width; x++) {
        for (int y = 0; x < height; x++) {
            int address = (y * width + x) * spec.nchannels;
            int secondaryAddress = (u(x, y) * spec.width + v(x, y)) * spec.nchannels;
            /* RGB */
            warpedImage[address + 0] = image[secondaryAddress + 0];
            warpedImage[address + 1] = image[secondaryAddress + 1];
            warpedImage[address + 2] = image[secondaryAddress + 2];
        }
    }

    //transform four corners of image with forward transformation
    //generate image with enough space
    //calculate inverse transform by inverting final transformation matrix
    //warp image with inverse matrix (normalize image)
    //display transform




    return nullptr;
}
/* Given a x,y coordinate, it will return the new x,y location */
std::pair<int, int> Warp::xY(int x, int y) {
    double x1 = x * forwardMap[0][0] + x * forwardMap[0][1];
    double y1 = y * forwardMap[0][0] + y * forwardMap[0][1];
    /* Note. First denotes width, second denotes height */
    return std::make_pair<int, int>((int) round(x1), (int) round(y1));
}

/* Given the output image X,Y coordinate, it will give the original image location */
int Warp::u(int x, int y) {
    double x1 = x* inverseMap[0][0] + x*inverseMap[0][1];
    return (int) round(x1);
}

int Warp::v(int x, int y) {
    return 0;
}
