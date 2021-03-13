#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

int main(int args, char *argv[]) {
    printf("Hello, World!\n");
    FILE *input = fopen(argv[1], "r");
    FILE *output = fopen("output.txt", "w");
    checkFile(input, argv[1]);
    checkFile(output, "output.txt");
    checkArgs(args);
    node_t *head = createList(input, &head);
    print(Song, output, head);
    fclose(input);
    fclose(output);
    return 0;
}
