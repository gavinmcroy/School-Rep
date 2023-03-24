
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>

/*
 * if the desired page is past the half point in the book, then its faster to flip from the back.
 * if the calculation finds its a single page flip then print the non plural "page"
 * else print pages
 * else if the desired page is not past the half point in the book, then its faster to flip from the front
 * if the calculation finds its a single page flip then print the non plural "page"
 * else print pages
 * @param size - the total book pages
 * @param page - the desired page we want to flip to in the book
 * @return none
 */
void howManyTurns(int, int);

/*
 * reads the data in from a file. Stores data into both pointers  passed in. File must be successfully opened
 * before calling
 * @param in - the file we want to read data from
 * @param totalPages - the total book pages from the file
 * @param desiredPages - the desired page we want to flip through read from the file
 * @return none
 */
void readData(FILE *, int *, int *);

/*
 * Checks the data to make sure the desiredPage number is not greater than the total book pages. If so
 * program exits
 * @param totalPages - the total pages of the book
 * @param desiredPage - the page we want to flip to in the book
 * @return none
 */
void checkData(int, int);

#endif