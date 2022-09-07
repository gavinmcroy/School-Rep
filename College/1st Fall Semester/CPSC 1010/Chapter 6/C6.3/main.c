#include <stdio.h>
#include<stdbool.h>

void displayInformation(void);

void determineCost(int *costPerMonth, int *costPerSession);

void promptInfo(bool *seniorCitizen, int *numTraining, int *numMonth);

double calculateCost(int membershipCost, int trainingCost, bool citizen, int numSessionsBought, int numMonth);

const double SENIOR_DISCOUNT = .3;
const double YEAR_DISCOUNT = .15;
const double MORE_THAN_SIX = .2;

int main() {
    int costPerMonth;
    int costPerSession;
    bool isSeniorCitizen;
    int personalTrainingSessions;
    int monthPaidFor;

    displayInformation();
    determineCost(&costPerMonth, &costPerSession);
    promptInfo(&isSeniorCitizen, &personalTrainingSessions, &monthPaidFor);
    printf("The membership cost = $%.2lf",
           calculateCost(costPerMonth, costPerSession, isSeniorCitizen, personalTrainingSessions,
                         monthPaidFor));
    return 0;
}

void displayInformation(void) {
    printf("This program determines the cost of a new membership.\n"
           "If you are a senior citizen, then the discount is 30%% of the regular membership price.\n"
           "If you buy membership for twelve months and pay today, the discount is 15%%\n"
           "If you buy and pay for 6 or more personal training session today, the discount on each session is 20%%!\n");
}

void determineCost(int *costPerMonth, int *costPerSession) {
    printf("Enter the cost of a regular membership per month: ");
    scanf("%d", costPerMonth);
    printf("Enter the cost of one personal training session: ");
    scanf("%d", costPerSession);
}

void promptInfo(bool *seniorCitizen, int *numTraining, int *numMonth) {
    char tmp = ' ';
    printf("Are you a senior citizen (Y|y/N|n): ");
    scanf(" %c", &tmp);
    if (tmp == 'Y' || tmp == 'y') {
        *seniorCitizen = true;
    } else {
        *seniorCitizen = false;
    }
    printf("Enter the number of personal training sessions bought: ");
    scanf("%d", numTraining);
    printf("Enter the number of month you are paying for: ");
    scanf("%d", numMonth);
}

double calculateCost(int membershipCost, int trainingCost, bool citizen, int numSessionsBought, int numMonth) {
    double sum = 0;
    if (numSessionsBought >= 6) {
        sum += (1.0 - MORE_THAN_SIX) * trainingCost;
    } else {
        sum += trainingCost * numSessionsBought;
    }
    if (numMonth >= 12) {
        sum += (1.0 - YEAR_DISCOUNT) * (membershipCost * numMonth);
    } else {
        sum += (membershipCost * numMonth);
    }
    if (citizen) {
        sum *= 1.0 - SENIOR_DISCOUNT;
    }
    return sum;
}