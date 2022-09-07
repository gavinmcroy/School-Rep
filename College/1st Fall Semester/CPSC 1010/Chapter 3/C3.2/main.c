#include <stdio.h>

int main() {

    char gender = ' ';
    int bodyWeight = 0;
    int wristMeasurement = 0;
    int waistMeasurement = 0;
    int hipMeasurement = 0;
    int foreArm = 0;

    printf("This program determines the body fat of a person.\n");
    printf("Enter your gender (f|F|m|M): \n");
    scanf("%c", &gender);

    if (gender == 'F' || gender == 'f') {
        printf("Enter body weight (in pounds): \n");
        scanf("%d", &bodyWeight);

        printf("Enter wrist measurement at fullest point (in inches): \n");
        scanf("%d", &wristMeasurement);

        printf("Enter waist measurement at navel (in inches): \n");
        scanf("%d", &waistMeasurement);

        printf("Enter hip measurement at fullest point (in inches): \n");
        scanf("%d", &hipMeasurement);

        printf("Enter forearm measurement at fullest point (in inches): \n");
        scanf("%d", &foreArm);

        double a1 = bodyWeight * 0.732 + 8.987;
        double a2 = wristMeasurement / 3.140;
        double a3 = waistMeasurement * 0.157;
        double a4 = hipMeasurement * 0.249;
        double a5 = foreArm * 0.434;
        double b = a1 + (a2 - a3 - a4) + a5;
        double bodyFat = bodyWeight - b;
        double bodyFatPercentage = (bodyFat * 100) / bodyWeight;

        printf("Body fat: %lf\n", bodyFat);
        printf("Body fat percentage: %lf\n", bodyFatPercentage);

    } else if (gender == 'M' || gender == 'm') {
        printf("Enter body weight (in pounds): \n");
        scanf("%d", &bodyWeight);

        printf("Enter waist measurement at fullest point (in inches): \n");
        scanf("%d", &waistMeasurement);

        double a1 = (bodyWeight * 1.082) + 94.42;
        double a2 = waistMeasurement * 4.15;
        double b = a1 - a2;
        double bodyFat = bodyWeight - b;
        double bodyFatPercentage = (bodyFat * 100) / bodyWeight;

        printf("Body fat: %lf\n", bodyFat);
        printf("Body fat percentage: %lf\n", bodyFatPercentage);
    } else {
        printf("Invalid gender code. ");
    }
    return 0;
}









