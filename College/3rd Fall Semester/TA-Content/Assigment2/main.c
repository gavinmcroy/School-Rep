#include <stdio.h>

void processArray(char** c){
    FILE *file = fopen("myfile");
    function1(file);
    function2();
    playMove();
    playerKill();
}


int main() {
//    int x = 10;
//    int size = 0;
//    printf("Hello, World!\n");

    readFile();
    loadFile();
    processFile();
    closeFile();
/*
    processArray(10,20)

    int x = processArray(10,20);

    char myChars[9][9];
    processArray(myChars);

    int myValue = addition(10,20);
    printf("%d",myValue);*/

    return 0;
}

int processArray(int x, int y){
    for(int i =0; i<10; i++){
        for(int j = 0; j<10; j++){
            int y = x;
        }
    }
    return x+y;
}

