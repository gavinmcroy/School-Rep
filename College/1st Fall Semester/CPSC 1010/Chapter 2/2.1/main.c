#include <stdio.h>

/*
 * Write a program that prompts the user to input the
 * elapsed time for an event in seconds.
 * The program then outputs the elapsed
 * time in hours, minutes, and seconds.
 */

int main() {
    int elapsedTime = 0;
    printf("Enter the elapsed time in seconds: \n");
    scanf("%d",&elapsedTime);
    int hour = elapsedTime / (60 * 60);
    int min = (elapsedTime / 60) % 60;
    int second = elapsedTime % 60;
    printf("The elapsed time in seconds = %d\n", elapsedTime);
    printf("The equivalent time in hours:minutes:seconds = %02d:%02d:%02d\n", hour, min, second);
    return 0;
}