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
    struct task *next;
};

const char *FIFO_NAME = "-fifo";
const char *SJF_NAME = "-sjf";
const char *RR_NAME = "-rr";

int validScheduleName(char * scheduleInput);

bool loadInput(char * in, struct task * list);

void FIFO();

void SJF();

void RR();


#endif //PROJECT_2_SCHED_H
