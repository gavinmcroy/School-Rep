//
// Created by Gavin McRoy on 3/10/2021.
//
#include "functions.h"

/****************************** /
* Gavin McRoy                 *
* CPSC2310 Spring 2021        *
* UserName: gmcroy            *
* Instructor:Dr. Yvon Feaster *
/ *****************************/

month_t *months;

/*
 * Adds a node to the list. If attempting to add a node while head is NULL the program exits.
 * This is because head is handled in create list and should not be null when add is called. Add works
 * by looping through the linked list, stopping on the last node, then adding the desired node to the end
 * @param node - the node to be added
 * @param head - the start of the list
 * @return none
 */
void add(node_t **node, node_t **head) {
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

/*
 * Reads information from a file that has been successfully opened. Will not work if file failed to open. Reads
 * one node from the file then returns. Also ignores nodes that are have a birthday that goes out of range
 * @param input - the file to be read
 * @return the information read from the file into one node
 */
node_t *readNodeInfo(FILE *input) {
    node_t *node = (node_t *) malloc(sizeof(node_t));

    fscanf(input, "%49[^,],%49[^,],%d,%d,%d, %499[^\n]\n", node->firstName, node->lastName, &(node->birthday.month),
           &node->birthday.day, &node->birthday.year, node->favoriteSong);

    if (!checkDate(node->birthday)) {
        free(node);
        return NULL;
    }
    node->next = NULL;
    return node;
}

/* Builds the actual linked list. Head is handled within create list. Loops over until the file hits EOF adding
 * nodes to the linked list along the way. If a node is NULL that means the birthday information is invalid,
 * so skip it
 * @param input - the file to be read
 * @param head - the start of the linked list
 * @return - the head of the node itself
 */
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
        if (feof(input)) {
            break;
        }
        //---Means garbage data, ignore
        if (node == NULL) {
            continue;
        }
        add(&node, head);
    }
    return firstNode;
}

/* Loops over all the contents while writing contents to a file. Also prints a border
 * around written contents
 * @param output - the file to write the linked list contents too
 * @param node - the start of the linked list
 * @return - none
 */
void PrintList(FILE *output, node_t *node) {
    printBorder(output);
    fprintf(output, "List Info:\n");
    for (node_t *node1 = node; node1 != NULL; node1 = node1->next) {
        fprintf(output, "%s,%s,%s,%d,%d, %s\n", node1->firstName, node1->lastName,
                (months[node1->birthday.month - 1].month),
                node1->birthday.day, node1->birthday.year, node1->favoriteSong);
    }
    printBorder(output);
}

/* Loops over all the contents while writing contents to a file. Prints ONLY a persons name
 * Also prints a border around written contents
 * @param output - the file to write the linked list contents too
 * @param node - the start of the linked list
 * @return - none
 */
void PrintName(FILE *output, node_t *node) {
    printBorder(output);
    fprintf(output, "List Info:\n");
    for (node_t *node1 = node; node1 != NULL; node1 = node1->next) {
        fprintf(output, "%s,%s\n", node1->firstName, node1->lastName);
    }
    printBorder(output);
}

/* Loops over all the contents while writing contents to a file. Prints everything EXCEPT favorite song
 * Also prints a border around written contents
 * @param output - the file to write the linked list contents too
 * @param node - the start of the linked list
 * @return - none
 */
void PrintBDay(FILE *output, node_t *node) {
    printBorder(output);
    for (node_t *node1 = node; node1 != NULL; node1 = node1->next) {
        fprintf(output, "%s %s's date of birth is %s %d,%d\n", node1->lastName, node1->firstName,
                (months[node1->birthday.month - 1].month),
                node1->birthday.day, node1->birthday.year);
    }
    //Yvon Feaster’s date of birth is October 7, 1963
    printBorder(output);
}

/* Loops over all the contents while writing contents to a file. Prints everything EXCEPT birthday information
 * Also prints a border around written contents
 * @param output - the file to write the linked list contents too
 * @param node - the start of the linked list
 * @return - none
 */
void Song(FILE *output, node_t *node) {
    //Yvon Feaster’s favorite song is I’m moving on
    printBorder(output);
    for (node_t *node1 = node; node1 != NULL; node1 = node1->next) {
        fprintf(output, "%s %s's favorite song is %s\n", node1->lastName, node1->firstName, node1->favoriteSong);
    }
    printBorder(output);
}

/* prints a simple border consisting of '*' to a output file
 * @param output - the file to be written too
 * @return - none
 */
void printBorder(FILE *output) {
    fprintf(output, "********************************************************************************\n");
}

/* General print function capable of excepting a function pointer to another print method. Prints
 * in the format the passed function specifies
 * @param fp - the function pointer that determines how the contents are formatted to the file
 * @param output - the file to write the linked list contents too
 * @param node - the start of the linked list
 * @return - none
 */
void print(void (*fp)(FILE *, node_t *), FILE *output, node_t *node) {
    fp(output, node);
}

/* Checks that a file was passed on the command line. If a file was not passed the program will exit
 * @param args - the total arguments passed through the command line.
 * @return - none
 */
void checkArgs(int args) {
    if (args < 2) {
        fprintf(stderr, "Not enough command line arguments. Exiting\n");
        exit(1);
    }
}

/* Determines if a particular file failed to open. If a file failed to open the program exits while printing
 * an error message to stderr
 * @param file - the file we are checking
 * @param fileName - the name of the file we are checking
 * @return - none
 */
void checkFile(FILE *file, char *fileName) {
    if (!file) {
        fprintf(stderr, "File %s failed to open", fileName);
        exit(1);
    }
}

/* Deletes all the contents of the linked list. Starts with head and deletes as it iterates through the list
 * @param head - the start of the linked list
 * @return - none
 */
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

/* Checks if a particular birthday is valid. By valid it means that a person isn't over 120 years old, a person was
 * born on a valid month and that the day is consistent how many days are in the month. Also determines if
 * there are any problems related to leap years and fixes accordingly preventing false positives.
 * @param birthday - birthday struct containing all information about a persons birthday
 * @return - true if the birthday is valid, false if it is not valid
 */
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
/* Determines if a particular year is a leap year.
 * @param year - the desired year to be checked
 * @return - false if it is not a leap year, true if it is a leap year
 */
bool isLeapYear(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
        return true;
    }
    return false;
}

/* Function created to reduce some of the code required for checking dates. Reads all month information in
 * from a file, and stores it an array where the indices correspond to the actual month-1. Makes it much easier
 * to grab information about a month such as name, or how many days are in said month
 * @param input - the file containing all the month information
 * @return - none
 */
void loadMonthInfo(FILE *input) {
    int size = 0;
    int iterator = 0;
    fscanf(input, "%d", &size);
    months = (month_t *) (malloc(sizeof(month_t) * size));
    while (fscanf(input, "%s %d", months[iterator].month, &months[iterator].day) != EOF) {
        iterator++;
    }
}

