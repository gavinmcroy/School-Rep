/*	Julieta Paniagua
	21 October 2020
	CpSc 1110 002
	Programming Assignment Two
	This programming assignment will demonstrate the use of arrays, functions,with loops and conditionals as well as logical expressions.
	This assignment will take me 8 hours and half to complete
	This assignment took me  hours to complete.

*/
#include <stdio.h>
#include <stdbool.h>

void show(char a[9][9]);

bool isrowWin(char a[9][9]);

bool iscolWin(char a[9][9]);

bool is3by3Win(char a[9][9]);

int main(void) {

    char arr[9][9];
    int i = 0;
    int j = 0;
    char temp;

    while (scanf("%c", &temp) != EOF && i < 9) {
        if (temp == ' ') {
        } else {
            arr[i][j] = temp;
            j++;
            if (j == 10) {
                j = 0;
                i++;
            }


        }
    }

    for (i = 0; i < 9; i++) {
        for (j = 0; j < 9; j++) {
            printf("%c", arr[i][j]);
        }
        printf("\n");

        show(arr);
    }
    if (isrowWin(arr) == false) {
        printf("The sudoku grid is Invalid");
    } else {
        printf("The sudoku grid is Valid");
    }


    return 0;
}

void show(char a[9][9]) {
    printf("+---+---+---+\n");
    int i, j;

    for (i = 0; i < 9; i++) {
        //if(i%3==0) {
        //printf("\n+---+---+---+");
        //printf("\n"); }

        for (j = 0; j < 9; j++) {
            if (j % 3 == 0) {
                printf("|");
            }
            if (a[i][j] == ' ') {
                printf(" ");
            } else {
                printf("%c", a[i][j]);
            }

        }

        printf("|");
    }
    printf("\n+---+---+---+\n");
}


bool isrowWin(char a[9][9]) {
    int i, j, k;
    bool t = true;

    for (i = 0; i <= 9; i++) {
        int count[9] = {0};
        for (j = 0; j <= 9; j++) {
            switch (a[i][j]) {
                case '1':
                    count[0] += 1;
                case '2':
                    count[1] += 1;
                case '3':
                    count[2] += 1;
                case '4':
                    count[3] += 1;
                case '5':
                    count[4] += 1;
                case '6':
                    count[5] += 1;
                case '7':
                    count[6] += 1;
                case '8':
                    count[7] += 1;
                case '9':
                    count[8] += 1;

                    for (k = 0; k <= 9; k++) {
                        if (count[k] > 1) {
                            return false;
                        }
                    }

            }
        }
    }
    return t;
}

bool iscolWin(char a[9][9]) {
    return true;
}

bool is3by3Win(char a[9][9]) {
    return true;
}




 
	

	

