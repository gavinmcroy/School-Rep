#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sched.h"

/*  ./a.out <scheduling> <input> <outfile> */
//TODO Handle errors by asking user to re-enter CLA
int main(int args, char *argv[]) {
    const int EXPECTED_ARGS = 4;
    struct task *head = NULL;
    if (args < EXPECTED_ARGS) {
        exit(1);
    }
    char *schedule = argv[1];
    char *inputFile = argv[2];
    char *outputFile = argv[3];

    int scheduleNumber = validScheduleName(schedule);
    if (!scheduleNumber) {
        exit(1);
    }

    loadInput(inputFile, head);
    //runScheduler(scheduleNumber);

}

/* Ensures proper schedule names are passed in. */
int validScheduleName(char *scheduleInput) {
    if (strcmp(scheduleInput, FIFO_NAME) == 0) {
        printf("FIFO_NAME \n");
        return 1;
    } else if (strcmp(scheduleInput, SJF_NAME) == 0) {
        printf("SJF_NAME \n");
        return 2;
    } else if (strcmp(scheduleInput, RR_NAME) == 0) {
        printf("RR_NAME \n");
        return 3;
    } else {
        fprintf(stderr, "Error invalid scheduling option. Did you include \"-\" (Ex. -fifo not fifo) \n");
        return 0;
    }
}

bool loadInput(char *in, struct task *list) {
    FILE *inFile = fopen(in, "r+");
    if (!inFile) {
        fprintf(stderr, "Error invalid input file\n");
        exit(1);
    }
    int x = 0;
    int y = 0;
    while (fscanf(inFile, "%d %d", &x, &y) != EOF) {
        //memory allocation shit
        printf("%d %d\n", x, y);
    }

    fclose(inFile);

    return true;
}

void FIFO() {

}

void SJF() {

}

void RR() {

}
