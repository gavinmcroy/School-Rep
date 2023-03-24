/*	Grace Boccia
	CPSC 1111, Lab 005
	11/10/20 Fall 2020
	Lab 11
	This lab prints the width and height of an image

main.c file
	the main function uses command-line arguments 
	(notice the function signature)

	to run the program, type a.out and the image file name, such as:
		./main tiger.ppm

	use fprintf to stderr for printing any messages or values to the user

	the parseHeader() function is called from here		
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ppm.h"

void eatWS(FILE *inputFile) {
        char c;

        c = fgetc(inputFile); ungetc(c,inputFile);

        if( ('0' <= c) && (c <= '9')) return;
        do {c=fgetc(inputFile); } while(c!='\n');

}

void eatComments(FILE *inputFile) {
        char c;

        if((c=fgetc(inputFile))=='#') do{c=fgetc(inputFile);} while(c!='\n');
        else ungetc(c,inputFile);
}

int main(int argc, char *argv[]) {

	//Declaring Variables
	FILE	*inputFile;     // file pointer
//	long width, height;

	// if user only types the executable name and no other arguments, 
	// remind them to type the image file name also
	if (argc == 1) {
		fprintf(stderr, "<executable> <image_name>\n");
		exit(1);
	}

	// open the image file for reading
	// - - > fill in code here:
	inputFile = fopen(argv[1],"r");
	if (inputFile  == NULL) {
		fprintf(stderr, "File  open error. Exiting program\n");
		exit(1);
	}

	// get the width and height of the image and print values to user
	// - - > fill in code here:
	
	parseHeader(inputFile);
/*
	long width, height;
        char buff[256];

        fgets(buff, 256, inputFile);
        sscanf(&buff[2], "%li %li", &width, &height);

        while (height == 0){
                while (width == 0){
                eatWS(inputFile);
                eatComments(inputFile);
                fgets(buff, 256, inputFile);
                sscanf(&buff[0], "%li %li", &width, &height);
                }
        }
        fprintf(stderr, "\nwidth is %li, height is %li \n\n", width, height);
*/
  return 0;
}
