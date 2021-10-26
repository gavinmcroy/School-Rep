//
// Created by Gavin Taylor Mcroy on 10/26/21.
//

#include "Warp.h"

Warp::Warp() {
    std::cout<<"Warp constructor called"<<std::endl;
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

    // todo: populate the rotation matrix
    /*R[0][0] = ;
    R[0][1] = ;
    R[1][0] = ;
    R[1][1] = ;
    */

    M = R * M; //append the rotation to your transformation matrix
}
