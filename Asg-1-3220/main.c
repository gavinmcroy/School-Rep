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
    const char PERIMETER_NAME[12] = "/perimeter";

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
    int firstChild = fork();
    if (firstChild < 0) {
        fprintf(stderr, "Process failed to start\n");
        exit(1);
    }

    /* execl area.c (print parent + child pid and result of calc then exit) */
    pid_t var1 = getpid();
    /* This is the child */
    if (firstChild == 0) {
        const int BUFFER = 256;
        char *perimeterPath = (char *) malloc(sizeof(char) * BUFFER);
        char *areaPath = (char *) malloc(sizeof(char) * BUFFER);

        char *tempArea = "./area";
        char *tempPerimeter = "./perimeter";
        printf("Child ID1 = %d \n", var1);
        grabCurrentPath();
        /* Append file name on the end of directory */
        strcpy(areaPath,cwd);
        strcpy(perimeterPath,cwd);
        strcat(areaPath, AREA_NAME);
        strcat(perimeterPath,PERIMETER_NAME);

        printf("%s", areaPath);
        /* This fork is for the second child of parent */
//        int secondChild = fork();
//
//        if (secondChild == 0) {
//            pid_t var2 = getpid();
//            printf("Child ID2 = %d \n", var2);
//            // execl()
//        }
        /* This is the first child being ran */
        execl(areaPath, tempArea, argv[1], argv[2], (char *) (NULL));

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