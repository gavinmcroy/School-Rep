#define _GNU_SOURCE

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


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
    args += 1;

    /* TODO Run specified program in separate process. Currently overwrites running process */
    pid_t pid = fork();
    if (pid == 0) {
        /* Need to link shim with process */
        //execvp(programName,args);

        setenv("LD_PRELOAD", "/Users/gavintaylormcroy/Desktop/shim-dir", 1);
        char *pathVar = getenv("LD_PRELOAD");
        printf("%s", pathVar);

        //execve(programName, args, &pathVar);
    } else {
        printf("Parent!\n");
    }

    return 0;
}
