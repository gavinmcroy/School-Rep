#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wait.h>
#include <string.h>
#include <time.h>
#define GetCurrentDir getcwd

char *environment = "LD_PRELOAD";
extern char **environ;

int main(int argc, char *argv[]) {
    /* Grabs programs working directory */
    char buff[FILENAME_MAX];
    char programBuffer[FILENAME_MAX];
    GetCurrentDir(buff,FILENAME_MAX);
    GetCurrentDir(programBuffer,FILENAME_MAX);

    if (argc < 2) {
        printf("Error, not enough commands\n");
        exit(-1);
    }
    int status;

    /* Set up environment variable */
    char *programName = argv[1];
    strcat(buff,"/memory_shim.so");
    strcat(programBuffer,programName);

    //printf("PWD %s\n",buff);
    //printf("PWD %s\n",programBuffer);

    /* args will point to program arguments */
    char **args = argv;
    args += 1;

    pid_t pid = fork();
    if (pid == 0) {
       //printf("Child created\n");
        setenv(environment, buff, 1);
        //printf("%s\n", pathVar);
        execvpe(programName,args,environ);
    }else{
       // printf("Parental unit\n");
    }
    waitpid(pid, &status, 0);

    return 0;
}

