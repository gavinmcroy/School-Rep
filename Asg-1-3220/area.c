#include <stdio.h>
#include <stdlib.h>

int main(int args, char * argv[]){
    printf("ran");
    const int EXPECTED_ARGS = 3;
    if(args < EXPECTED_ARGS){
        fprintf(stderr,"Area was not provided enough arguments. Closing\n");
        exit(1);
    }
    int val1 = atoi(argv[1]);
    int val2 = atoi(argv[2]);
    printf("area is %d\n",val1*val2);

    return 0;
}

