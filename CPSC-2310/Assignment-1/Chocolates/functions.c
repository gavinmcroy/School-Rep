//
// Created by Gavin McRoy on 1/31/2021.
//
#include "functions.h"

void Winner(int students, int sweets, int start, char **names) {
    /* Parallel array to keep track of who did not get chocolate */
    bool *whoDoesNotGetsChocolate = (bool *) malloc(sizeof(bool) * students);
    /* Initialize parallel array to all true */
    for (int i = 0; i < students; i++) {
        whoDoesNotGetsChocolate[i] = true;
    }
    while (sweets > 0) {
        /* loop the array back around when it goes out of bounds */
        if (start > students) {
            start = 1;
        }

        whoDoesNotGetsChocolate[start - 1] = false;
        start++;
        sweets--;
    }

    printf("The following student(s) did not receive chocolate! Maybe next time!!\n");
    for (int i = 0; i < students; i++) {
        if (whoDoesNotGetsChocolate[i] == true) {
            printf("%s\n", names[i]);
        }
    }
    free(whoDoesNotGetsChocolate);
}

char **readData(FILE *in, int *students, int *sweets, int *start) {
    int iterator = 0;
    int nameSize = 25;

    fscanf(in, "%d %d %d", students, sweets, start);

    /* Allocate memory for 2d array */
    char **names = (char **) malloc(sizeof(char *) * (*students));
    for (int i = 0; i < *students; i++) {
        names[i] = (char *) malloc(sizeof(char) * nameSize);
    }

    while (fscanf(in, "%s", names[iterator]) != EOF) {
        iterator++;
    }

    fclose(in);
    return names;
}


void printStudents(int s, char **n) {
    for (int i = 0; i < s; i++) {
        printf("%s\n", n[i]);
    }
}

void freeMemory(char **n, int s) {
    for (int i = 0; i < s; i++) {
        free(n[i]);
    }
    free(n);
}
