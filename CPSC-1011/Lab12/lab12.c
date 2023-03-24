#include <stdio.h>
#include<stdlib.h>
#include<string.h>

/*
 *  lab12.c
 *  Author: Gavin McRoy
 *  Lecture, Lab Section: CPSC 1010-100, CPSC 1011-100-005
 *  Lab #: 12
 *  submitted on: 11/21/2019
 *  Purpose: Takes console input and finds if a number is abundant, deficient, or perfect
 *  Academic Honesty Declaration: * The following code represents my own
 *  work and I have neither received nor given assistance that violates
 *  the collaboration policy posted with this assignment. I have not copied
 *  or modified code from any other source other than the lab
 *  assignment, course textbook, or course lecture slides. Any unauthorized
 *  collaboration or use of materials not permitted will be subjected to
 *  academic integrity policies of Clemson University and CPSC 1010/1011.
 *  I acknowledge that this lab assignment is based upon an assignment
 *  created by Clemson University and that any publishing or
 *  posting of this code is prohibited unless I
 *  receive written permission from Clemson University.
 */

typedef struct LineData {
    int lineNum;
    int sumOfDivisors;
    char state[20];
} LineData;

int calculateDivisors(int num);

LineData *allocateMem(int size);

void initialize(LineData *data, int min, int max);

void printLineData(LineData *data, int size, char histogramChar);

int main(int argc, char *argv[]) {
    int min = 0;
    int max = 0;
    char histogramChar = ' ';

    sscanf(argv[1], "%d", &min);
    sscanf(argv[2], "%d", &max);
    sscanf(argv[3], "%c", &histogramChar);

    if (min < 2) {
        printf("Min is out of range\n");
        return 1;
    } else if (min >= max) {
        printf("Min is greater than or equal to max\n");
        return 1;
    }

    int size = max - min;

    LineData *data = allocateMem(size);

    if (data == NULL) {
        printf("Error in allocation of memory\n");
        return 1;
    }
    initialize(data, min, max);
    printLineData(data, size, histogramChar);

    free(data);
    return 0;
}

//---Properly allocates memory based on user input
LineData *allocateMem(int size) {
    LineData *data = (LineData *) malloc(sizeof(LineData) * (size + 1));
    if (data == NULL) {
        return NULL;
    }
    return data;
}

//---Initializes the array of structs
void initialize(LineData *data, int min, int max) {
    for (int i = 0; i <= max - min; i++) {
        data[i].sumOfDivisors = calculateDivisors(min + i);
        if (data[i].sumOfDivisors > min + i) {
            strcpy(data[i].state, "Abundant");
        } else if (data[i].sumOfDivisors < min + i) {
            strcpy(data[i].state, "Deficient");
        } else {
            strcpy(data[i].state, "Perfect");
        }
        data[i].lineNum = min + i;
    }
}

//---Returns sum of the divisors of any number passed in
int calculateDivisors(int num) {
    int sum = 0;
    for (int i = 1; i < num / 2 + 1; i++) {
        if (num % i == 0) {
            sum += i;
        }
    }
    return sum;
}

//---Loops through array and nicely prints data in each element
void printLineData(LineData *data, int size, char histogramChar) {
    for (int i = 0; i <= size; i++) {
        printf("%4d is %-10s ", data[i].lineNum, data[i].state);
        for (int j = 0; j < data[i].sumOfDivisors; j++) {
            printf("%c", histogramChar);
        }
        printf("\n");
    }
}