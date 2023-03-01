#include <stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<time.h>

/*
 *  flags.c
 *  Author: Gavin McRoy
 *  Lecture, Lab Section: CPSC 1010-100, CPSC 1011-100-005
 *  Lab #: 5
 *  submitted on: 9/26/2019
 *  Purpose: Simple rock paper scissors game that goes against a computer
 *  using random values
 *  work and I have neither received nor given assistance that violates
 *  the collaboration policy posted with this assignment. I have not copied
 *  or modified code from any other source other than the lab
 *  assignment, course textbook, or course lecture slides. Any unauthorized
 *  collaboration or use of materials not permitted will be subjected to
 *  academic integrity policies of Clemson University and CPSC 1010/1011.
 *  * I acknowledge that this lab assignment is based upon an assignment
 *  created by Clemson University and that any publishing or
 *  posting of this code is prohibited unless I
 *  receive written permission from Clemson University.
*/

void make_pixel(int r, int g, int b);

void make_ppm_header(int width, int height);

void make_ppm_image(int country_code, int width);

int row_count = 0;
int col_count = 0;

int main() {
    int width, country_code;
    srand(time(0));

    fprintf(stderr, "What country’s flag do you want to create? \n ");
    fscanf(stdin, "%d", &country_code);
    fprintf(stderr, "Enter width for the flag: \n");
    fscanf(stdin, "%d", &width);

    fprintf(stderr, "\nMaking country %d’s flag with width %d pixels... \n", country_code, width);
    row_count = width;
    col_count = width * 2 / 3;;
    make_ppm_header(row_count, col_count);
    make_ppm_image(country_code, width);

    fprintf(stderr, "Done!\n\n");
    return (0);
}

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
    //---Checkered Flag
    if (country_code == 1) {
        srand(time(0));
        int red = rand()%255;
        int green = rand()%255;
        int blue = rand()%255;
            for(int i = 0; i<row_count; i++){
                for(int j = 0; j<col_count; j++){
                    if(i%10==0 && j%10==0){
                        srand(time(0));
                        red = rand()%255;
                        green = rand()%255;
                        blue = rand()%255;
                    }
                    make_pixel(red,green,blue);
                }
        }
    }
}

