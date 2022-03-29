#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void FIFO();

void SJF();

void RR();

/*  ./a.out <scheduling> <input> <outfile> */
int main(int args, char *argv[]) {
    const int EXPECTED_ARGS = 4;
    if (args < EXPECTED_ARGS) {
        exit(1);
    }

    //TODO Handle errors by asking user to re-enter CLA

    const char *FIFO = "-fifo";
    const char *SJF = "-sjf";
    const char *RR = "-rr";
    char *schedule = argv[1];
    char *inputFile = argv[2];
    char *outputFile = argv[3];

    if (strcmp(schedule, FIFO) == 0) {
        printf("FIFO \n");
    } else if (strcmp(schedule, SJF) == 0) {
        printf("SJF \n");
    } else if (strcmp(schedule, RR) == 0) {
        printf("RR \n");
    } else {
        fprintf(stderr, "Error invalid scheduling option\n");
        exit(1);
    }

    FILE *inFile = fopen(inputFile, "r+");
    FILE *outFile = fopen(outputFile, "w+");
    if (!inFile) {
        fprintf(stderr, "Error invalid input file\n");
        exit(1);
    } else if (!outFile) {
        fprintf(stderr, "Error invalid output file\n");
        exit(1);
    }

    fclose(inFile);
    fclose(outFile);
}

void FIFO() {

}

void SJF() {

}

void RR() {

}
