#include <iostream>

/* Declare a struct called pixels with 3 unsigned char values (r,g,b) */
struct pixel {
    unsigned char r, g, b;
};
/* Declare a pointer to a pointer of type pixmap */
pixel **pixmap;

/* Set up the width and height variables */
unsigned int W, H;

int main() {
    /* Allocate memory for our pixmap */
    pixmap = new pixel *[H];
    pixmap[0] = new pixel[W * H];

    /* Sets up the array indexes, such that [2][3] points to the correct part of the image */
    for (int i = 1; i < H; i++) {
        pixmap[i] = pixmap[i - 1] + W;
    }

    /* Invert the images colors */
    for (int row = 0; row < H; row++) {
        for (int col = 0; col < W; col++) {
            pixmap[row][col].r = 255 - pixmap[row][col].r;
            pixmap[row][col].g = 255 - pixmap[row][col].g;
            pixmap[row][col].b = 255 - pixmap[row][col].b;
        }
    }


    pixel *pixmap1, *pixmap2;
    unsigned int W1, H2;
    W1 = 200;
    H2 = 200;
    pixmap1 = new pixel[W1 * H2];
    pixmap2 = new pixel[W1 * H2];

    // . . . . assume we read some image file and stored it in pixmap1

    for (int row = 0; row < H2; row++)
        for (int col = 0; col < W1; col++) {
            pixmap2[col*W1 +row].r = pixmap1[(H2*(H2-row)) + col].g;
            pixmap2[col*W1 + row].g = pixmap1[(H2*(H2-row)) + col].g;
            pixmap2[col*W1 + row].b = pixmap1[H2*(H2-row) + col].b;
        }


}