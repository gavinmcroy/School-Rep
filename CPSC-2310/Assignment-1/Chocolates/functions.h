//
// Created by Gavin McRoy on 1/31/2021.
//
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#ifndef CHOCOLATES_FUNCTIONS_H
#define CHOCOLATES_FUNCTIONS_H

/*
 * prints the number of students with a new line for each name
 * @param s - the total students to be printed
 * @param n - the block of memory holding the students names
 * @return none
 */
void printStudents(int, char **);

/*
 * Creates a parallel array of boolean variables, and determines if a student got a piece of candy or not.
 * Once the array runs out of bounds it circles back to the first student or index 0 in the array. If a student gets
 * chocolate there index in the array is set to false
 * @param students - the total students that could receive chocolate
 * @param sweets - the amount of chocolate available
 * @param start - the index of the first student who can pick there chocolate. Note that start is not 0 based meaning
 * that 1 actually represents names[0]
 * @param names - a pointer to a block of memory containing all the student names
 * @return none
 */
void Winner(int, int, int, char **);

/*
 * Reads data in and stores desired data into passed in parameters. Also allocates block
 * of memory for student names. Also closes in read in file so no need for fclose after function call
 * @param in - the file to be read in
 * @param students - the total number of students read in
 * @param sweets - the total amount of chocolates available
 * @param start - the first student who gets to pick a chocolate
 * @return - a pointer to a block of memory containing all the student names
 */
char **readData(FILE *, int *, int *, int *);

/*
 * Free the memory, first free the columns, then the rows
 * @param n - the 2D block of memory to be freed
 * @param s - the total columns that need to be freed
 * @return none
 */
void freeMemory(char **, int);


#endif //CHOCOLATES_FUNCTIONS_H
