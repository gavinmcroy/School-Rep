#include <stdio.h>
#include "allocator.h"

int main() {
    char * pointer = (char *)malloc(sizeof(char)*5);
    if(!pointer){
        printf("error");
    }
    printf("Hello, World!\n");

    return 0;
}
