#include <stdio.h>

/*
 *  flags.c
 *  Author: Gavin McRoy
 *  Lecture, Lab Section: CPSC 1010-100, CPSC 1011-100-005
 *  Lab #: 11
 *  submitted on: 11/14/2019
 *  Purpose: Outputs images of 4 different flags (Poland,Netherlands,Italy,Benin)
 *  Academic Honesty Declaration: * The following code represents my own
 *  work and I have neither received nor given assistance that violates
 *  the collaboration policy posted with this assignment. I have not copied
 *  or modified code from any other source other than the lab
 *  assignment, course textbook, or course lecture slides. Any unauthorized
 *  collaboration or use of materials not permitted will be subjected to
 *  academic integrity policies of Clemson University and CPSC 1010/1011.
 *  I acknowledge that this lab assignment is based upon an assignment
 *  created by Clemson University and that any publishing or
 *  posting of this code is prohibited unless I
 *  receive written permission from Clemson University.
 */

typedef struct Pixel {
    int r;
    int g;
    int b;
} Pixel;

typedef struct Image {
    int width;
    int height;
    int country_code;
} Image;

void make_pixel(Pixel pixel);

void make_ppm_header(Image image);

void make_ppm_image(Image image);

Pixel get_color(int column, int row, Image image);

Image calculate_height(int width, int country_code);

void tmpDriver();

int validatedData(int width, int country_code);

int main() {
    tmpDriver();
    return 0;
}

void tmpDriver() {
    int width;
    int country_code;

    fprintf(stderr, "What country’s flag do you want to create? \n ");
    fscanf(stdin, "%d", &country_code);
    fprintf(stderr, "Enter width(in pixels) for the flag: \n");
    fscanf(stdin, "%d", &width);

    int tmp = validatedData(width, country_code);
    if (tmp == 1) {
        return;
    }

    fprintf(stderr, "\nMaking country %d’s flag with width %d pixels... \n", country_code, width);
    Image image = calculate_height(width, country_code);
    make_ppm_header(image);
    make_ppm_image(image);

    fprintf(stderr, "Done!\n\n");
}

//---Creates RGB Pixel
void make_pixel(Pixel pixel) {
    fprintf(stdout, "%c%c%c", pixel.r, pixel.g, pixel.b);
}

//---Creates a header with the desired width and height
void make_ppm_header(Image image) {
    fprintf(stdout, "P6\n");
    fprintf(stdout, "%d %d %d\n", image.width, image.height, 255);
}

//---draws a complete ppm image pixel by pixel to specified with and height
void make_ppm_image(Image image) {
    //---TODO should only draw the image based on data passed in
    Pixel pixel;
    for (int column = 0; column < image.height; column++) {
        for (int row = 0; row < image.width; row++) {
            pixel = get_color(column, row, image);
            make_pixel(pixel);
        }
    }
}

//---Determines what pixel to return for make_ppm_image so colors are accurately displayed
Pixel get_color(int column, int row, Image image) {
    Pixel pixel;
    //---Poland Flag
    if (image.country_code == 1) {
        //---White Row
        if (column >= image.height / 2) {
            pixel.r = 255;
            pixel.g = 255;
            pixel.b = 255;
        }
            //---Red Row
        else {
            pixel.r = 220;
            pixel.g = 20;
            pixel.b = 60;
        }
    }
        //---Netherlands Flag
    else if (image.country_code == 2) {
        //---Red Row
        if (column <= image.height / 3) {
            pixel.r = 174;
            pixel.g = 28;
            pixel.b = 40;
        }
            //---White Row
        else if (column >= image.height / 3 && column <= image.height / 1.5) {
            pixel.r = 255;
            pixel.g = 255;
            pixel.b = 255;
        }
            //--Blue Row
        else {
            //---33, 70, 139
            pixel.r = 33;
            pixel.g = 70;
            pixel.b = 139;
        }
    }
        //---Italy Flag
    else if (image.country_code == 3) {
        //---Green Column
        if (row <= image.width / 3) {
            pixel.r = 0;
            pixel.g = 140;
            pixel.b = 69;
        }
            //---White Column
        else if (row >= image.width / 3 && row <= image.width / 1.5) {
            pixel.r = 255;
            pixel.g = 255;
            pixel.b = 255;
        }
            //---Red Column
        else {
            pixel.r = 216;
            pixel.b = 30;
            pixel.g = 5;
        }
    }
        //---Benin flag
    else {
        if (row <= image.width * 6 / 15) {
            pixel.r = 34;
            pixel.g = 136;
            pixel.b = 72;
        } else if (row >= image.width * 6 / 15 && column <= image.height / 2) {
            //---253 218 36
            pixel.r = 253;
            pixel.g = 218;
            pixel.b = 36;
        } else {
            //---238 39 55
            pixel.r = 238;
            pixel.g = 39;
            pixel.b = 55;
        }
    }
    return pixel;
}

//---Calculates image ratio and sets the image country code
Image calculate_height(int width, int country_code) {
    Image image;
    image.width = width;
    //---Creates 2:3 Ratio
    image.height = width * 2 / 3;
    image.country_code = country_code;
    return image;
}


int validatedData(int width, int country_code) {
    if (width > 1920 || width < 1) {
        fprintf(stderr, "Error width is out of bounds\n");
        return 1;
    }
    if (country_code > 4 || country_code<1) {
        fprintf(stderr, "Error country code does not exist\n");
        return 1;
    }
    return 0;
}
