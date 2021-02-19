#include "functions.h"

int *readData(FILE *file, int *numberOfGrades) {
    fscanf(file, "%d", numberOfGrades);
    int *grades = (int *) malloc(sizeof(int) * (*numberOfGrades));
    for (int i = 0; i < *numberOfGrades; i++) {
        fscanf(file, "%d", &grades[i]);
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
    int benefited = 0;
    for (int i = 0; i < numberOfGrades; i++) {
        /* take the modulo, if modulo <= 3 than round*/
        if (abs(grades[i] % 5 - 5) < 3) {
            if (grades[i] <= 38) {
                continue;
            }
            benefited++;
            grades[i] = grades[i] + abs(grades[i] % 5 - 5);
        }
    }
    printf("%d = %.2lf%% of the students benefited from the grading policy change.\n", benefited,
           (double) benefited / numberOfGrades);
}

/*
 * Prints all the grades out in one line
 * @param numberOfGrades - the total number of grades to be printed out
 * @param grades - a pointer to the array containing the grades
 * @return none
 */
void printGrade(int numberOfGrades, int *grades) {
    printf("The new grades are:\n");
    for (int i = 0; i < numberOfGrades; i++) {
        printf("%d ", grades[i]);
    }
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


void calculatePercent(int numberOfGrades, int *grades) {
    /* Number of A's B's C's and so fourth */
    int gradeA = 0;
    int gradeB = 0;
    int gradeC = 0;
    int gradeD = 0;
    int gradeF = 0;

    for (int i = 0; i < numberOfGrades; i++) {
        if (grades[i] >= 85) {
            gradeA++;
        } else if (grades[i] <= 84 && grades[i] >= 70) {
            gradeB++;
        } else if (grades[i] <= 69 && grades[i] >= 55) {
            gradeC++;
        } else if (grades[i] <= 54 && grades[i] >= 40) {
            gradeD++;
        } else {
            gradeF++;
        }
    }
    printf("The following is a graph that represents the grade distribution for each grade category.\n");
    printf("A: ");
    printGraph(gradeA);
    printf("B: ");
    printGraph(gradeB);
    printf("C: ");
    printGraph(gradeC);
    printf("D: ");
    printGraph(gradeD);
    printf("F: ");
    printGraph(gradeF);
}

void printGraph(int value) {
    for (int i = 0; i < value; i++) {
        printf("* ");
    }
    printf("\n");
}