#include <stdio.h>

int main() {
/*
 *  Lab03.c
 *  Author: Gavin McRoy
 *  Lecture, Lab Section: CPSC 1010-100, CPSC 1011-100-005
 *  Lab #: 3
 *  submitted on: 9/11/2019
 *  Purpose: Calculates predicted income and tax given hours worked in a week
 *  Academic Honesty Declaration: * The following code represents my own
 *  work and I have neither received nor given assistance that violates
 *  the collaboration policy posted with this assignment. I have not copied
 *  or modified code from any other source other than the lab
 *  assignment, course textbook, or course lecture slides. Any unauthorized
 *  collaboration or use of materials not permitted will be subjected to
 *  academic integrity policies of Clemson University and CPSC 1010/1011.
 *  * I acknowledge that this lab assignment is based upon an assignment
 *  created by Clemson University and that any publishing or
 *  posting of this code is prohibited unless I
 *  receive written permission from Clemson University.
*/
    const double taxRate = .1905;
    double hourlyRate = 7.25;
    const double federalDeductions = .5249;
    const double stateDeductions = .0736;
    const double fica = .3255;
    const double medicare = .076;
    int hoursWorked = 0;

    printf("Enter hours worked: \n");
    scanf("%d", &hoursWorked);
    printf("Enter hourly rate: \n");
    scanf("%lf",&hourlyRate);

    double grossPay = hoursWorked * hourlyRate;
    const double taxDeduction = grossPay * taxRate;

    printf("Hours per Week :     $%d\n", hoursWorked);
    printf("Hourly Rate:         $%.2lf\n", hourlyRate);
    printf("Gross Pay:           $%.2lf\n", grossPay);
    printf("Net Pay:             $%.2lf\n", grossPay - (grossPay * taxRate));
    printf("Deductions Federal:  $%.2lf\n", taxDeduction * federalDeductions);
    printf("State:               $%.2lf\n", taxDeduction * stateDeductions);
    printf("FICA:                $%.2lf\n", taxDeduction * fica);
    printf("Medicare:            $%.2lf\n", taxDeduction * medicare);
    return 0;
}