#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sched.h"

/*  ./a.out <scheduling> <input> <outfile> */
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

    head = loadInput(inputFile);

    /* Testing linked list to ensure proper construction */
//    for (struct task *begin = head; begin != NULL; begin = begin->next) {
//        printf("%d %d\n", begin->arrival_time, begin->service_time);
//    }

    printFinalResult("FIFO scheduling results\n\n");
    //runScheduler(scheduleNumber);
    //saveFile(outputFile);

}

/* Ensures proper schedule names are passed in. */
int validScheduleName(char *scheduleInput) {
    if (strcmp(scheduleInput, FIFO_NAME) == 0) {
        //printf("FIFO_NAME \n");
        return FIFO_SCHED;
    } else if (strcmp(scheduleInput, SJF_NAME) == 0) {
        // printf("SJF_NAME \n");
        return SJF_SCHED;
    } else if (strcmp(scheduleInput, RR_NAME) == 0) {
        // printf("RR_NAME \n");
        return RR_SCHED;
    } else {
        fprintf(stderr, "Error invalid scheduling option. Did you include \"-\" (Ex. -fifo not fifo) \n");
        return 0;
    }
}

struct task *loadInput(char *in) {
    struct task *head = NULL;
    FILE *inFile = fopen(in, "r+");
    if (!inFile) {
        fprintf(stderr, "Error invalid input file\n");
        exit(1);
    }
    int arrival = 0;
    int service = 0;

    /* we build the link list and read in all the data */
    bool first = true;
    struct task *temp = NULL;
    while (fscanf(inFile, "%d %d", &arrival, &service) != EOF) {
        struct task *node = (struct task *) malloc(sizeof(struct task));
        node->arrival_time = arrival;
        node->service_time = service;
        if (first) {
            head = node;
            temp = node;
            first = false;
        } else {
            temp->next = node;
            temp = node;
            node->next = NULL;
        }
    }

    fclose(inFile);
    return head;
}

/* TODO implement function (prints final result to file in proper format) */
void saveFile(char *out) {
    FILE *open = fopen(out, "w+");
    fprintf(open, "testing output");
}

/* TODO implement function (chooses which scheduler to run)*/
void runScheduler(int schedule) {
    if (schedule == FIFO_SCHED) {
        FIFO();
    } else if (schedule == SJF_SCHED) {
        SJF();
    } else if (schedule == RR_SCHED) {
        RR();
    }
}

//time  cpu ready queue (tid/rst)
void printFinalResult(char *scheduleName) {
    /* First table template */
    printf("%s", scheduleName);
    printf("%-6s %-4s %-6s %-6s (tid/rst)\n","time","cpu","ready","queue");
    printf("-------------------------------\n");
    printf("%3d %5s %5s\n",0,"AB","--");

    /* Second table template */
    printf("\n\n");
    printf("%14s %9s %12s %9s %5s","arrival","service","completion","response","wait");
    printf("\n");
    printf("%-6s %-9s %-9s %-11s %-9s %-9s\n","tid","time","time","time","time","time");
    printf("--------------------------------------------------\n");

}

void FIFO() {

}

void SJF() {

}

void RR() {

}
