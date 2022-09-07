#include <stdio.h>
#include "functions.h"

int main(int args, char *argv[]) {
    checkArguments(args);
    //FILE* input = fopen("test2.txt","r");
    FILE *input = fopen(argv[1], "r");

    checkFile(input);
    checkBraces(input);
    return 0;
}
