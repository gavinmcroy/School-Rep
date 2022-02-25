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
    const int BUFFER = 256;
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
        fprintf(stderr, "First process failed to start\n");
        exit(1);
    }

    /* execl area.c (print parent + child pid and result of calc then exit) */
    pid_t var1 = getpid();
    /* This is the child */
    if (firstChild == 0) {
        char *areaPath = (char *) malloc(sizeof(char) * BUFFER);
        char *tempArea = "./area";

        printf("Child1: pid %d, ppid %d ", var1,getppid());
        grabCurrentPath();
        /* Append file name on the end of directory */
        strcpy(areaPath, cwd);
        strcat(areaPath, AREA_NAME);

        /* This is how we get everything to print on one line. Removing this will cause nothing to be printed
         * other than the new process */
        fflush(stdout);
        /* This is the first child being ran */
        execl(areaPath, tempArea, argv[1], argv[2], (char *) (NULL));

    }
    wait(NULL);

    int secondChild = fork();

    if (firstChild < 0) {
        fprintf(stderr, "Second process failed to start\n");
        exit(1);
    }

    if (secondChild == 0) {
        char *perimeterPath = (char *) malloc(sizeof(char) * BUFFER);
        char *tempPerimeter = "./perimeter";

        grabCurrentPath();
        strcpy(perimeterPath, cwd);
        strcat(perimeterPath, PERIMETER_NAME);

        pid_t var2 = getpid();
        printf("Child2: pid = %d, ppid %d ", var2,getppid());
        fflush(stdout);
        int val = execl(perimeterPath, tempPerimeter, argv[1], argv[2], (char *) NULL);
        printf("%d",val);
    }

    //Example: "Child1: pid 39810, ppid 39809, area is 50"
    wait(NULL);
    printf("Parent ID = %d \n", var1);
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