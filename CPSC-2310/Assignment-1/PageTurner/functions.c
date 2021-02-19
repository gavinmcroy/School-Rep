#include "functions.h"


void howManyTurns(int size, int page) {
    /* Means it is quicker to flip from back */
    if (page > (size / 2)) {
        int calculation = (size - page + 1) / 2;
        if (calculation == 1) {
            printf("%d page from the back\n", calculation);
        } else {
            printf("%d pages from the back\n", calculation);
        }
    } else {
        int calculation = page / 2;
        if (calculation == 1) {
            printf("%d page from the front\n", page / 2);
        } else {
            printf("%d pages from the front\n", page / 2);
        }
    }
}

void readData(FILE *in, int *totalPages, int *desiredPage) {
    fscanf(in, "%d %d", totalPages, desiredPage);
    //printf("%d %d\n", *totalPages, *desiredPage);
    fclose(in);
}

void checkData(int totalPages, int desiredPage) {
    if (desiredPage > totalPages) {
        printf("The total pages in the book is smaller than the page you are looking for!\n"
               "Exiting the program!");
        exit(1);
    }
}
