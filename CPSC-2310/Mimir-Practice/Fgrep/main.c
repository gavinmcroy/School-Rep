#include <stdio.h>
#include <stdlib.h>
#include<string.h>

void search(char *fileName, FILE *input, char *searchString);


int main(int argc, char *argv[]) {
    const int MIN_COMMANDS = 3;
    int loopIterations = argc - MIN_COMMANDS;
    char *searchString = argv[1];
    int additionalCommands = 0;
    while (loopIterations >= 0) {
        FILE *file = fopen(argv[MIN_COMMANDS + additionalCommands - 1], "r");
        if (!file) {
            perror(argv[MIN_COMMANDS + additionalCommands - 1]);
        }
        search(argv[MIN_COMMANDS + additionalCommands - 1], file, searchString);
        printf("\n");
        fclose(file);
        additionalCommands++;
        loopIterations--;
    }





//    if (argc == 3) {
//        FILE *file = fopen(argv[argc - 1], "r");
//        if (!file) {
//            perror(argv[argc - 1]);
//        }
//        search(argv[argc - 1], file, argv[argc - 2]);
//        fclose(file);
//    } else if (argc == 4) {
//        FILE *file = fopen(argv[argc - 2], "r");
//        FILE *file2 = fopen(argv[argc - 1], "r");
//        search(argv[argc - 2], file, argv[argc - 3]);
//        printf("\n");
//        search(argv[argc - 1], file2, argv[argc - 3]);
//        fclose(file);
//        fclose(file2);
//    }
    //---Read file contents
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