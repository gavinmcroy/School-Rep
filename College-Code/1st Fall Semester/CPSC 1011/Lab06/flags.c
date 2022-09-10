#include <stdio.h>
#include<stdbool.h>

void make_pixel(int r, int g, int b);

void make_ppm_header(int width, int height);

void make_ppm_image(int country_code, int width);

int row_count = 0;
int col_count = 0;

int main() {
    int width, country_code;

    fprintf(stderr, "What country’s flag do you want to create? \n ");
    fscanf(stdin, "%d", &country_code);
    fprintf(stderr, "Enter width for the flag: \n");
    fscanf(stdin, "%d", &width);

    fprintf(stderr, "\nMaking country %d’s flag with width %d pixels... \n", country_code, width);
    //---Setting a 2:3 Ratio for flags
    row_count = width;
    col_count = width * 2 / 3;;
    //---Creating header then processing image to output
    make_ppm_header(row_count, col_count);
    make_ppm_image(country_code, width);

    fprintf(stderr, "Done!\n\n");
    return (0);
}
//---Creates RGB Pixel 
void make_pixel(int r, int g, int b) {
    fprintf(stdout, "%c%c%c", r, g, b);
}

// Creates a header with the desired width and height when you call it
void make_ppm_header(int width, int height) {
    fprintf(stdout, "P6\n");
    fprintf(stdout, "%d %d %d\n", width, height, 255);
}

// Creates a complete ppm image when you call it
void make_ppm_image(int country_code, int width) {
    //---Poland Flag
    if (country_code == 1) {
        for (int i = 0; i < col_count; i++) {
            for (int j = 0; j < row_count; j++) {
                //---White Row
                if (i >= col_count / 2) {
                    make_pixel(255, 255, 255);
                }//---Red Row
                else {
                    make_pixel(255, 0, 0);
                }
            }
        }
    }
    //---Netherlands Flag
    if (country_code == 2) {
        bool first = true;
        for (int i = 0; i < col_count; i++) {
            for (int j = 0; j < row_count; j++) {
                //---Red Row
                if (i <= col_count / 3 && first) {
                    make_pixel(255, 0, 0);
                }//---White Row
                else if (i >= col_count / 3 && i <= col_count / 1.5) {
                    make_pixel(255, 255, 255);
                }//--Blue Row
                else {
                    make_pixel(0, 0, 255);
                }
            }
        }
    }
    //---Italian Flag
    if (country_code == 3) {
        for (int i = 0; i < col_count; i++) {
            for (int j = 0; j < row_count; j++) {
                //---Green Collumn
                if (j <= row_count / 3) {
                    make_pixel(0, 147, 70);
                }
                    //---White Collumn
                else if (j >= row_count / 3 && j <= row_count / 1.5) {
                    make_pixel(255, 255, 255);
                }
                    //---Red Collumn
                else {
                    make_pixel(216, 30, 5);
                }
            }
        }
    }
}
