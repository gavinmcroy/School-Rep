//
// Created by Gavin McRoy on 3/10/2021.
//
#include "functions.h"

month_t *months;

void add(node_t **node, node_t **head) {
    //---node is what is going to be added and head is the head pointer
    if (head == NULL) {
        fprintf(stderr, "Error in Adding Node. HEAD is NULL\n");
        exit(1);
    }

    if (node == head) {
        return;
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
    if (feof(input)) {
        return NULL;
    }
    //---TODO Check if birthday is valid

    fscanf(input, "%49[^,],%49[^,],%d,%d,%d, %499[^\n]\n", node->firstName, node->lastName, &(node->birthday.month),
           &node->birthday.day, &node->birthday.year, node->favoriteSong);


    checkDate(node->birthday);

//    printf("%s,%s,%d,%d,%d, %s", node->firstName, node->lastName, (node->birthday.month),
//           node->birthday.day, node->birthday.year, node->favoriteSong);
    node->next = NULL;
    return node;
}

node_t *createList(FILE *input, node_t **head) {
    /* Building the list */
    node_t *firstNode = readNodeInfo(input);
    head = &firstNode;
    if (firstNode == NULL) {
        fprintf(stderr, "Error in creating list. First Node read was NULL\n");
        exit(1);
    }
    while (true) {
        node_t *node = readNodeInfo(input);
        //---Means file has been fully read
        if (node == NULL) {
            break;
        }
        add(&node, head);
    }
    return firstNode;
}

void PrintList(FILE *output, node_t *node) {
    printBorder(output);
    fprintf(output, "List Info:\n");
    for (node_t *node1 = node; node1 != NULL; node1 = node1->next) {
        fprintf(output, "%s,%s,%d,%d,%d, %s\n", node1->firstName, node1->lastName, (node1->birthday.month),
                node1->birthday.day, node1->birthday.year, node1->favoriteSong);
    }
    printBorder(output);
}

void PrintBDay(FILE *output, node_t *node) {
    printBorder(output);
    //---TODO convert the digit month into the string month (1 == JANUARY)
    for (node_t *node1 = node; node1 != NULL; node1 = node1->next) {
        fprintf(output, "%s %s's date of birth is %d %d,%d\n", node1->firstName, node1->lastName,
                (node1->birthday.month),
                node1->birthday.day, node1->birthday.year);
    }
    //Yvon Feaster’s date of birth is October 7, 1963
    printBorder(output);
}

void Song(FILE *output, node_t *node) {
    //Yvon Feaster’s favorite song is I’m moving on
    printBorder(output);
    //---TODO convert the digit month into the string month (1 == JANUARY)
    for (node_t *node1 = node; node1 != NULL; node1 = node1->next) {
        fprintf(output, "%s %s's favorite song is %s\n", node1->firstName, node1->lastName, node1->favoriteSong);
    }
    printBorder(output);
}

void printBorder(FILE *output) {
    fprintf(output, "********************************************************************************\n");
}

void print(void (*fp)(FILE *, node_t *), FILE *output, node_t *node) {
    fp(output, node);
}

void checkArgs(int args) {
    if (args < 2) {
        fprintf(stderr, "Not enough command line arguments. Exiting\n");
        exit(1);
    }
}

void checkFile(FILE *file, char *fileName) {
    if (!file) {
        fprintf(stderr, "File %s failed to open", fileName);
        exit(1);
    }
}

void deleteList(node_t **head) {
    node_t *tmp = *(head);
    node_t *test = tmp;
    while (tmp != NULL) {
        tmp = tmp->next;
        free(test);
        test = tmp;
    }
    head = NULL;
}

bool checkDate(bday_t birthday) {
    enum month;
    if (birthday.year < 1900 || birthday.year > 2020) {
        fprintf(stderr, "Year out of bounds\n");
        return false;
    } else if (birthday.month < 1 || birthday.month > 12) {
        fprintf(stderr, "Month out of bounds\n");
        return false;
    } else if (birthday.day < 0 || birthday.day > months[birthday.month].day) {
        if (isLeapYear(birthday.year)) {
            //---Basically does the february date equal 28 + 1? If so leap year is in affect
            if (birthday.month == February && (birthday.day == months[birthday.month].day + 1)) {
                return true;
            }
        }
        return false;
    }
    return true;
}

bool isLeapYear(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
        return true;
    }
    return false;
}

void loadMonthInfo(FILE *input) {
    int size = 0;
    int iterator = 0;
    fscanf(input, "%d", &size);
    months = (month_t *) (malloc(sizeof(month_t) * size));
    while (fscanf(input, "%s %d", months[iterator].month, &months[iterator].day) != EOF) {
        //printf("%s %d\n", months[iterator].month, months[iterator].day);
        iterator++;
    }
}

