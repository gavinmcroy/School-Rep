//
// Created by Gavin McRoy on 3/10/2021.
//
#include "functions.h"

void add(node_t **node, node_t **head) {

}

node_t *readNodeInfo(FILE *input) {
    node_t *node = (node_t *) malloc(sizeof(node_t));
//    char name[15];
//    char lastName[20];
//    int month;
//    int day;
//    int year;
//    char song[20];
    //fscanf(file,"%s,%s,%d,%d,%d,%s",name,lastName,&month,&day,&year,song);
    fscanf(input, "%100[^,]s,%100[^,]s", node->firstName, node->lastName);
    //fscanf(input,"%[0-9]s",&node->birthday.month);
    printf("%s %s %c %d", node->firstName, node->lastName, node->birthday.month, node->birthday.day);
}

node_t *createList(FILE *input, node_t **head) {

}

void PrintList(FILE *output, node_t *node) {

}

void PrintBDay(FILE *output, node_t *node) {

}

void Song(FILE *output, node_t *node) {

}

void printBorder(FILE *output) {

}

void print(void (*fp)(FILE *, node_t *), FILE *output, node_t *node) {

}

void checkArgs(int args) {

}

void checkFile(FILE *file, char *fileName) {
    //---Print using stderr
}

void deleteList(node_t **head) {

}

bool checkDate(bday_t birthday) {

}

bool isLeapYear(int year) {

}

