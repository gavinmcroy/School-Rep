#include <string.h>
#include <stdio.h>

int readFile(char filenameInput[]);

int writeFile(char filenameOutput[], int myCount);

int main(void) {
    char fileName[100] = "ce9.1.txt";
    int cnt = 0;

    printf("Enter file name to write:");
    scanf("%s", fileName);

    printf("\n");
    printf("How many lines to write [1-10]: ");
    scanf("%d", &cnt);
    if (writeFile(fileName, cnt) > 0) {
        printf("# of lines written: %d\n", cnt);
    }

    printf("Enter file name to read:");
    scanf("%s", fileName);
    printf("\n");
    cnt = readFile(fileName);

    if (cnt > 0) {
        printf("# of lines read: %d\n", cnt);
    }


    return 0;
}

int readFile(char filenameInput[]) {
    FILE *inFP;
    int cnt = 0;
    int len = 0;
    int num = 0;

    inFP = fopen(filenameInput, "r");
    if (inFP == NULL) {
        printf("Error: fopen() failed\n");
        return -1;
    }

    while (!feof(inFP)) {
        cnt++;
        len = fscanf(inFP, "%d", &num);
        if (len == 1) {
            printf("num: %d\n", num);
        }
    }

    fclose(inFP);

    return cnt;
}

int writeFile(char filenameOutput[], int myCount) {
    FILE *outFP;

    outFP = fopen(filenameOutput, "w");
    if (outFP == NULL) {
        printf("Error: fopen() failed W\n");
        return -1;
    }

    for (int i = 1; i < myCount; i++) {
        fprintf(outFP, "%d\n", i);
    }

    fclose(outFP);

    return 0;
}