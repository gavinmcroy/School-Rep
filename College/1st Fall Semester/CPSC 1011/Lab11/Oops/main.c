#include <stdio.h>

typedef struct Pixel {
    int r;
    int g;
    int b;
} Pixel;

//---TODO Figure out how to incorperate image struct
typedef struct Image {
    int width;
    int height;
    int country_code;
} Image;

void make_pixel(Pixel pixel);

void make_ppm_header(Image image);

void make_ppm_image(int country_code, int col_count, int row_count);

void make_poland_flag(int col_count, int row_count);

void make_italy_flag(int col_count, int row_count);

void make_netherlands_flag(int col_count, int row_count);

void make_benin_flag(int col_count,int row_count);

//---TODO what is this
Pixel get_color(int column,int row,Image image);

//Pixel get_color_poland(int row);
//
//Pixel get_color_netherlands(int row);
//
//Pixel get_color_italy(int column);

Image calculate_height(int width, int country_code);

//---TODO Remove TMP Driver
void tmpDriver(void);

int main() {
    tmpDriver();
}

void tmpDriver(void) {
    int width, country_code, col_count, row_count;

    fprintf(stderr, "What country’s flag do you want to create? \n ");
    fscanf(stdin, "%d", &country_code);
    fprintf(stderr, "Enter width for the flag: \n");
    fscanf(stdin, "%d", &width);

    fprintf(stderr, "\nMaking country %d’s flag with width %d pixels... \n", country_code, width);

    Image flagImage = calculate_height(width,country_code);

    //---Setting a 2:3 Ratio for flags

    //---Creating header then processing image to output
    make_ppm_header(row_count, col_count);
    make_ppm_image(country_code, col_count, row_count);

    fprintf(stderr, "Done!\n\n");
}

//---Creates RGB Pixel
void make_pixel(Pixel pixel) {
    fprintf(stdout, "%c%c%c", pixel.r, pixel.g, pixel.b);
}

// Creates a header with the desired width and height when you call it
void make_ppm_header(Image image) {
    fprintf(stdout, "P6\n");
    fprintf(stdout, "%d %d %d\n", width, height, 255);
}

// Creates a complete ppm image when you call it
void make_ppm_image(int country_code, int col_count, int row_count) {
    //---TODO should not contain logic to determine the color of pixel to print
    //---Poland Flag
    if (country_code == 1) {
        make_poland_flag(col_count, row_count);
    }
    //---Netherlands Flag
    if (country_code == 2) {
        make_netherlands_flag(col_count, row_count);
    }
    //---Italian Flag
    if (country_code == 3) {
        make_italy_flag(col_count, row_count);
    }
    if (country_code == 4) {
        //---TODO incorporate benin flag
    }
}

void make_poland_flag(int col_count, int row_count) {
    for (int i = 0; i < col_count; i++) {
        for (int j = 0; j < row_count; j++) {
            //---White Row
            if (i >= col_count / 2) {
                make_pixel(get_color_poland(0));
            }//---Red Row
            else {
                make_pixel(get_color_poland(1));
            }
        }
    }
}

void make_netherlands_flag(int col_count, int row_count) {
    for (int i = 0; i < col_count; i++) {
        for (int j = 0; j < row_count; j++) {
            //---Red Row
            if (i <= col_count / 3 /*&& first*/) {
                make_pixel(get_color_netherlands(0));
            }//---White Row
            else if (i >= col_count / 3 && i <= col_count / 1.5) {
                make_pixel(get_color_netherlands(1));
            }//--Blue Row
            else {
                make_pixel(get_color_netherlands(2));
            }
        }
    }
}

void make_italy_flag(int col_count, int row_count) {
    for (int i = 0; i < col_count; i++) {
        for (int j = 0; j < row_count; j++) {
            //---Green Column
            if (j <= row_count / 3) {
                make_pixel(get_color_italy(0));
            }
                //---White Column
            else if (j >= row_count / 3 && j <= row_count / 1.5) {
                make_pixel(get_color_italy(1));
            }
                //---Red Column
            else {
                make_pixel(get_color_italy(2));
            }
        }
    }
}

void make_benin_flag(int col_count,int row_count){

}

Pixel get_color_poland(int row) {
    Pixel pixel;
    if (row == 0) {
        pixel.r = 255;
        pixel.g = 0;
        pixel.b = 0;
        return pixel;
    } else {
        pixel.r = 255;
        pixel.g = 255;
        pixel.b = 255;
        return pixel;
    }
}

Pixel get_color_netherlands(int row) {
    Pixel pixel;
    if (row == 0) {
        pixel.r = 255;
        pixel.g = 0;
        pixel.b = 0;
        return pixel;
    } else if (row == 1) {
        pixel.r = 255;
        pixel.g = 255;
        pixel.b = 255;
        return pixel;
    } else {
        pixel.r = 0;
        pixel.g = 0;
        pixel.b = 255;
        return pixel;
    }
}

Pixel get_color_italy(int column) {
    Pixel pixel;
    if (column == 0) {
        pixel.r = 0;
        pixel.g = 147;
        pixel.b = 70;
        return pixel;
    } else if (column == 1) {
        pixel.r = 255;
        pixel.g = 255;
        pixel.b = 255;
        return pixel;
    } else {
        pixel.r = 216;
        pixel.g = 30;
        pixel.b = 5;
        return pixel;
    }
}

Image calculate_height(int width, int country_code) {
    Image image;
    image.width = width;
    image.height = width * 2 / 3;
    image.country_code = country_code;
    return image;
}
