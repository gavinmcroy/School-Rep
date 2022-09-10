#include <stdio.h>
#include<string.h>

int main() {
    //printf("Hello, World!\n");
    char temp[10] = "Hello";
    char buffer[2][2] = {};
    buffer[0][0] = 'X';
    strcat(temp,&buffer[0][0]);
    printf("%s",temp);
    return 0;
}
