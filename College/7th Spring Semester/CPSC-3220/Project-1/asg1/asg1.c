#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <string.h>
#include <pthread.h>

typedef struct Data {
    int x1;
    int x2;
    char *string;
} Data;

void *threadRatio(void *passTheStruct) {
    Data *data = (Data *) passTheStruct;
    double *memory = (double *) malloc(sizeof(double));
    *memory = (data->x1 / (double) data->x2);
    printf("Thread 1: tig %ld, ratio is %.2lf\n", (long) pthread_self(), *memory);
    pthread_exit((void *) memory);
}

void *stringReversal(void *passTheStruct) {
    Data *data = (Data *) passTheStruct;
    char *reverseString = (char *) malloc(sizeof(char) * strlen(data->string));
    int secondaryCount = 0;
    for (int i = strlen(data->string) - 1; i >= 0; i--) {
        reverseString[secondaryCount] = data->string[i];
        secondaryCount++;
    }
    reverseString[secondaryCount + 1] = '\0';
    printf("Thread 2: tig %ld, message is %s\n",(long) pthread_self(), reverseString);
    pthread_exit((void *) reverseString);
}

char cwd[PATH_MAX];

void grabCurrentPath();

/* ./a.out num1 num2 string */
int main(int args, char *argv[]) {
    const int BUFFER = 256;
    const int THREE_ARGS = 4;
    const char AREA_NAME[6] = "/area";
    const char PERIMETER_NAME[12] = "/perimeter";
    pthread_t thread1;
    pthread_t thread2;

    Data *data = (Data *) malloc(sizeof(Data));
    if (args < THREE_ARGS) {
        fprintf(stderr, "Error not enough command arguments");
        exit(1);
    }
    /* Initialize struct + process */
    data->x1 = atoi(argv[1]);
    data->x2 = atoi(argv[2]);
    data->string = argv[3];

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

        printf("Child1: pid %d, ppid %d ", var1, getppid());
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
        printf("Child2: pid = %d, ppid %d ", var2, getppid());
        fflush(stdout);
        int val = execl(perimeterPath, tempPerimeter, argv[1], argv[2], (char *) NULL);
        printf("%d", val);
    }

    //Example: "Child1: pid 39810, ppid 39809, area is 50"
    wait(NULL);
    printf("\n");
    /* execl perimeter.c (print parent + child pid with x1,x2, print output, exit) */

    /* Parent makes two threads */
    /* Each thread will print its own tig and the result of the
       calculation/reversal to standard output before returning result to the parent */
    double *ratioFromThread = NULL;
    char *reverseStringFromThread = NULL;
    pthread_create(&thread1, NULL, &threadRatio, (void *) data);
    pthread_create(&thread2, NULL, &stringReversal, (void *) data);
    pthread_join(thread1, (void **) &ratioFromThread);
    pthread_join(thread2, (void **) &reverseStringFromThread);


    printf("\nParent: pid %d, ratio: %.2lf, message: %s\n", var1, *ratioFromThread, reverseStringFromThread);

    /* Not exactly good design but threadRatio allocates memory when called so the return
 * value must be freed */
    free(ratioFromThread);
    free(reverseStringFromThread);


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
