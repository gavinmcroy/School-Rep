#include <stdio.h>
#include <stdlib.h>

int main(int args, char *argv[]) {
    const int EXPECTED_ARGS = 3;
    if (args < EXPECTED_ARGS) {
        fprintf(stderr, "Error not enough arguments\n");
    }
    int val1 = atoi(argv[1]);
    int val2 = atoi(argv[2]);
    printf("perimeter is %d\n", val1 + val1 + val2 + val2);
    return 0;
}

