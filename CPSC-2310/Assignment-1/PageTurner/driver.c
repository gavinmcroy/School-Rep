#include <stdio.h>
#include <stdlib.h>
#include "functions.h"


int main(int argc, char *argv[]) {
    int numberOfPages = 0;
    int desiredPageToTurnToo = 0;

    if (argc < 2) {
        printf("Not enough command line arguments! Exiting the program!");
        exit(1);
    }

    FILE *inputFile = fopen(argv[1], "r");
    if (!inputFile) {
        printf("File did not open successfully! Exiting the program!");
        exit(1);
    }

    readData(inputFile, &numberOfPages, &desiredPageToTurnToo);
    checkData(numberOfPages, desiredPageToTurnToo);
    howManyTurns(numberOfPages, desiredPageToTurnToo);
}
