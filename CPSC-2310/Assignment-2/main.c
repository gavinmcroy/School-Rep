#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

int main(int args, char* argv[]) {
    printf("Hello, World!\n");
    FILE* file = fopen(argv[1],"r");
    if(!file){
        printf("File failed to open");
        exit(1);
    }
    checkArgs(args);
    node_t **head = NULL;
    readNodeInfo(file);
    createList(file,head);
    //print()
    return 0;
}
