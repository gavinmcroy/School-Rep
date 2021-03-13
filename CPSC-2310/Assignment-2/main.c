#include <stdio.h>
#include "functions.h"

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
    print(PrintList, output, head);
    deleteList(&head);
    fclose(input);
    fclose(output);
    return 0;
}
