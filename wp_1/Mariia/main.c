// Include section
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

/**
 * This program takes an input number from user and outputs its representation in binary
 * along with the amount of 0s and 1s in its binary representation.
 *
 * Purpose: Get hands-on experience in bitwise operations and practice transforming a decimal number to binary.
 * DIT633
 *
 * Author: Mariia Zabolotnia, 2024
 *
 **/

// declaration of the main function
int main(int argc, char **argv)
{
    // assign the input from user to a variable. Since user input comes as a string presented in array of chars,
    // then it is assigned to an array of chars with a pointer to the first bit.
    char *userInput = argv[1];
    // Start of error handling
    if (argc < 2) // count of arguments is expected to be 2, 1st being the name of the program
    // and 2nd being user input as a command line argument. If amount is less than 2, then user didn't provide the number.
    {
        // print a prompt for the user in case there is no command line argument.
        printf("Error: No number provided. Please provide a number as a command line argument.\n");
        // terminate the program
        return 0;
    }
    // declare a counter for iterating the while loop
    int i = 0;
    // start iterating on the string until we encounter the end of it denoted by \0
    while (userInput[i] != '\0')
    {
        // check if every number in user input is a digit utilizing in-built function
        if (!isdigit(userInput[i]))
        {
            // in case it is not a digit, the user is prompted with error message
            printf("Error: Invalid number.\n");
            // terminate the program
            return 0;
        }
        // increase counter to continue iterating
        i++;
    }
    // print the number inputted by the user in the decimal representation
    printf("Number: %s\n", userInput);
    // convert the number from string to integer
    int numb = atoi(userInput);
    // declare variable to keep track of 0s in the binary version of the number
    int numOfZeros = 0;
    // declare variable to keep track of 1s in the binary version of the number
    int numOfOnes = 0;
    // calculate the number of bits that will be reserved for the number
    int numSize = sizeof(numb) * 8;
    // declare a variable to act as a bool to keep track of the leading 0s that should not be displayed when printing the number
    int endOfLeadingZeros = 0;
    // print placeholder for binary representation
    printf("Binary: 0b");
    // iterate through the number starting from the last digit
    for (int i = numSize - 1; i >= 0; i--)
    {
        // shift i bits in the numbers with the mask of 1 bit in order to determine the value of the number
        if (numb >> i & 1)
        {
            // change the variable to true, since we encountered the first one meaning there are no more leading zeros
            endOfLeadingZeros = 1;
            // add 1 to the bool representation of the number
            printf("1");
            // increase counter for the amount of 1s in the number
            numOfOnes++;
        }
        // in case all leading zeros are omitted and the encountered 0 is already the part of the number
        else if (endOfLeadingZeros)
        {
            // add 0 to the bool representation of the number
            printf("0");
            // increase counter for the amount of 0s in the number
            numOfZeros++;
        }
    }
    // insert line break for better formatting
    printf("\n");
    // print the amount of 0s and 1s in the binary version of the number
    printf("Number of 0s: %i\nNumber of 1s: %i\n", numOfZeros, numOfOnes);
    // terminate the program
    return 0;
}