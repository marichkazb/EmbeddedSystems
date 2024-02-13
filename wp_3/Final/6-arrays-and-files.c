// (C) __Mariia Zabolotnia, Joel Celén, Ionel Pop, group: 8__ (2024)
// Work package 3
// Exercise 2
// Submission code: xxxxxx (provided by your TA-s)

/** ----- Instructions -----
 * Write a program that reads in a string with a maximum of 20 characters from the keyboard
 * and stores the string in a local string variable.
 *
 * Copy the string to another string by using:
 *      a) The library function strcpy(..)
 *      b) Your own function void copyString(...) not using any library function.
 *
 * Main program ends by printing out the copied string in the console.
 * The program should be able to both read in from keyboard
 * or from a text file ‘myfile.txt’ containing one string of characters.
 * You create this file with notepad or any other text editor.
 * The reading from the text file should be done by redirect the readings
 * from command line when program execution starts as follows:
 * Exerc_2_1 < myfile.txt
 * Where Exerc_2_1 is the filename of the compiled program.
 * You shall not use standard file managing by opening the file and the read from it.
 **/

// Include section
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define section
#define MAX 21 // 20 characters + '\0'

// Function prototypes
void copyString(char *pInStart, char *pInEnd, char *pOutStart);

// Main function
int main(int argc, char const *argv[])
{
    // Declare input and output strings
    char input[MAX];  // Input goes into this
    char output[MAX]; // Copied string goes into this

    // Declare and initialize pointers
    char *pInStart = &input[0];     // Pointer to the first element of the input
    char *pInEnd = &input[MAX - 1]; // Pointer to the last element of the input
    char *pOutStart = &output[0];   // Pointer to the first element of the output

    // Prompt user to input a string
    printf("Please provide a string of max 20 characters:\n");
    // Take input from user OR from a .txt file if file redirection was used
    fgets(pInStart, MAX, stdin);

    // Copy input string to output string
    copyString(pInStart, pInEnd, pOutStart);

    // Print result of output string
    printf("Input was: %s\n", output);

    // Return 0 for successful execution
    return 0;
}

// Custom string copy function using pointer arithmetics
void copyString(char *pInStart, char *pInEnd, char *pOutStart)
{
    // Declare current pointers
    char *pInCurrent = pInStart;   // Initialize to start of input
    char *pOutCurrent = pOutStart; // Initialize to start of output

    // For every character in input
    while (pInCurrent <= pInEnd) // While end has not been reached
    {
        // Current value of output takes current value of input
        *pOutCurrent = *pInCurrent;

        pInCurrent++;  // Increment current pointer input
        pOutCurrent++; // Increment current pointer output
    }
}