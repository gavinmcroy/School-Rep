/*	Grace Boccia
	CPSC 1111, Lab 005
	11/11/2020 Fall 2020
	Lab 11
	Function to obtain the width and height values
	
ppm.c file, will be used for PA3 and will contain:

	1. parseHeader() - - > this lab
		is called from the main() function
		gets cols & rows from the header of the image file

	2. getImage() function - - > for the assignment, NOT this lab
		gets the image data and puts into the 2-D array (of struct pixels)

	3. any other helper functions you may write for parsing the file 

	use fprintf to stderr for printing any messages or values to the user
		
*/ 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "ppm.h"

// parseHeader() function goes here:
/*
void eatWS(FILE *inputFile) {
        char c;

        c = fgetc(inputFile); ungetc(c,inputFile);

        if( ('0' <= c) && (c <= '9')) return;
        do {c=fgetc(inputFile); } while(c!='\n');

}
/Users/gavintaylormcroy/Desktop/ppm.c
void eatComments(FILE *inputFile) {
        char c;

        if((c=fgetc(inputFile))=='#') do{c=fgetc(inputFile);} while(c!='\n');
        else ungetc(c,inputFile);
}
*/
void parseHeader(FILE *inputFile) {

	long width=0, height=0;
	char buff[256];
	char c = ' ';

	fgets(buff, 256, inputFile);
        sscanf(&buff[2], "%li %li", &width, &height);

        while (height == 0){
                while (width == 0){
                //eatWS(inputFile);
	        c = fgetc(inputFile); ungetc(c,inputFile);
        	if( ('0' <= c) && (c <= '9')) return;
        	do {c=fgetc(inputFile); } while(c!='\n');

                //eatComments(inputFile);
	if((c=fgetc(inputFile))=='#') do{c=fgetc(inputFile);} while(c!='\n');
        else ungetc(c,inputFile);

                fgets(buff, 256, inputFile);
                sscanf(&buff[0], "%li %li", &width, &height);
                }
        }
        fprintf(stderr, "\nwidth is %li, height is %li \n\n", width, height);

}
