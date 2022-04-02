#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "sched.h"

/* Written by Gavin McRoy (gmcroy) */

/*  ./a.out <scheduling> <input> <outfile> */
char *inputFileName;
char *outputFileName;
FILE *outputFile;

int main(int args, char *argv[]) {
    const int EXPECTED_ARGS = 4;
    struct task *head = NULL;
    if (args < EXPECTED_ARGS) {
        fprintf(stderr,"Not enough arguments. Expected ./a.out <schedule> input.txt output.txt\n");
        exit(1);
    }else if(args > EXPECTED_ARGS){
        fprintf(stderr,"Too many arguments. Expected ./a.out <schedule> input.txt output.txt\n");
    }
    char *schedule = argv[1];
    inputFileName = argv[2];
    outputFileName = argv[3];

    int scheduleNumber = validScheduleName(schedule);
    if (!scheduleNumber) {
        exit(1);
    }

    head = loadInput(inputFileName);
    outputFile = saveFile(outputFileName);
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
        fprintf(stderr, "Error invalid input file name. Try again \n");
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
        node->addedToQueue = false;
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
FILE *saveFile(char *out) {
    FILE *open = fopen(out, "w+");
    if (!open) {
        fprintf(stderr, "Error file was unable to be created \n");
        exit(1);
    }
    return open;
}

/* TODO implement function (chooses which scheduler to run)*/
void runScheduler(int schedule, struct task *head) {
    if (schedule == FIFO_SCHED) {
        FIFO(head);
    } else if (schedule == SJF_SCHED) {
        SJF(head);
    } else if (schedule == RR_SCHED) {
        RR(head);
    }
}

//time  cpu ready queue (tid/rst)
void printFinalResult(char *scheduleName) {
    /* First table template */
    fprintf(outputFile, "%s", scheduleName);
    fprintf(outputFile, "%-6s %-4s %-6s %-6s (tid/rst)\n", "time", "cpu", "ready", "queue");
    fprintf(outputFile, "-------------------------------\n");
    fprintf(outputFile, "%3d %5s %5s\n", 0, "AB", "--");

    /* Second table template */
    fprintf(outputFile, "\n\n");
    fprintf(outputFile, "%14s %9s %12s %9s %5s", "arrival", "service", "completion", "response", "wait");
    fprintf(outputFile, "\n");
    fprintf(outputFile, "%-6s %-9s %-9s %-11s %-9s %-9s\n", "tid", "time", "time", "time", "time", "time");
    fprintf(outputFile, "--------------------------------------------------\n");

}

/* TODO Finish formatting */
void FIFO(struct task *head) {
    fprintf(outputFile, "FIFO scheduling results\n\n");
    fprintf(outputFile, "%-6s %-4s %-6s %-6s (tid/rst)\n", "time", "cpu", "ready", "queue");
    fprintf(outputFile, "-------------------------------------\n");
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
                fprintf(outputFile, "%-5d", time);
            } else {
                fprintf(outputFile, "\n%-5d", time);
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
                fprintf(outputFile, "%3c%d", begin->task_id, conditionCount);

                /* We need to figure out the queue list */
                bool didItPrint = false;
                bool appendComma = false;
                for (struct task *queue = begin; queue != NULL; queue = queue->next) {
                    if (queue->arrival_time <= time && !queue->isProcessed) {
                        if (appendComma) {
                            fprintf(outputFile, ",");
                        }
                        fprintf(outputFile, " %3c%d", queue->task_id, queue->service_time);
                        didItPrint = true;
                        appendComma = true;
                    }
                }
                /* This handles the dashes that go above the queue */
                if (!didItPrint) {
                    fprintf(outputFile, "%5s", "--");
                }

                if (conditionCount == 1) {
                    startProcessing = false;
                    /* This is confusing to explain, but the loop will terminate before time is incremented.
                     * This ensures time is incremented even when the loop closes, since its counter must not
                     * be reset */
                    begin->completion_time = time + 1;
                    time++;
                    break;
                }
                conditionCount -= 1;
            } else {
                fprintf(outputFile, "%9s", "--");
            }
        }
    }

    fprintf(outputFile, "\n\n");
    fprintf(outputFile, "%14s %9s %12s %9s %5s", "arrival", "service", "completion", "response", "wait");
    fprintf(outputFile, "\n");
    fprintf(outputFile, "%-6s %-9s %-9s %-11s %-9s %-9s\n", "tid", "time", "time", "time", "time", "time");
    fprintf(outputFile, "--------------------------------------------------\n");
    for (struct task *begin = head; begin != NULL; begin = begin->next) {
        begin->response_time = begin->completion_time - begin->arrival_time;
        begin->wait_time = begin->response_time - begin->service_time;
        fprintf(outputFile, "%-6c %-9d %-9d %-11d %-9d %-9d\n", begin->task_id, begin->arrival_time,
                begin->service_time,
                begin->completion_time, begin->response_time, begin->wait_time);
    }


    fprintf(outputFile, "\n \n%s %10s ", "service", "wait");
    fprintf(outputFile, "\n");
    fprintf(outputFile, "%5s %12s \n", "time", "time");
    fprintf(outputFile, "-------      ------\n");
    for (struct task *begin = head; begin != NULL; begin = begin->next) {
        fprintf(outputFile, "%4d %11d\n", begin->service_time, begin->wait_time);
    }

}

