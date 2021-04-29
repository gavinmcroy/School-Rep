//
// Created by Gavin McRoy on 3/10/2021.
//
/****************************** /
* Gavin McRoy                 *
* CPSC2310 Spring 2021        *
* UserName: gmcroy            *
* Instructor:Dr. Yvon Feaster *
/ *****************************/

#ifndef ASSIGNMENT_2_FUNCTIONS_H
#define ASSIGNMENT_2_FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct MonthInfo {
    char month[20];
    int day;
} month_t;

typedef struct Birthday {
    int month;
    int day;
    int year;
} bday_t;

typedef struct Node {
    char firstName[20];
    char lastName[20];
    char favoriteSong[25];
    bday_t birthday;
    struct Node *next;
} node_t;

enum Month {
    January, February, March, April, May, June, July, August, September, October, November, December
};

void add(node_t **node, node_t **head);

node_t *readNodeInfo(FILE *input);

node_t *createList(FILE *, node_t **);

void PrintList(FILE *, node_t *);

void PrintName(FILE *output, node_t *node);

void PrintBDay(FILE *, node_t *);

void Song(FILE *, node_t *);

void printBorder(FILE *);

void print(void (*fp)(FILE *, node_t *), FILE *, node_t *);

void checkArgs(int);

void checkFile(FILE *, char *);

void deleteList(node_t **);

bool checkDate(bday_t);

/* ***************** */
void loadMonthInfo(FILE *input);
/* ***************** */

bool isLeapYear(int);

#endif //ASSIGNMENT_2_FUNCTIONS_H
