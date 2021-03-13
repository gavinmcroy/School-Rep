//
// Created by Gavin McRoy on 3/10/2021.
//
#include "functions.h"

const char MONTH_NAMES[12][20] = {"January", "February", "March", "April", "May", "June", "July", "August", "September",
                             "October", "November", "December"};

void add(node_t **node, node_t **head) {
    //---node is what is going to be added and head is the head pointer
    if (head == NULL) {
        fprintf(stderr, "Error in Adding Node. HEAD is NULL\n");
        exit(1);
    }
    //Loop to the last node. Node1 should equal the last node
    node_t *node1;
    int i = 0;
    for (node1 = *(head); node1->next != NULL; node1 = node1->next) {
        i++;
    }
    node1->next = *(node);
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
    if (feof(input)) {
        return NULL;
    }
    //---TODO Check if birthday is valid

    fscanf(input, "%49[^,],%49[^,],%d,%d,%d, %499[^\n]\n", node->firstName, node->lastName, &(node->birthday.month),
           &node->birthday.day, &node->birthday.year, node->favoriteSong);

//    printf("%s,%s,%d,%d,%d, %s", node->firstName, node->lastName, (node->birthday.month),
//           node->birthday.day, node->birthday.year, node->favoriteSong);
    node->next = NULL;
    return node;
}

node_t *createList(FILE *input, node_t **head) {
    node_t *firstNode = readNodeInfo(input);
    head = &firstNode;
    if (firstNode == NULL) {
        fprintf(stderr, "Error in creating list. First Node read was NULL\n");
        exit(1);
    }
    while (true) {
        node_t *node = readNodeInfo(input);
        if (node == NULL) {
            break;
        }
        add(&node, head);
    }
    return NULL;
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
    if(args < 2){
        fprintf(stderr,"Not enough command line arguments. Exiting\n");
        exit(1);
    }
}

void checkFile(FILE *file, char *fileName) {
    //---Print using stderr
}

void deleteList(node_t **head) {

}

bool checkDate(bday_t birthday) {
    if (birthday.year < 1900 || birthday.year > 2020) {
        fprintf(stderr, "Year out of bounds\n");
        return false;
    } else if (birthday.month < 1 || birthday.month > 12) {
        fprintf(stderr, "Month out of bounds\n");
        return false;

        //Check day
    } else if (1) {
        //---TODO
        if(isLeapYear(birthday.year)){
            //---Do something
        }
        return false;
    }

    return true;
}

bool isLeapYear(int year) {
    if((year%4==0 && year%100!=0)|| year%400==0)
    {
        return true;
    }
    return false;
}

/*
 * for (node_t **node1 = head; node1 != NULL; node1 = &(*(node1))->next) {

   }
 */
