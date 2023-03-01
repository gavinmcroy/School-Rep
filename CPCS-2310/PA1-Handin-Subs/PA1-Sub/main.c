#include <stdio.h>
#include "functions.h"

void loadMenu(FILE *output, node_t *head);

int main(int args, char *argv[]) {
    FILE *input = fopen(argv[1], "r");
    FILE *monthInput = fopen("MonthInfo", "r");
    FILE *output = fopen("output.txt", "w");
    checkFile(monthInput, "MonthInfo");
    checkFile(input, argv[1]);
    checkFile(output, "output.txt");
    checkArgs(args);
    loadMonthInfo(monthInput);
    node_t *head = createList(input, &head);
    loadMenu(output, head);
    deleteList(&head);
    fclose(input);
    fclose(output);
    return 0;
}

void loadMenu(FILE *output, node_t *head) {
    bool runMenu = true;
    while (runMenu) {
        char option = ' ';
        //---Loop until valid input
        while (option < '1' || option > '4') {
            printf("What would you like to print\n"
                   "1. Print List Contents\n"
                   "2. Print Birthdays\n"
                   "3. Print Songs\n"
                   "4. Quit\n");
            scanf(" %1c", &option);
        }
        switch (option) {
            case '1':
                print(PrintList, output, head);
                printf("Contents written to file\n");
                break;
            case '2':
                print(PrintBDay, output, head);
                printf("Contents written to file\n");
                break;
            case '3':
                print(Song, output, head);
                printf("Contents written to file\n");
                break;
            case '4':
                runMenu = false;
                printf("Exiting.\n");
                return;
        }
    }
}