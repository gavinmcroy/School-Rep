#include <stdio.h>
#include "functions.h"

int main(int argc, char *argv[]) {
    int numberOfGrades = 0;
    checkArguments(argc);
    FILE *in = fopen(argv[1], "r");
    checkFile(in);
    int *arr = readData(in, &numberOfGrades);
    fclose(in);
    determineGrade(arr, numberOfGrades);
    printGrade(numberOfGrades, arr);
    calculatePercent(numberOfGrades, arr);

    return 0;
}
