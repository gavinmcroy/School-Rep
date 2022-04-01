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
void saveFile(char *out) {
    FILE *open = fopen(out, "w+");
    fprintf(open, "testing output");
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

/* TODO Finish formatting */
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
                printf(" %c%d", begin->task_id, conditionCount);

                /* We need to figure out the queue list */
                for (struct task *queue = begin; queue != NULL; queue = queue->next) {
                    if (queue->arrival_time <= time && !queue->isProcessed) {
                        printf(" %c%d", queue->task_id, queue->service_time);
                    }
                }

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

/* This is preemptive so this might take some creativity */
void SJF(struct task *head) {
    /* This is essentially an infinite loop */
    for (int time = 0; time < INT_MAX; time++) {
        /* if everything is finished, break */
        if (SJF_isFinished(head)) {
            break;
        }
        /* Solely for formatting */
        if (time == 0) {
            printf("%d", time);
        } else {
            printf("\n%d", time);
        }

        /* We find the shortest job */
        struct task *optimalJob = SJF_pickOptimalJob(time, head);

        /* We found an optimal job, so process one tick */
        if (optimalJob) {
            /* Print the id + service, and queued jobs behind it */
            printf(" %c%d", optimalJob->task_id, optimalJob->service_time);
            SJF_buildQueue(time, head, optimalJob);
            /* If this job is finished, mark it as finished, else tick by one */
            optimalJob->service_time--;
            if (optimalJob->service_time == 0) {
                optimalJob->isProcessed = true;
            }
        }
    }
}

/* this is how we break out the infinite loop, if all tasks are processed return false */
bool SJF_isFinished(struct task *head) {
    for (struct task *begin = head; begin != NULL; begin = begin->next) {
        /* if something is not processed, false */
        if (!begin->isProcessed) {
            return false;
        }
    }
    /* if everything is processed, true */
    return true;
}

/* When given start time, it will search for an optimal job, if no job is found returns null */
struct task *SJF_pickOptimalJob(int time, struct task *head) {
    /* Search the entire data structure */
    struct task *optimalJob = NULL;
    for (struct task *begin = head; begin != NULL; begin = begin->next) {
        /* This means a possible task has been found. But we must ensure it's the shortest task and unfinished */
        if (begin->arrival_time <= time && !begin->isProcessed) {
            /* We need to then ensure this job is optimal. */
            if(!optimalJob){
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

/* TODO Not printing in order */
void SJF_buildQueue(int time, struct task *head, struct task *optimal) {
    optimal->addedToQueue = true;
    /* Search the entire data structure */
    struct task *optimalJob = NULL;
    for (struct task *begin = head; begin != NULL; begin = begin->next) {
        /* This means a possible task has been found. But we must ensure it's the shortest task and unfinished */
        if (begin->arrival_time <= time && !begin->isProcessed) {
            /* We need to then ensure this job is optimal. */
            if(!optimalJob){
                optimalJob = begin;
            }
            /* Locate the shortest service time */
            for (struct task *i = begin; i != NULL; i = i->next) {
                /* If a job is within the proper arrival time, and not printed */
                if (i->arrival_time <= time && !i->isProcessed && !i->addedToQueue) {
                    printf(" %c%d", i->task_id, i->service_time);
                    i->addedToQueue = true;
                }
            }
        }
    }
    /* We then reset everything back to out of the queue */
    for (struct task *begin = head; begin != NULL; begin = begin->next) {
        begin->addedToQueue = false;
    }
}


/* TODO finish */
void RR(struct task *head) {

}

/* if we want to destroy our data structure and reset as if the file was never read this is what we call */
void cleanUp() {

}



//int time = 0;
//for (struct task *begin = head; begin != NULL; begin = begin->next) {
//// int temporaryStorage = begin->service_time;
//for (; time < INT_MAX; time++) {
///* If this particular task has no remaining work, end */
//if (begin->service_time == 0) {
//break;
//}
//
///* This is solely for formatting */
//if (time == 0) {
//printf("%d ", time);
//} else {
//printf("\n%d ", time);
//}
//
//
//if (begin->arrival_time <= time) {
//printf("%c%d", begin->task_id, begin->service_time);
//begin->service_time--;
//}
//
///* if finished break */
//}
//}