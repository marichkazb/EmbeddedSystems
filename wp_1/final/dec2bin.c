// (C) __Mariia Zabolotnia, Joel Celén, Ionel Pop, group: 8__ (2024)
// Work package 1
// Exercise 4.1
// Submission code: 098890 (provided by your TA-s)

// Includes section
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <errno.h>

/**
 *
 * Purpose: Learning C programming
 * DIT633
 *
 * Author: Joel Celén, Ionel Pop, Mariia Zabolotnia 2024
 *
 * TA Code: 098890
 *
 **/

// The main entry point for the program
int main(int argc, char **argv)
{
    // save user input from command line to the variable of type long
    unsigned long userInput = atol(argv[1]);
    // declare variable to store amount of bits
    int bits = 0;
    // utilizing the loop calculate amount of bits in the user input number
    while (userInput > 0)
    {
        // shift the bits by one in every iteration
        userInput >>= 1;
        // increase the counter by one
        bits++;
    }
    // min size of num
    int numSize = 8;
    // declare the array of break points of bit sizes to be able to switch between them
    int bitSizes[4] = {8, 16, 32, 64};
    // iterate on the number to identify the min size data type for it
    for (int i = 0; i < sizeof(bitSizes); i++)
    {
        // find the least amount of bites in the bytes array
        if (bitSizes[i] >= bits)
        {
            // assign number size to the least found size
            numSize = bitSizes[i];
            // terminate the loop
            break;
        }
    }
    // iterate until the end of the number of size to bit shift
    for (int i = numSize - 1; i >= 0; i--)
    {
        // bitshift digits and compare to mask of 1 to print the binary representation of the number
        long convertedNum = atol(argv[1]) >> i & 1;
        // print the result of conversion
        printf("%lu", convertedNum);
    }
    // print the new line for better formatting
    printf("\n");
    // terminate the program
    return 0;
}
