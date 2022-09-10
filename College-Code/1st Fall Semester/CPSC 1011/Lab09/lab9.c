#include<stdio.h>
#include<stdbool.h>
#include<string.h>

const int MAX_SIZE = 20;

typedef struct romanNumeral_struct {
    char numeral[100];
    int romanInDecimal;
} romanNumeral;

/*
	This function prompts the user for a Roman Numeral
	and calls ProperRoman to validate the input until
	a valid Roman Numeral is entered or the user types EXIT
	to end the program.

	When the Roman Numeral is valid, the function returns true.

	When EXIT is entered, the function returns false.
*/
bool Prompt(char romanNumeral[], int maxSize);
/*
	This function takes a Roman Numeral and validates that only
	legal digits have been entered.

	The function returns true when a valid Roman Numeral is entered, otherwise
	it returns false.
*/
bool ProperRoman(const char romanNumeral[]);

/*
	This Function takes a valid Roman Numeral struct, calculates the integer
	equivalent, and returns the updated struct.
*/
romanNumeral ConvertRoman(romanNumeral romanNumeralToConvert);

/*
	This function takes a valid Roman Numeral struct and prints out the roman number
	and integer value nicely formatted as:
	XX = 20
*/
void PrintRoman(romanNumeral romanNumeralToConvert);

int main(void) {
    romanNumeral myRoman;
    while (Prompt(myRoman.numeral, MAX_SIZE)) {
        myRoman = ConvertRoman(myRoman);
        PrintRoman(myRoman);
    }
    printf("Thank you for using the Roman Numeral to Decimal calculator.\nGoodbye!\n");
}

bool Prompt(char romanNumeral[], int maxSize) {
    bool isProperRoman = false;
    while (true) {
        printf("Please input a value in Roman numerals or EXIT to quit: ");
        scanf("%s", romanNumeral);
        if (strlen(romanNumeral) > maxSize) {
            printf("Error! Too many characters!! Roman Number must be less than 21 characters long\n");
            continue;
        }
        isProperRoman = ProperRoman(romanNumeral);
        if ((strcmp(romanNumeral, "EXIT") == 0)) {
            return false;
        }
        if (isProperRoman) {
            return true;
        } else {
            printf("Illegal Characters.\n");
        }
    }
}

bool ProperRoman(const char romanNumeral[]) {
    char eachNumeral[7] = {'M', 'D', 'C', 'L', 'X', 'V', 'I'};
    int sumFound = 0;
    for (int i = 0; i < strlen(romanNumeral); i++) {
        for (int j = 0; j < strlen(eachNumeral); j++) {
            if (romanNumeral[i] == eachNumeral[j]) {
                sumFound++;
            }
        }
    }
    //---if sum found doesnt equal the entered numerals than it must be an illegal string
    return (sumFound == strlen(romanNumeral)) ? true : false;
}

romanNumeral ConvertRoman(romanNumeral romanNumeralToConvert) {
    int previousVal = 0;
    int currentVal = 0;
    int sum = 0;
    bool ignoreFirstRun = true;
    for (int i = 0; i < strlen(romanNumeralToConvert.numeral); i++) {
        if (romanNumeralToConvert.numeral[i] == 'M') {
            currentVal = 1000;
        } else if (romanNumeralToConvert.numeral[i] == 'D') {
            currentVal = 500;
        } else if (romanNumeralToConvert.numeral[i] == 'C') {
            currentVal = 100;
        } else if (romanNumeralToConvert.numeral[i] == 'L') {
            currentVal = 50;
        } else if (romanNumeralToConvert.numeral[i] == 'X') {
            currentVal = 10;
        } else if (romanNumeralToConvert.numeral[i] == 'V') {
            currentVal = 5;
        } else if (romanNumeralToConvert.numeral[i] == 'I') {
            currentVal = 1;
        } else {
            break;
        }

        //---To prevent subtracting the value just added multiply by two to properly remove numeral in front
        if (currentVal > previousVal && !ignoreFirstRun) {
            currentVal -= previousVal * 2;
            sum += currentVal;
        } else {
            sum += currentVal;
        }
        previousVal = currentVal;
        ignoreFirstRun = false;
    }
    romanNumeralToConvert.romanInDecimal = sum;
    return romanNumeralToConvert;
}

void PrintRoman(romanNumeral romanNumeralToConvert) {
    printf("%s = %d\n\n", romanNumeralToConvert.numeral, romanNumeralToConvert.romanInDecimal);
}




