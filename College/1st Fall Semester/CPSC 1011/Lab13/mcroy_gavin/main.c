#include <stdio.h>
#include<time.h>
#include<stdlib.h>
#include "sorting_algorithms.h"

void PrintMenu();

int *ReadFileToArray(char *fileName, int size);

void WriteArrayToFile(int array[], int num);

void CallSort(int *array, int size, char *fileReset);

//---TODO Write descriptions for different sorting methods for how they work
//---TODO Record data into excel on different run times of algorithms
//---TODO Write report for data collected

int main() {
    PrintMenu();
    int userChoice = -1;
    scanf("%d", &userChoice);
    int *data = NULL;

    switch (userChoice) {
        case 1:
            data = ReadFileToArray("lab13_random.small.input", 10);
            CallSort(data, 10, "lab13_random.small.input");
            WriteArrayToFile(data, 10);
            break;
        case 2:
            data = ReadFileToArray("lab13_random.medium.input", 100);
            CallSort(data, 100, "lab13_random.medium.input");
            WriteArrayToFile(data, 100);
            break;
        case 3:
            data = ReadFileToArray("lab13_random.large.input", 1000);
            CallSort(data, 1000, "lab13_random.large.input");
            WriteArrayToFile(data, 1000);
            break;
        case 4:
            data = ReadFileToArray("lab13_random.jumbo.input", 10000);
            CallSort(data, 10000, "lab13_random.jumbo.input");
            WriteArrayToFile(data, 10000);
            break;
        default:
            printf("Chose a valid input\n");
            break;
    }
    printf("Finishing the program...\n");
    return 0;
}

int *ReadFileToArray(char *fileName, int size) {
    FILE *file = fopen(fileName, "r");
    if (file == NULL) {
        printf("Error opening file\n");
        return NULL;
    }
    int *data = (int *) malloc(sizeof(int) * size);
    for (int i = 0; i < size; i++) {
        int tmp = fscanf(file, "%d,", &data[i]);
        if (tmp != 1) {
            break;
        }
    }
    fclose(file);
    return data;
}

void PrintMenu() {
    printf("Which data file would you like to sort?\n"
           "[1] Small file (10 items)\n"
           "[2] Medium file (100 items)\n"
           "[3] Large file (1,000 items)\n"
           "[4] Jumbo file (10,000 items)\n");
}

void WriteArrayToFile(int array[], int num) {
    FILE *pF = NULL;
    switch (num) {//based off the file size create a new file with size name
        case 10:
            pF = fopen("sorted.algorithm.small.output", "w+");
            break;
        case 100:
            pF = fopen("sorted.algorithm.medium.output", "w+");
            break;
        case 1000:
            pF = fopen("sorted.algorithm.large.output", "w+");
            break;
        case 10000:
            pF = fopen("sorted.algorithm.jumbo.output", "w+");
            break;
        default:
            pF = fopen("rand", "w+");
            break;
    }

    if (pF == NULL) {
        perror("Error opening file");
    } else {
        for (int i = 0; i < num; i++) {
            fprintf(pF, "%d, ", array[i]);
        }
        fclose(pF);
    }
}

void CallSort(int *array, int size, char *fileReset) {
    size -=1;
    clock_t begin = clock();
    SelectionSort(array, size);
    clock_t end = clock();
    double timeSpent = ((double) (end - begin) / CLOCKS_PER_SEC) * 1000;
    printf("Sorting with selection sort...done after %lf\n", timeSpent);
    free(array);

    //---Purpose of just resetting data
    array = ReadFileToArray(fileReset, size);
    begin = clock();
    InsertionSort(array, size);
    end = clock();
    timeSpent = ((double) (end - begin) / CLOCKS_PER_SEC) * 1000;
    printf("Sorting with insertion sort...done after %lf\n", timeSpent);
    free(array);

    array = ReadFileToArray(fileReset, size);
    begin = clock();
    BubbleSort(array, size);
    end = clock();
    timeSpent = ((double) (end - begin) / CLOCKS_PER_SEC) * 1000;
    printf("Sorting with bubble sort...done after %lf\n", timeSpent);
    free(array);

    array = ReadFileToArray(fileReset, size);
    begin = clock();
    QuickSort(0, size, array);
    end = clock();
    timeSpent = ((double) (end - begin) / CLOCKS_PER_SEC) * 1000;
    printf("Sorting with quick sort...done after %lf\n", timeSpent);
}
