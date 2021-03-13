//
// Created by Gavin McRoy on 3/10/2021.
//
#include "functions.h"

void add(node_t **node, node_t **head) {

}

node_t *readNodeInfo(FILE *input) {
    node_t *node = (node_t *) malloc(sizeof(node_t));
    //fscanf(file,"%s,%s,%d,%d,%d,%s",name,lastName,&month,&day,&year,song);
    //fscanf(input, "%100[^,]s,%100[^,]s", node->firstName, node->lastName);
    //fscanf(input,"%[0-9]s",&node->birthday.month);
//    char buffer[100];
//    fscanf(input, "%s[^\n]", buffer);
//    int marker = 0;
//    for (int i = 0; i < strlen(buffer); i++) {
//        if(buffer[i]==','){
//            buffer[i]= ' ';
//        }
//    }
//    sscanf(buffer,"%s",node->firstName);

    fscanf(input, "%49[^,],%49[^,],%d,%d,%d, %499[^\n]\n", node->firstName, node->lastName, &(node->birthday.month),
           &node->birthday.day, &node->birthday.year, node->favoriteSong);

    printf("%s,%s,%d,%d,%d, %s", node->firstName, node->lastName, (node->birthday.month),
           node->birthday.day, node->birthday.year, node->favoriteSong);

    return node;
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

