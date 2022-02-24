#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

typedef struct Data {
    int x1;
    int x2;
    char *string;
} Data;

/* ./a.out num1 num2 string */
int main(int args, char *argv[]) {
    const int THREE_ARGS = 4;
    Data data;
    if (args < THREE_ARGS) {
        fprintf(stderr, "Error not enough command arguments");
        exit(1);
    }
    /* Initialize struct + process */
    data.x1 = atoi(argv[1]);
    data.x2 = atoi(argv[2]);
    data.string = argv[3];

    //Example: "Child1: pid 39810, ppid 39809, area is 50"
    int error = fork();
    if (error < 0) {
        fprintf(stderr, "Process failed to start\n");
        exit(1);
    }
    pid_t var1 = getpid();
    /* This is the child */
    if(error == 0){
        printf("Child ID = %d \n", var1);
    }else{
        printf("Parent ID = %d \n", var1);
    }
    wait(NULL);

    /* execl area.c (print parent + child pid and result of calc then exit) */
    /* execl perimeter.c (print parent + child pid with x1,x2, print output, exit) */
    /* Parent makes two threads */
    return 0;
}
