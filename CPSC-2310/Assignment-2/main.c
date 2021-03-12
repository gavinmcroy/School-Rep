#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

int main(int argc, char* argv[]) {
    printf("Hello, World!\n");
    FILE* file = fopen(argv[1],"r");
    if(!file){
        printf("File failed to open");
        exit(1);
    }
    readNodeInfo(file);

    return 0;
}
