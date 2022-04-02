//
// Created by Gavin T McRoy on 3/29/2022.
//
#include <stdbool.h>

#ifndef PROJECT_2_SCHED_H
#define PROJECT_2_SCHED_H

struct task {
    int task_id,    /* alphabetic tid can be obtained as 'A'+(task_counter++) */
    arrival_time,
            service_time,
            remaining_time,
            completion_time,
            response_time,
            wait_time;
    bool isProcessed;
    bool addedToQueue;
    struct task *next;
};

const char *FIFO_NAME = "-fifo";
const char *SJF_NAME = "-sjf";
const char *RR_NAME = "-rr";
const int FIFO_SCHED = 1;
const int SJF_SCHED = 2;
const int RR_SCHED = 3;

int validScheduleName(char *scheduleInput);

struct task *loadInput(char *in);

void saveFile(char *out);

void runScheduler(int schedule, struct task *head);

void printFinalResult();

void FIFO(struct task *head);

void SJF(struct task *head);

struct task * SJF_pickOptimalJob(int time,struct task * head);

void SJF_buildQueue(int time, struct task * head,struct task *optimal);

void RR(struct task *head);

void RR_buildQueue(struct task *head, struct task * currentElement, int time);

bool isFinished(struct task * head);

void cleanUp();


#endif //PROJECT_2_SCHED_H
