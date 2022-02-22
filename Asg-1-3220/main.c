#include <stdio.h>
#include <stdlib.h>

typedef struct Data {
    int x1;
    int x2;
    char *string;
} Data;

int main(int args, char *argv[]) {
    const int THREE_ARGS = 4;
    Data data;
    if (args < THREE_ARGS) {
        fprintf(stderr, "Error not enough command arguments");
        exit(1);
    }
    /* Initialize struct + process */
    /* execl area.c (print parent + child pid and result of calc then exit) */
    /* execl perimeter.c (print parent + child pid with x1,x2, print output, exit) */
    /* Parent makes two threads */
    return 0;
}
