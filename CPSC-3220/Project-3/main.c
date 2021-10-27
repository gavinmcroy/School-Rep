#include <stdio.h>
#include <stdlib.h>
#include "allocator.h"

int main() {
    char * pointer = (char *)malloc(sizeof(char)*5);
    printf("Hello, World!\n");
    return 0;
}
