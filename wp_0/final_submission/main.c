// (C) __Mariia Zabolotnia, Joel Celén, Ionel Pop, group: 8__ (2024)
// Work package 0
// Exercise 1, 2, and 3
// Submission code: 373657 (provided by your TA-s)

// Include section
#include <stdio.h>
#include <string.h>

// Main program section

/**
 * This program expects a command line argument
 * and prints the following message
 * Hello World! - I'm <provided_argument>!
 *
 * Purpose: Introduction to C programming
 * DIT633
 *
 * Author: Joel Celén, Ionel Pop, Mariia Zabolotnia 2024
 *
 **/
// Main function in the program, program arguments supported
int main(int argc, char **argv)
{
	// variable declarations
	char userInput[10]; // A buffer string with a size of 10 bytes to capture user input

	// program logic
	// If the number of arguments provided is different than 2
	if (argc != 2)
	{
		// Promt the user to input "-h" to get help
		printf("Please input \"-h\" to get help\n");

		// Get the user input and store it in userInput
		scanf("%s", userInput);

		// If the user inputs the proper help command,
		if (strcmp("-h", userInput) == 0)
		{
			// Display the proper usage of the app
			printf("To use the program, provide just one name with no spaces as a comand line argument\n");
			// Return 0 and exit the program
			return 0;
		}
		// Otherwise
		else
		{
			// Print an appropiate error message
			printf("Oops! Wrong command :(\n");
			// Return 0 and exit the program
			return 0;
		}
	}
	// Else, if the user provided '-h' as command line argument
	else if (strcmp(argv[1], "-h") == 0)
	{
		// Display instructions of the programa
		printf("To use the program, provide just one name with no spaces as a comand line argument\n");
		// Return 0 and exit the program
		return 0;
	}

	// Otherwise, the user input the proper command line arguments

	// Print the requested message using argv[1] as parameter
	printf("Hello World! - I'm %s!\n", argv[1]);

	// Return 0 and exit the program
	return 0;
}
