// (C) __Mariia Zabolotnia, Joel Celén, Ionel Pop, group: 8__ (2024)
// Work package 2
// Exercise 1
// Submission code: 355721 (provided by your TA-s)

// Include section
#include <stdio.h>
#include <stdlib.h>

// Type definitions
typedef unsigned char BYTE;

// Function prototypes
void invalidNumber(); // If integer is outside of allowed range,prints error message and exits the program

// Main function
/**
 *
 * Purpose: Work package 2: Code
 * DIT633
 *
 * Author: Joel Celén, Ionel Pop, Mariia Zabolotnia 2024
 *
 **/
int main(int argc, char const *argv[])
{
    // If the amount of arguments are correct
    if (argc == 6)
    {
        // Variable declarations
        BYTE output = 0;                       // Initialize output byte to 0000 0000
        int brake2, brake1, key, gear, engine; // Declare car instructions

        // If all arguments are within the correct range
        if ((*argv[5] >= '0' && *argv[5] <= '1') && // if brake2 argument is either 0 or 1 AND
            (*argv[4] >= '0' && *argv[4] <= '1') && // if brake1 argument is either 0 or 1 AND
            (*argv[3] >= '0' && *argv[3] <= '2') && // if key argument is either 0, 1 or 2 AND
            (*argv[2] >= '0' && *argv[2] <= '7') && // if gear argument is between 0 and 7 AND
            (*argv[1] >= '0' && *argv[1] <= '1'))   // if engine argument is either 0 or 1
        {
            // Convert ascii value of input to integer
            brake2 = atoi(argv[5]); // Break2 argument ascii converted to int
            brake1 = atoi(argv[4]); // Break1 argument ascii converted to int
            key = atoi(argv[3]);    // Key argument ascii converted to int
            gear = atoi(argv[2]);   // Gear argument ascii converted to int
            engine = atoi(argv[1]); // Engine argument ascii converted to int

            output |= (brake2 << 0);  // Set bit no 0 to value of brake2
            output |= (brake1 << 1);  // Set bit no 1 to value of brake1
            output |= (key << 2);     // Set bit no 2 and 3 to value of key
            output |= (gear << 4);    // Set bit no 4, 5, and 6 to value of gear
            output |= (engine << 7);  // Set bit no 7 to value of engine
            printf("%02X\n", output); // Print byte as hexadecimal, with at least two digits
        }
        else // If any of the entered arguments are outside of accepted integer range
        {
            // Call invalidNumber function
            invalidNumber();
        }
    }
    else // Number of entered arguments is not exactly 5
    {
        // Print error message
        printf("Wrong amount of arguments entered.\n");
        // Return 1 for faulty execution
        return 1;
    }
    // Return 0 for successful operation
    return 0;
}

// Function to print error message and exit the program
void invalidNumber()
{
    // Print error message
    printf("Arguments are outside of allowed range. Please enter in the following order:\n"
           "Engine   Gear   Key   Brake1   Break2\n"
           "0-1      0-7    0-2   0-1      0-1\n");
    // Exit program with error code 1
    exit(1);
}