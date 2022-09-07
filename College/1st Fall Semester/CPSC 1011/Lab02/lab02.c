//---Gavin McRoy
//---C11633100
//---CPSC 1011-005
//---Lab 2 Excercise 1

#include <stdio.h> //Missing . before h

int main (void) { //---Missing Curly Brace
		
        //---Changed to double and changed %d to %lf
        //---Added const to avoid magic numbers
	double const kilometerInMile = 1.60934;
	double kilometers;
	double miles;

	printf("\n"); //---Missing Quotation
	printf("Please enter the distance in miles: ");
	scanf("%lf", &miles); //---Missing Quotation //---Missing semicolon
	printf("\n"); //---print instead of printf

	kilometers = kilometerInMile * miles;

	printf("%.2lf miles is equal to ", miles); //---Remove % infront of i
	printf("%.2lf kilometers", kilometers); //--- No Semi Colon, Remove .2d , Remove Address operator
	printf("\n\n");

	return 0;
}
