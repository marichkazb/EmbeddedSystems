// Include section
#include <stdio.h>
#include <stdlib.h>

// TODO: ask if it's ok to format it like this 6 -> 110 instead of 0110
// I'm confused because of the example

// Function declarations
void printBinary(int decNumber);    // Helper function to format
int isValidNumber(char* str);       // Helper function that checks if user input is valid

/**
 * This program expects an integer and returns its representation
 * in binary alongside the number of 1s and 0s it has
 * 
 * Purpose: Bonus question work package 1
 * DIT633
 * 
 * Author: Ionel Pop, 2024
 * 
**/
int main(int argc, char** argv)
{
    // If the number of provided arguments is less than 2
    if (argc < 2)
    {
        // Print an appropiate error message
        printf("Error: No number provided. Please provide a number as a command line argument.\n");
        // Return 0 and exit the program
        return 0;
    }
    // Otherwise, if it's not a valid number
    else if (isValidNumber(argv[1]) == 0)
    {
        // Print an appropiate error message
        printf("Error: Invalid number.\n");
        // Return 0 and exit the program
        return 0;
    }

    // If the provided argument was in fact a valid number,
    // cast it and pass it to the function
    printBinary(atoi(argv[1]));
}

void printBinary(int decNumber)
{
    // print the number
    printf("Number: %d\n", decNumber);

    int zeroCount = 0;  // local variable to keep track of the number of 0s
    int oneCount = 0;   // local variable to keep track of the number of 1s

    // print the prefix of the binary representation
    // this is the start of the output
    printf("Binary: 0b");

    int numberOfDigits = 0;     // Variable to keep track of the number of digits
    int original = decNumber;   // Temporary variable to count the number of digits
    
    /**
     * To get the number of digits,
     * divide the number by 2,
     * until it reaches 0
     * 
     * For example:
     * 8 can be divided 4 times -> 1000
    */
    while (original != 0)
    {
        original /= 2;
        numberOfDigits++;
    }

    /**
     * To print the binary representation,
     * we start from the last digit.
     * 
     * For example, if we want to print 4,
     * we start from i = 2
     * 
     * 4 >> 2 -> 0b100 >> 2 -> 0b001,
     * -> 0b001 & 0b001 = 0b001,
     * therefore we print a [1] and we update the count of 1s to 1
     * 
     * 4 >> 1 -> 0b100 >> 1 -> 0b010
     * -> 0b010 & 0b001 = 0b000,
     * therefore we print a [0] and we update the count of 0s to 1
     * 
     * 4 >> 0 -> 0b100 >> 0 -> 0b100
     * -> 0b100 & 0b001 = 0b000,
     * therefore we print a [0] and we update the count of 0s to 1
     * 
     * Finally, we print a new line to end the binary representation,
     * and we print the number of 0s and 1s
     * 
     */
    for (int i = numberOfDigits - 1; i >= 0; i--)
    {
        // shift decNumber i spaces to the right and
        // perform an & operation with 1 as explained above
        // if the digit is a 1
        if (decNumber >> i & 1)
        {
            // print 1
            printf("1");
            // update the count of 1s
            oneCount++;
        }
        // else if it's a 0
        else
        {
            // print 0
            printf("0");
            // update the count of 0s
            zeroCount++;
        }
    }
    printf("\n");

    printf("Number of 0s: %d\n", zeroCount);
    printf("Number of 1s: %d\n", oneCount);
}

int isValidNumber(char* str)
{
    while(*str != '\0')
    {
        // If it's not a proper number
        if (*str < 48 || *str > 57 )
        {
            return 0;
        }

        *str++;
    }

    return 1;
}

/*
Number: 3
Binary: 0b11
Number of 0s: 0
Number of 1s: 2
*/

/*
My thought process:

2 -> 10
2 << 1

5 -> 101
5 >> 2 -> 001 -> & 1 -> 1
5 >> 1 -> 010 -> & 1 -> 0
5 >> 0 -> 101 -> & 1 -> 1

6 -> 110 | numberOfDigits = 3
6 >> 2 -> 001 -> & 1 -> 1
6 >> 1 -> 011 -> & 1 -> 1
6 >> 0 -> 110 -> & 1 -> 0
*/