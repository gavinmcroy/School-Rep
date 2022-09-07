#include <stdio.h>
#include <stdlib.h>
typedef struct temp {
    int x;
    int y;
}temp;

int main() {
    printf("Hello, World!\n");
    struct temp* myVal = (temp*) malloc(sizeof(temp)*3);

    for(int i = 0; i < 3; i++){
        myVal[i].x = 20;
    }
    printf("%d",myVal[2].x);
    printf("%d",myVal[1].x);
    return 0;
}
