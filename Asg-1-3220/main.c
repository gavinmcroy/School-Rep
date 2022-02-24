#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <string.h>

typedef struct Data {
    int x1;
    int x2;
    char *string;
} Data;

char cwd[PATH_MAX];

void grabCurrentPath();

/* ./a.out num1 num2 string */
int main(int args, char *argv[]) {
    const int THREE_ARGS = 4;
    const char AREA_NAME[6] = "/area";

    Data data;
    if (args < THREE_ARGS) {
        fprintf(stderr, "Error not enough command arguments");
        exit(1);
    }
    /* Initialize struct + process */
    data.x1 = atoi(argv[1]);
    data.x2 = atoi(argv[2]);
    data.string = argv[3];

    /* Start up second process */
    int error = fork();
    if (error < 0) {
        fprintf(stderr, "Process failed to start\n");
        exit(1);
    }

    /* execl area.c (print parent + child pid and result of calc then exit) */
    pid_t var1 = getpid();
    /* This is the child */
    if (error == 0) {
        char *temp = "./area";
        printf("Child ID = %d \n", var1);
        grabCurrentPath();
        /* Append file name on the end of directory */
        strcat(cwd, AREA_NAME);
        printf("%s", cwd);
        int problemFound = execl(cwd, temp, argv[1], argv[2],(char *) (NULL));
        printf("\n%d\n",problemFound);
    } else {
        printf("Parent ID = %d \n", var1);
    }
    //Example: "Child1: pid 39810, ppid 39809, area is 50"
    wait(NULL);

    /* execl perimeter.c (print parent + child pid with x1,x2, print output, exit) */
    


    /* Parent makes two threads */
    return 0;
}

/* Grabs current path for execl */
void grabCurrentPath() {
    if (getcwd(cwd, sizeof(cwd)) != NULL) {
        // printf("Current working dir: %s\n", cwd);
    } else {
        fprintf(stderr, "Error grabbing current directory\n");
        exit(1);
    }

}