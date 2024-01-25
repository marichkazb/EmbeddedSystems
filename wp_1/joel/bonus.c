// Includes section
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * This program takes a string (represented as an integer) and prints the binary representation
 *
 * Purpose: To learn basic bitwise operations
 * DIT633
 *
 * Author: Joel Celén, 2024
 *
 **/

// Main argument declaration
int main(int argc, char const *argv[])
{

    // If there not exactly ONE input argument + main argument, eg two agruments in total
    if (argc != 2)
    {
        // Print error message
        printf("Error: No number provided. Please provide a number as a command line argument.\n");
        // Return 1 for unsuccessful execution, beacuse of code grade this is 0
        return 0;
    }

    // Iterate through every caharcter of the user input
    for (int i = 0; i < strlen(argv[1]); i++)
    {
        // Save the i-th character of the input as a variable
        char characterInput = argv[1][i];

        // Cast "characterInput" to int to get the ASCII value
        int asciiValue = (int)characterInput;

        // If ANY character is outside of ASCII value range for integers (48 - 57)
        if (asciiValue < 48 || asciiValue > 57)
        {
            // Print error message
            printf("Error: Invalid number.\n");
            // Return 1 for unsuccessful execution, beacuse of code grade this is 0
            return 0;
        }
    }

    // Convert the argument given by the user from string to integer and store it in memory
    int value = atoi(argv[1]);

    // Declare a pointer to the first bit in the array of integers where "value" resides
    int *pointer = &value;

    // Amount of bits that the integer reserves in memory, eg bytes * 8
    int numBits = sizeof(value) * 8;

    // Initialize counter for 0s to 0
    int zeroCounter = 0;

    // Initialize counter for 1s to 0
    int oneCounter = 0;

    // Initialize a "boolean" value as one bit
    unsigned char startCount = 0;

    // Print statements for the information
    printf("Number: %d\n", value);
    printf("Binary: 0b");

    // Iterates from the last bit to the first
    for (int i = numBits - 1; i >= 0; --i)
    {
        // Bitshifts i spaces and uses AND(bit operator) with mask value of 0b1 to get the value of the i-th bit
        int currentBit = (*pointer >> i) & 1;

        // Turn startCount to true
        if (currentBit == 1 || i == 0) // at the first occurance of a bit with value 1 OR(logical operator) at bit number 1
        {
            // Change "boolean" variable to true
            startCount = 1;
        }

        // If statement for counting number of ones and zeros
        if (currentBit == 1) // If currentBit == 1
        {
            // If bit is 1, always increment the oneCounter
            oneCounter++;
        }
        else if (currentBit == 0 && startCount == 1) // If currentBit == 0 AND startCount is true
        {
            // If startCount is true, and bit is 0, increment zeroCounter
            zeroCounter++;
        }

        // Print bit values
        if (startCount == 1) // If 1 encountered in bit or at bit number 1
        {
            printf("%d", currentBit);
        }
    }

    // New line
    printf("\n");

    // Print counters for 1's and 0's
    printf("Number of 0s: %d\n", zeroCounter);
    printf("Number of 1s: %d\n", oneCounter);

    // return 0 for successful execution
    return 0;
}
