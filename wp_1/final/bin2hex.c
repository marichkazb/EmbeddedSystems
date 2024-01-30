// (C) __Mariia Zabolotnia, Joel Celén, Ionel Pop, group: 8__ (2024)
// Work package 1
// Exercise 4.2
// Submission code: 098890 (provided by your TA-s)

// Includes section
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>

// ------ Function definitions ----------
// Declare a helper function that will take the arguments and convert binary numbers to hex values
int validateAndConvert(int argc, char **argv);
// Declare a helper function that is responsible for converting bin to hex
void bin2hex(char *binaryNum);

/**
 *
 * Purpose: Learning C programming
 * DIT633
 *
 * Author: Joel Celén, Ionel Pop, Mariia Zabolotnia 2024
 *
 **/
// ------ Function definitions ----------
// The main entry point for the program
int main(int argc, char **argv)
{
    // Call the helper functions with argc and argv parameters from user input
    validateAndConvert(argc, argv);
    // terminate the program
    return 0;
}

// function to convert binary to hexadecimal
void bin2hex(char *binaryNum)
{
    unsigned long dec = strtol(binaryNum, NULL, 2);
    // print the hexadecimal number
    printf("%lX\n", dec);
    // terminate the program with exit code 0
    exit(0);
}
// declare helper function to validate and convert the number from binary to hexadecimal
int validateAndConvert(int argc, char **argv)
{
    if (argc < 2) // if two programs are run in a pipeline and there are no command line arguments
    {
        char binary[10000]; // declare variable to store value of the bin from pipeline
        // scan bin value from the previous program in pipeline
        if (scanf("%s", binary) != 1)
        {
            // print error message
            printf("Error reading binary input\n");
            // terminate the program
            return 0;
        }
        bin2hex(binary);
    }
    // declare variable to store pointer to the entered command line arguments
    char *userInput = argv[1];
    // if users asks for help, read user input and check if it is -h meaning command to display help
    if (strcmp(userInput, "-h") == 0)
    {
        // print user message with instructions
        printf("Please, input the decimal number and you will get its binary representation");
        // terminate the program
        return 0;
    }
    int i = 0;
    while (userInput[i] != '\0')
    {
        // check if every number in user input is a binary number since the program is to convert binary to hex
        if (userInput[i] != '0' && userInput[i] != '1')
        {
            // in case it is not a digit, the user is prompted with error message
            printf("Error: Invalid number\n");
            // terminate the program with exit code 2
            exit(2);
        }
        // increase counter to continue iterating
        i++;
    }
    bin2hex(argv[1]);
    // terminate the program
    return 0;
}