#define _GNU_SOURCE

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#ifdef __APPLE__
char *environment = "DYLD_INSERT_LIBRARIES";
#else
char * environment = "LD_PRELOAD";
#endif

extern char **environ;

/* ./leakCount ./ProgramToRun ./ProgramToRun Arguments */
int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Error, not enough command arguments. Closing");
        exit(1);
    }
    int status;

    /* Program name is always second argument */
    char *programName = argv[1];

    /* args will point to the array of program arguments*/
    char **args = argv;
    args += 1;

    /* TODO Run specified program in separate process. Currently overwrites running process */
    pid_t pid = fork();
    if (pid == 0) {
        printf("Child created\n");
        /* Need to link shim with process */
        setenv(environment, "/Users/gavintaylormcroy/Documents/GitHub/School-Rep/CPSC-3220"
                            "/shim.dylib DYLD_FLAT_NAMESPACE=1 .//Users/gavintaylormcroy/Documents/GitHub/School-Rep"
                            "/CPSC-3220/leakcount", 1);
        char *pathVar = getenv(environment);
        printf("%s", pathVar);

        execve(programName, args, environ);
    } else {
        printf("Parent!\n");
    }

    waitpid(pid, &status, 0);
    return 0;
}

//DYLD_INSERT_LIBRARIES=$PWD/shim.dylib DYLD_FORCE_FLAT_NAMESPACE=1 ./mallocTest
