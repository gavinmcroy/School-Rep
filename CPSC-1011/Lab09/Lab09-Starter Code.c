
const int MAX_SIZE = 20;

typedef struct romanNumeral_struct {
	// YOUR STRUCT GOES HERE
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
	This funciton takes a valid Roman Numeral struct and prints out the roman number 
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
