#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

int main(int argc, char *argv[]) {
    int numStudentsAtTable = 0;
    int numChocolatesInBowl = 0;
    int whoGoesFirst = 0;
    char **names = NULL;

    if (argc < 1) {
        printf("Error not enough command line arguments");
        exit(1);
    }
    FILE *inputFile = fopen(argv[1], "r");
    if (!inputFile) {
        printf("Failed to open file");
        exit(1);
    }
    names = readData(inputFile, &numStudentsAtTable, &numChocolatesInBowl, &whoGoesFirst);
    //printStudents(numStudentsAtTable, names);
    Winner(numStudentsAtTable, numChocolatesInBowl, whoGoesFirst, names);
    freeMemory(names, numStudentsAtTable);

    return 0;
}
