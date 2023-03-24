#include "functions.h"

void checkFile(FILE *input) {
    if (input == NULL) {
        printf("File did not open!!\n");
        exit(1);
    }
}

void checkArguments(int args) {
    if (args < 2) {
        printf("Not enough command line arguments!!\n");
        exit(1);
    }
}

void checkBraces(FILE *input) {
    int totalOpeningBraces = 0;
    int totalClosingBraces = 0;
    char myChar;
    /* while true, read characters one by one until end of file */
    while (1) {
        myChar = (char) fgetc(input);
        if (myChar == EOF) {
            break;
        } else if (myChar == '}') {
            if (totalOpeningBraces == 0) {
                printf("Found a '}' closing bracket before an '{' opening bracket!\n");
            } else {
                totalClosingBraces++;
            }
        } else if (myChar == '{') {
            totalOpeningBraces++;
        }
    }
    if (totalOpeningBraces - totalClosingBraces < 0) {
        printf("There were %d unmatched opening brackets.\n", 0);
    } else {
        printf("There were %d unmatched opening brackets.\n", totalOpeningBraces - totalClosingBraces);
    }
}
