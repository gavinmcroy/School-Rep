#include <stdio.h>
#include <sys/ptrace.h>
#include <sys/types.h>
#include <stdlib.h>

int main() {
    printf("Hello, World!\n");
    


    FILE* out = fopen("my.txt","w");
    if(!out){
        fprintf(stderr,"Error\n");
        exit(-1);
    }
    fprintf(out,"Hello\n");


    return 0;
}
