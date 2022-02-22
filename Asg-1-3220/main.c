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
    return 0;
}
