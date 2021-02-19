#include "functions.h"

int *readData(FILE *file, int *numberOfGrades) {
    fscanf(file, "%d", numberOfGrades);
    int * grades = (int *) malloc(sizeof(int) * (*numberOfGrades));
    for(int i = 0; i < *numberOfGrades; i++){
        fscanf(file,"%d",&grades[i]);
    }
    return grades;
}

void determineGrade(int *grades, int numberOfGrades) {
    /*
     * If the difference between the grade and the next multiple of 5 is less than 3, round the grade
        up to the next multiple of 5. Ex. 81 is 4 points from 85 (the next multiple of 5) therefore the
        grade is not rounded. However, 88 is 2 points from 90, therefore, the grade will be rounded to
        90.
     */
    int benefitted = 0;
    for (int i = 0; i < numberOfGrades; i++) {
        /* take the modulo, if modulo <= 3 than round*/
        if (abs(grades[i] % 5 - 5) <= 3) {
            if(grades[i] <= 38){
                continue;
            }
            benefitted++;
            grades[i] = grades[i] + grades[i] % 5;
        }
    }
    printf("%d = %.2lf%% of the students benefited from the grading policy change.\n", benefitted,
           (double) benefitted / numberOfGrades);
}

void printGrade(int numberOfGrades, int *grades) {

}

void checkArguments(int args) {
    if (args < 2) {
        printf("To few command line arguments. Exiting program.\n");
        exit(1);
    }
}

void checkFile(FILE *file) {
    if (!file) {
        printf("The file did not open successfully. Exiting program.\n");
        exit(1);
    }
}

void calculatePercent(int numberOfGrades, int * grades) {

}

void printGraph(int unknown) {

}