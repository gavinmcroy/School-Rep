#include <stdio.h>

int main() {
    /*
You found an exciting summer job for five weeks.
Suppose that the total tax you pay on your summer job income is 14%.
After paying the taxes, you spend:
You spend 10% of your net income to buy new clothes and other accessories for the next school year
You 1% to buy school supplies
AFTER buying clothes and school supplies, you save 25% of the remaining money
For each dollar you save, your parents add $0.50 additional savings

Write a program that prompts the user to enter the pay rate for an hour and
the number of hours you worked each week.

For Example, If you earned $10.00/hour and worked 10 hours per week....
the program should output the following:

//    printf("|----------|--------------------------------------------------|\n");
//    printf("| $%7.02lf | Hourly Rate                                      |\n", hourlyRate);
//    printf("|  %7.02lf | Total Hours Worked                               |\n", hoursWorked);
//    printf("|----------|--------------------------------------------------|\n");
//    printf("| $%7.02lf | Total Income before tax                          |\n", totalIncomeBeforeTax);
//    printf("| $%7.02lf | Net Income                                       |\n", netIncome);
//    printf("| $%7.02lf | Money spent on clothes and other accessories     |\n", spentOnAccessories);
//    printf("| $%7.02lf | Money spent on school supplies                   |\n", spentOnSchool);
//    printf("| $%7.02lf | Money spent on savings                           |\n", savings);
//    printf("| $%7.02lf | Money spent by parents on additional savings     |\n", parentsSavings);
//    printf("|----------|--------------------------------------------------|");
|----------|--------------------------------------------------|
| $  10.00 | Hourly Rate                                      |
|    50.00 | Total Hours Worked                               |
|----------|--------------------------------------------------|
| $ 500.00 | Total Income before tax                          |
| $ 430.00 | Net Income                                       |
| $  43.00 | Money spent on clothes and other accessories     |
| $   4.30 | Money spent on school supplies                   |
| $  95.67 | Money spent on savings                           |
| $  47.84 | Money spent by parents on additional savings     |
|----------|--------------------------------------------------|
     */
    const double totalWorkWeeks = 5;
    const double TAX = .14;
    const double MONEY_ON_ACCESORIES = .1;
    const double MONEY_ON_SCHOOL = .01;
    double hourlyRate = 0;
    double hoursWorked = 0;
    double tmp = 0;

    printf("Enter the per hour pay rate: \n");
    scanf("%lf", &hourlyRate);

    for (int i = 0; i < totalWorkWeeks; i++) {
        printf("Enter the number of hours worked for week %d: \n", i + 1);
        scanf("%lf", &tmp);
        hoursWorked += tmp;
    }

    double totalIncomeBeforeTax = hoursWorked * hourlyRate;
    double netIncome = totalIncomeBeforeTax - (totalIncomeBeforeTax * TAX);
    double spentOnAccessories = netIncome * MONEY_ON_ACCESORIES;
    double spentOnSchool = netIncome * MONEY_ON_SCHOOL;
    double savings = .25 * (netIncome - (spentOnAccessories + spentOnSchool));
    double parentsSavings = savings * .5;

    printf("|----------|----------------------------------------------|\n");
    printf("| $%7.02lf | %-45s|\n", hourlyRate,"Hourly Rate");
    printf("|  %7.02lf | %-45s|\n",hoursWorked,"Total Hours Worked");
    printf("|----------|----------------------------------------------|\n");
    printf("| $%7.02lf | %-45s|\n", totalIncomeBeforeTax,"Total Income before tax");
    printf("| $%7.02lf | %-45s|\n", netIncome,"Net Income");
    printf("| $%7.02lf | %-45s|\n", spentOnAccessories,"Money spent on clothes and other accessories");
    printf("| $%7.02lf | %-45s|\n", spentOnSchool,"Money spent on school supplies");
    printf("| $%7.02lf | %-45s|\n", savings,"Money spent on savings");
    printf("| $%7.02lf | %-45s|\n", parentsSavings,"Money spent by parents on additional savings ");
    printf("|----------|----------------------------------------------|\n");
}