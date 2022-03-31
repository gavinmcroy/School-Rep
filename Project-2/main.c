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
    runScheduler(scheduleNumber, head);
    //printFinalResult("FIFO scheduling results\n\n");

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
    int startLetter = 'A';
    while (fscanf(inFile, "%d %d", &arrival, &service) != EOF) {
        struct task *node = (struct task *) malloc(sizeof(struct task));
        node->arrival_time = arrival;
        node->service_time = service;
        node->task_id = startLetter;
        node->isProcessed = false;
        if (first) {
            head = node;
            temp = node;
            first = false;
        } else {
            temp->next = node;
            temp = node;
            node->next = NULL;
        }
        startLetter++;
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
void runScheduler(int schedule, struct task *head) {
    if (schedule == FIFO_SCHED) {
        FIFO(head);
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
    printf("%-6s %-4s %-6s %-6s (tid/rst)\n", "time", "cpu", "ready", "queue");
    printf("-------------------------------\n");
    printf("%3d %5s %5s\n", 0, "AB", "--");

    /* Second table template */
    printf("\n\n");
    printf("%14s %9s %12s %9s %5s", "arrival", "service", "completion", "response", "wait");
    printf("\n");
    printf("%-6s %-9s %-9s %-11s %-9s %-9s\n", "tid", "time", "time", "time", "time", "time");
    printf("--------------------------------------------------\n");

}

void FIFO(struct task *head) {
    /* We need to loop through all the work */
    int time = 0;
    for (struct task *begin = head; begin != NULL; begin = begin->next) {
        /* We have a task, we now are searching for its start time */
        bool startProcessing = false;
        int conditionCount = begin->service_time;
        /* This loop must break once the schedule is complete. We need to build a run queue */
        for (; time < INT_MAX; time++) {
            /* this prevents an extra new line in the beginning */
            if (time == 0) {
                printf("%d ", time);
            } else {
                printf("\n%d ", time);
            }
            /* is the time moment at which it arrives, service time is run length */

            /* Once our arrival times match we begin processing. TODO this is prone to bugs */
            if (begin->arrival_time <= time) {
                startProcessing = true;
            }

            /* We need to build a queue list for which tasks are queuing up */
            if (startProcessing) {
                /* Task then begins processing */
                begin->isProcessed = true;
                printf(" %c%d ", begin->task_id, conditionCount);

                /* We need to figure out what is getting queued up */
//                for (struct task *queue = begin; queue != NULL; queue = begin->next) {
//                    if (time >= queue->arrival_time && !queue->isProcessed) {
//                        printf("%c%d", queue->task_id, queue->service_time);
//                    }
//                }

                if (conditionCount == 1) {
                    startProcessing = false;
                    /* This is confusing to explain, but the loop will terminate before time is incremented.
                     * This ensures time is incremented even when the loop closes, since its counter must not
                     * be reset */
                    time++;
                    break;
                }
                conditionCount -= 1;
            }
        }
    }
}

void SJF() {

}

void RR() {

}