/* This is preemptive so this might take some creativity */
void SJF(struct task *head) {
    fprintf(outputFile, "SJF scheduling results\n\n");
    fprintf(outputFile, "%-6s %-4s %-6s %-6s (tid/rst)\n", "time", "cpu", "ready", "queue");
    fprintf(outputFile, "-------------------------------------\n");

    /* This is essentially an infinite loop */
    for (int time = 0; time < INT_MAX; time++) {
        /* if everything is finished, break */
        if (isFinished(head)) {
            break;
        }
        /* Solely for formatting */
        if (time == 0) {
            fprintf(outputFile, "  %-4d", time);
        } else {
            fprintf(outputFile, "\n  %-4d", time);
        }

        /* We find the shortest job */
        struct task *optimalJob = SJF_pickOptimalJob(time, head);

        /* We found an optimal job, so process one tick */
        if (optimalJob) {
            /* Print the id + service, and queued jobs behind it */
            fprintf(outputFile, "  %c%-3d", optimalJob->task_id, optimalJob->service_time);
            SJF_buildQueue(time, head, optimalJob);
            /* If this job is finished, mark it as finished, else tick by one */
            optimalJob->service_time--;
            if (optimalJob->service_time == 0) {
                optimalJob->completion_time = time + 1;
                optimalJob->isProcessed = true;
            }
        } else {
            fprintf(outputFile, "%9s", "--");
        }
    }

    /* Unfortunately the way I built my project, I need to reset the linked list. And build it from scratch
     * then print this table */
    cleanUp();
    struct task *head2 = loadInput(inputFileName);
    for (struct task *begin = head; begin != NULL; begin = begin->next) {
        begin->arrival_time = head2->arrival_time;
        begin->service_time = head2->service_time;
        head2 = head2->next;
    }


    fprintf(outputFile, "\n\n");
    fprintf(outputFile, "%14s %9s %12s %9s %5s", "arrival", "service", "completion", "response", "wait");
    fprintf(outputFile, "\n");
    fprintf(outputFile, "%-6s %-9s %-9s %-11s %-9s %-9s\n", "tid", "time", "time", "time", "time", "time");
    fprintf(outputFile, "--------------------------------------------------\n");
    for (struct task *begin = head; begin != NULL; begin = begin->next) {
        begin->response_time = begin->completion_time - begin->arrival_time;
        begin->wait_time = begin->response_time - begin->service_time;
        fprintf(outputFile, "%-6c %-9d %-9d %-11d %-9d %-9d\n", begin->task_id, begin->arrival_time,
                begin->service_time,
                begin->completion_time, begin->response_time, begin->wait_time);
    }

    fprintf(outputFile, "\n \n%s %10s ", "service", "wait");
    fprintf(outputFile, "\n");
    fprintf(outputFile, "%5s %12s \n", "time", "time");
    fprintf(outputFile, "-------      ------\n");
    for (struct task *begin = head; begin != NULL; begin = begin->next) {
        fprintf(outputFile, "%4d %11d\n", begin->service_time, begin->wait_time);
    }
}

/* When given start time, it will search for an optimal job, if no job is found returns null */
struct task *SJF_pickOptimalJob(int time, struct task *head) {
    /* Search the entire data structure */
    struct task *optimalJob = NULL;
    for (struct task *begin = head; begin != NULL; begin = begin->next) {
        /* This means a possible task has been found. But we must ensure it's the shortest task and unfinished */
        if (begin->arrival_time <= time && !begin->isProcessed) {
            /* We need to then ensure this job is optimal. */
            if (!optimalJob) {
                optimalJob = begin;
            }
            /* Locate the shortest service time */
            for (struct task *i = begin; i != NULL; i = i->next) {
                /* If a job is within the proper arrival time and its service time  is shorter, its optimal */
                if (i->arrival_time <= time && optimalJob->service_time > i->service_time && !i->isProcessed) {
                    optimalJob = i;
                }
            }
        }
    }
    return optimalJob;
}

/* TODO Queue not printing in correct order */
void SJF_buildQueue(int time, struct task *head, struct task *optimal) {
    optimal->addedToQueue = true;
    /* Search the entire data structure */
    bool addComma = false;
    bool addDash = true;
    for (struct task *begin = head; begin != NULL; begin = begin->next) {
        for (struct task *i = begin; i != NULL; i = i->next) {
            /* If a job is within the proper arrival time, not processed and not printed */
            if ((i->arrival_time <= time) && !i->isProcessed && !i->addedToQueue && (begin->service_time >=
                                                                                     i->service_time)) {
                if (addComma) {
                    fprintf(outputFile, ",");
                }
                fprintf(outputFile, "%2c%d", i->task_id, i->service_time);
                addComma = true;
                addDash = false;
                i->addedToQueue = true;
            }
        }
    }
    if (addDash) {
        fprintf(outputFile, " --");
    }

    /* We then reset everything back to out of the queue */
    for (struct task *begin = head; begin != NULL; begin = begin->next) {
        begin->addedToQueue = false;
    }
}


