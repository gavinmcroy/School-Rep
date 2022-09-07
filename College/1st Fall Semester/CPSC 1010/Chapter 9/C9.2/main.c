#include <stdio.h>
#include<stdlib.h>

int writeFile(char filenameOutput[], int myCount);

FILE *readFile(char filenameInput[], int *mySize);

int *loadArray(FILE *inFP, int mySize);

int main() {
    int lines = 0;
    int mySize = -1;
    char fileName[30];

    printf("Enter file name: \n");
    scanf("%s", fileName);
    printf("How many lines to write [1-100]: ");
    scanf("%d", &lines);
    if (lines < 0 || lines > 100) {
        printf("Bad line count.\n");
        return 1;
    }

    int tmp = writeFile(fileName, lines);
    if (tmp == 1) {
        return 1;
    }
    FILE *file = readFile(fileName, &mySize);
    loadArray(file, mySize);
    return 0;
}

int writeFile(char filenameOutput[], int myCount) {
    FILE *fileOut = fopen(filenameOutput, "w");
    if (fileOut == NULL) {
        printf("Error: writeFile fopen() failed on file \"%s\".", filenameOutput);
        return 1;
    }
    fprintf(fileOut, "%d\n", myCount);
    for (int i = 1; i <= myCount; i++) {
        fprintf(fileOut, "%d\n", i);
    }
    fclose(fileOut);
    printf("File Written.\n");
    return 0;
}

FILE *readFile(char filenameInput[], int *mySize) {
    FILE *file = fopen(filenameInput, "r");
    if (file == NULL) {
        printf("Error: writeFile fopen() failed on file %s.", filenameInput);
        return NULL;
    }
    fscanf(file, "%d", mySize);
    printf("Read count: %d\n", *mySize);
    //fclose(file);
    return file;
}

int *loadArray(FILE *inFP, int mySize) {
    int i = 0;
    int *array = (int *) malloc(sizeof(int) * mySize);
    printf("Data read:\n");
    while (fscanf(inFP, "%d", &array[0]) == 1) {
        printf("[%d] = %d\n", i, array[0]);
        i++;
    }
    fclose(inFP);
    return array;
}