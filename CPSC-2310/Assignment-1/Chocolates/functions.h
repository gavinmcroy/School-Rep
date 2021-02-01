//
// Created by Gavin McRoy on 1/31/2021.
//
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#ifndef CHOCOLATES_FUNCTIONS_H
#define CHOCOLATES_FUNCTIONS_H

void printStudents(int, char **);

void Winner(int, int, int, char **);

char **readData(FILE *, int *, int *, int *);

void freeMemory(char **, int);


#endif //CHOCOLATES_FUNCTIONS_H