/* TODO go get lunch and implement round robin :D */
void RR(struct task *head) {
    fprintf(outputFile, "RR scheduling results\n\n");
    fprintf(outputFile, "%-6s %-4s %-6s %-6s (tid/rst)\n", "time", "cpu", "ready", "queue");
    fprintf(outputFile, "-------------------------------------\n");

    /* No matter what there is a passive ticking each iteration */
    int time = 0;
    bool ifQueuePrinted = false;
    bool cpuPrinted = false;
    for (; time < INT_MAX; time++) {
        if (isFinished(head)) {
            break;
        }

        if (time == 0) {
            fprintf(outputFile, "%3d", time);
        } else {
            fprintf(outputFile, "\n%3d", time);
        }

        bool secondPrint = false;
        for (struct task *begin = head; begin != NULL; begin = begin->next) {
            if (begin->arrival_time <= time && !begin->isProcessed) {
                if (secondPrint) {
                    time++;
                    fprintf(outputFile, "\n%3d%6c%d ", time, begin->task_id, begin->service_time);
                } else {
                    fprintf(outputFile, "%6c%d ", begin->task_id, begin->service_time);
                }
                cpuPrinted = true;

                ifQueuePrinted = RR_buildQueue(head, begin, time);

                begin->service_time--;
                if (begin->service_time == 0) {
                    begin->completion_time = time + 1;
                    begin->isProcessed = true;
                    break;
                }
                secondPrint = true;
            }
        }
        if (!cpuPrinted) {
            fprintf(outputFile, "%12s", "--");
        }

        if (!ifQueuePrinted && cpuPrinted) {
            fprintf(outputFile, "%4s", "--");
            cpuPrinted = false;
        }

    }

    cleanUp();
    struct task *head2 = loadInput(inputFileName);
    for (struct task *begin = head; begin != NULL; begin = begin->next) {
        begin->arrival_time = head2->arrival_time;
        begin->service_time = head2->service_time;
        head2 = head2->next;
    }


    fprintf(outputFile, "\n\n");
    fprintf(outputFile, "%14s %9s %12s %9s %5s", "arrival", "service", "completion", "response", "wait");
    fprintf(outputFile, "\n");
    fprintf(outputFile, "%-6s %-9s %-9s %-11s %-9s %-9s\n", "tid", "time", "time", "time", "time", "time");
    fprintf(outputFile, "--------------------------------------------------\n");
    for (struct task *begin = head; begin != NULL; begin = begin->next) {
        begin->response_time = begin->completion_time - begin->arrival_time;
        begin->wait_time = begin->response_time - begin->service_time;
        fprintf(outputFile,"%-6c %-9d %-9d %-11d %-9d %-9d\n", begin->task_id, begin->arrival_time, begin->service_time,
               begin->completion_time, begin->response_time, begin->wait_time);
    }

    fprintf(outputFile, "\n \n%s %10s ", "service", "wait");
    fprintf(outputFile, "\n");
    fprintf(outputFile, "%5s %12s \n", "time", "time");
    fprintf(outputFile, "-------      ------\n");
    for (struct task *begin = head; begin != NULL; begin = begin->next) {
        fprintf(outputFile, "%4d %11d\n", begin->service_time, begin->wait_time);
    }


}

bool RR_buildQueue(struct task *head, struct task *currentElement, int time) {
    struct task *temp = currentElement;
    bool firstRun = true;
    bool printedQueue = false;
    bool firstPrint = true;
    while (true) {
        /* This is how we know we are on the last element */
        if (currentElement == NULL) {
            currentElement = head;
        }

        if (currentElement->arrival_time <= time && !currentElement->isProcessed &&
            (currentElement->task_id != temp->task_id)) {
            if (firstPrint) {
                fprintf(outputFile,"%3c%d", currentElement->task_id, currentElement->service_time);
                firstPrint = false;
            } else {
                fprintf(outputFile,",%3c%d", currentElement->task_id, currentElement->service_time);
            }
            printedQueue = true;
        }

        /* We iterated through the entire list */
        if (currentElement->task_id == temp->task_id && !firstRun) {
            break;
        }
        currentElement = currentElement->next;
        firstRun = false;
    }
    return printedQueue;
}

/* this is how we break out the infinite loop, if all tasks are processed return false */
bool isFinished(struct task *head) {
    for (struct task *begin = head; begin != NULL; begin = begin->next) {
        /* if something is not processed, false */
        if (!begin->isProcessed) {
            return false;
        }
    }
    /* if everything is processed, true */
    return true;
}

/* if we want to destroy our data structure and reset as if the file was never read this is what we call */
void cleanUp() {

}