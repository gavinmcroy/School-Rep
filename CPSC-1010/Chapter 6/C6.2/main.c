#include <stdio.h>

void initialize(int *one, int *two, char *ch);

void getHoursRate(double *hrs, double *pRate);

double payCheck(double hrs, double pRate);

void printCheck(double hrs, double pRate, double pSalary);

void funcOne(int *pOne, int pTwo);

void nextChar(char *ch);

int main() {
    int x, y;
    char z;
    double rate, hours;
    double amount;

    initialize(&x, &y, &z);

    printf("After initialization: x = %d, y = %d, z = %c\n", x, y, z);

    getHoursRate(&hours, &rate);
    amount = payCheck(hours, rate);
    printCheck(hours, rate, amount);

    x = 35;
    y = 20;
    printf("Before calling funcOne: x = %d, y = %d\n", x, y);
    funcOne(&x, y);
    printf("After funcOne: x = %d\n", x);

    //z = 'B';
    printf("Before nextChar z = %c\n", z);
    nextChar(&z);
    printf("After nextChar: z = %c\n", z);

    return 0;
}

void initialize(int *one, int *two, char *ch) {
    *one = 0;
    *two = 0;
    *ch = '~';
}

void getHoursRate(double *hrs, double *pRate) {
    printf("Enter hours worked: ");
    scanf("%lf", hrs);
    printf("Enter pay rate: ");
    scanf("%lf", pRate);
}

double payCheck(double hrs, double pRate) {
    double cash = 0.0;
    if (hrs > 40) {
        hrs -= 40;
        cash += hrs * (pRate * 1.5);
        cash += 40 * pRate;
        return cash;
    } else {
        cash = hrs * pRate;
        return cash;
    }
}

void printCheck(double hrs, double pRate, double pSalary) {
    printf("Hours worked: %lf\n", hrs);
    printf("Pay Rate: $%lf\n", pRate);
    printf("This week's salary: $%lf\n", pSalary);
}

void funcOne(int *pOne, int pTwo) {
    int val = 0;
    printf("Enter an integer: ");
    scanf("%d", &val);
    *pOne = (*pOne) * (2) + pTwo - val;
}

void nextChar(char *ch) {
    char tmp = ' ';
    printf("Enter a character: ");
    scanf(" %c", &tmp);
    *ch = tmp + 1;
}

