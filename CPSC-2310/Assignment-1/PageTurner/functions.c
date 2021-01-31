#include "functions.h"


void howManyTurns(int size, int page) {
    /* TODO Implement Function */
}

void readData(FILE *in, int *totalPages, int *desiredPage) {
    fscanf(in,"%d %d",totalPages,desiredPage);
    printf("%d %d",*totalPages,*desiredPage);
    fclose(in);
}

void checkData(int totalPages, int desiredPage) {
    assert(totalPages > desiredPage);
}
