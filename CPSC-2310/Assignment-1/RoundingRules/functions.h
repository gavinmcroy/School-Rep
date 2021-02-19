#include <stdio.h>
#include <stdlib.h>

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

/*
 * Reads data from a file, dynamically allocates and then stores read data into an array
 * @param file - the file to be read in. File must be successfully opened
 * @param numberOfGrades - the amount of memory to allocate / the total amount of grades to be read in
 * @return - a pointer to the array of memory storing the grades
 */
int *readData(FILE *, int *);

/*
 * Cycles through all the grades and determines if a grade is 3 away from the nearest multiple
 * of 5. If so, we check to make sure the grade is not less than 38. If the grade is not less than 38
 * than we round the grade up to the nearest multiple of 5. If it is less than 38 we just skip over to the
 * next element. Then we print out the percentage of students that benefited from the grade change
 * @param grades - a pointer to the array containing all the grades
 * @param numberOfGrades - the number of grades to be processed
 * @return none
 */
void determineGrade(int *, int);

/*
 * Prints all the grades out in one line
 * @param numberOfGrades - the total number of grades to be printed out
 * @param grades - a pointer to the array containing the grades
 * @return none
 */
void printGrade(int, int *);

/* Checks if the number of arguments passed in is valid. If there is not enough arguments
 * the program closes with a message stating theres not enough arguments
 * @param args - the number of arguments passed in through the command line
 * @return none
 */
void checkArguments(int);

/*
 * Determines if the file was successfully opened or failed to be opened. If the file failed
 * to open the program closes stating the file did not open successfully
 * @param none
 * @return none
 */
void checkFile(FILE *);

/*
 * Calculates the grade distribution (number of A's B's C's D's and F's), then prints out a graph
 * showing the distribution
 * @param numberOfGrades - the total number of grades to be analyzed
 * @param grades - a pointer to the array of data to be analyzed
 * @return none
 */
void calculatePercent(int, int *);

/*
 * Prints out the ascii character '*' a given number of times
 * @param value - the amount of times for '*' to be printed
 * @return none
 */
void printGraph(int);

#endif