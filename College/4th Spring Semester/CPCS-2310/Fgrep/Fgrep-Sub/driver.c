#include <stdio.h>
#include <stdlib.h>
#include<string.h>

void search(char *fileName, FILE *input, char *searchString);


int main(int argc, char *argv[]) {
    const int MIN_COMMANDS = 3;
    if (argc < MIN_COMMANDS) {
        printf("Usage: executable string file ...\n");
        exit(0);
    }
    int loopIterations = argc - MIN_COMMANDS;
    char *searchString = argv[1];
    int additionalCommands = 0;
    while (loopIterations >= 0) {
        FILE *file = fopen(argv[MIN_COMMANDS + additionalCommands - 1], "r");
        if (!file) {
            perror(argv[MIN_COMMANDS + additionalCommands - 1]);
        } else {
            search(argv[MIN_COMMANDS + additionalCommands - 1], file, searchString);
            printf("\n");
            fclose(file);
        }

        additionalCommands++;
        loopIterations--;
    }
    return 0;
}

void search(char *fileName, FILE *input, char *searchString) {
    int bufferSize = 256;
    char *buffer = (char *) malloc(sizeof(char) * bufferSize);
    while (fgets(buffer, 260, input) != NULL) {
        if (strstr(buffer, searchString) != NULL) {
            printf("%s:%s", fileName, buffer);
        }
    }
    free(buffer);
}