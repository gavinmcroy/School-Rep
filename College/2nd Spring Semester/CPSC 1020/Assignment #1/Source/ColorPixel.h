//
// Created by Gavin Taylor Mcroy on 2/29/2020 AD.
//

#ifndef ASSIGNMENT_1_COLORPIXEL_H
#define ASSIGNMENT_1_COLORPIXEL_H


class ColorPixel {
private:
    int red;
    int green;
    int blue;
public:
    ColorPixel(int, int, int);
    ColorPixel();
    ~ColorPixel();

    int getRed();

    int getGreen();

    int getBlue();
};


#endif //ASSIGNMENT_1_COLORPIXEL_H
