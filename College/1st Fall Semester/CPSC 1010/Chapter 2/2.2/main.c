#include <stdio.h>

int main() {
    /*
     * A milk carton can hold 3.78 liters of milk.
     * Each morning, a dairy farm ships cartons of milk to a local grocery store.
     * The cost of producing one liter of milk is $0.38, and the
     * profit of each carton of milk is $0.27.
     * Write a program that does the following:
     * Prompts the user to enter the total amount of milk produced in liters.
     * Outputs the number of milk cartons needed
     * to hold milk. (Round your answer to the nearest integer.)
     * Outputs the cost of producing the milk.
     * Outputs the profit from producing the milk.

     * For example:
     * Enter, in liters, the total quantity of milk produced: 3.78
     * The number of milk cartons needed to hold milk: 1
     * The cost of producing milk: $ 1.44
     * Profit: $ 0.27
     */
    double litersProduced = 0;
    const double cartonSizeLiters = 3.78;
    const double costPerLiter = .38;
    const double profitPerCarton = .27;
    printf("Enter, in liters, the total quantity of milk produced: ");
    scanf("%lf",&litersProduced);
    int cartonsProduced = litersProduced/cartonSizeLiters;
    printf("The number of milk cartons needed to hold milk: %.0lf\n", litersProduced / cartonSizeLiters);
    printf("The cost of producing milk: $%.2lf\n",costPerLiter*litersProduced);
    printf("Profit: $%.2lf \n",(cartonsProduced)*profitPerCarton);
    return 0;
}