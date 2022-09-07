#include <stdio.h>

int main() {

    double scores[5];
    double sum = 0;
    double max = 0;
    double min = 0;

    for (int i = 0; i < 5; i++) {
        double tmp = 0;
        printf("Enter Score %d:", i + 1);
        scanf("%lf", &tmp);
        if (tmp <= 100 && tmp >= 0) {
            scores[i] = tmp;
        } else {
            printf("Invalid Input\n");
            i--;
        }
    }
    printf("\n");

    printf("You entered: ");
    for (int i = 0; i < 5; i++) {
        if (i < 4) {
            printf("%lf, ", scores[i]);
        } else {
            printf("%lf\n", scores[i]);
        }
    }

    for (int i = 0; i < 5; i++) {
        sum += scores[i];
    }

    printf("Total Score: %lf\n", sum);
    printf("Average Score: %lf\n", sum / 5);

    //---highest score
    max = scores[0];
    min = scores[0];

    for (int i = 0; i < 5; i++) {
        if (scores[i] > max) {
            max = scores[i];
        }
        if (scores[i] < min) {
            min = scores[i];
        }
    }
    printf("Max Score: %lf\n", max);
    printf("Min Score: %lf\n", min);

    return 0;
}