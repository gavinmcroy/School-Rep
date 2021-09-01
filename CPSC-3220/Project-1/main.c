#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


/* ./leakCount ./ProgramToRun ./ProgramToRun Arguments */
int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Error, not enough command arguments. Closing");
        exit(1);
    }

    /* Program name is always second argument */
    char *programName = argv[1];

    /* args will point to the array of program arguments*/
    char **args = argv;
    args+=1;

    /* TODO Run specified program in separate process. Currently overwrites running process */
    execvp(programName,args);

    return 0;
}
