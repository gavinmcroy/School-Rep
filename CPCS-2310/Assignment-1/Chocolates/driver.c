#include "functions.h"

/* Malloc error inside functions */

int main(int argc, char *argv[]) {
    int numStudentsAtTable = 0;
    int numChocolatesInBowl = 0;
    int whoGoesFirst = 0;
    char **names = NULL;

    if (argc < 2) {
        printf("Not enough command line arguments! Exiting the program!\n");
        exit(1);
    }
    FILE *inputFile = fopen(argv[1], "r");
    if (!inputFile) {
        printf("File did not open successfully! Exiting the program!\n");
        exit(1);
    }

    names = readData(inputFile, &numStudentsAtTable, &numChocolatesInBowl, &whoGoesFirst);
    printStudents(numStudentsAtTable, names);
    Winner(numStudentsAtTable, numChocolatesInBowl, whoGoesFirst, names);
    //freeMemory(names, numStudentsAtTable);

    return 0;
}
