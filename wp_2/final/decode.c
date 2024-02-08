// (C) __Mariia Zabolotnia, Joel Celén, Ionel Pop, group: 8__ (2024)
// Work package 2
// Exercise 1
// Submission code: 355721 (provided by your TA-s)

// Includes section
#include <stdio.h>
#include <stdlib.h>

// Type definitions
typedef unsigned char BYTE;

// Function prototypes
void printInstructions(BYTE output); // Function that prints the list with instructions
int hexToInt(char ascii);            // Function that turns a hex character into int
void clearBuffer();                  // Function to clear buffer after reading values

// Main function
/**
 *
 * Purpose: Work package 2: Decode
 * DIT633
 *
 * Author: Joel Celén, Ionel Pop, Mariia Zabolotnia 2024
 *
 **/
int main(int argc, char const *argv[])
{
    // If there are no given arguments except the main argument
    if (argc == 1)
    {
        // Variable declarations
        char input[3];   // Input variable
        BYTE output = 0; // Output variable to store binary representation of instructions

        // Take input
        scanf("%2s", input); // Specified to read only two characters
        clearBuffer();       // Clear buffer

        // Convert hex to int and store in variables
        int firstHex = hexToInt(input[0]);  // Convert character at index 0 to int
        int secondHex = hexToInt(input[1]); // Convert character at index 1 to int

        
        if (firstHex == -1 || secondHex == -1)
        {
            printf("Error\n");
            return 0;
        }

        // Set output byte to corresponding hex values from input
        output |= (secondHex << 0); // Set first four first bits to the value of the second hex
        output |= (firstHex << 4);  // Set first four last bits to the value of the first hex

        // Call print statement with byte representation of instructions
        printInstructions(output);
    } else {
        // Print error message
        printf("Incorrect amount of arguments, please do not provide any arguments.");
    }

    // Return 0 for successful execution
    return 0;
}

// Function to print the instructions using a byte representation
void printInstructions(BYTE output)
{
    BYTE engine = (output >> 7) & 1; // Right shift by 7, mask with 1 to get 1 bit
    BYTE gear = (output >> 4) & 7;   // Right shift by 4, mask with 7 to get 3 bits
    BYTE key = (output >> 2) & 3;    // Right shift by 2, mask with 3 to get 2 bits
    BYTE brake1 = (output >> 1) & 1; // Right shift by 1, mask with 1 to get 1 bit
    BYTE brake2 = output & 1;        // Mask with 0x01 to get 1 bit

    // Print the instructions
    printf("Name             Value\n"
           "----------------------\n"
           "engine_on           %d\n"
           "gear_pos            %d\n"
           "key_pos             %d\n"
           "brake1              %d\n"
           "brake2              %d\n",
           engine,
           gear,
           key,
           brake1,
           brake2);
}

// Function to convert a hex character to int
int hexToInt(char ascii)
{
    if (ascii >= '0' && ascii <= '9') // If character is between 0 and 9 - ascii values
    {
        return ascii - '0'; // Return character ascii value - lowest integer ascii value
    }
    else if (ascii >= 'a' && ascii <= 'f') // If character is between a and f - ascii values
    {
        return 10 + (ascii - 'a'); // Return 10 + character ascii value - lowest lowercase ascii value
    }
    else if (ascii >= 'A' && ascii <= 'F') // If character is between A and F - ascii values
    {
        return 10 + (ascii - 'A'); // Return 10 + character ascii value - lowest uppercase ascii value
    }
    return -1; // Return -1 if character is outside of allowed ranges
}

// Function to clear any remaining characters in the buffer
void clearBuffer()
{
    // Temporary integer representation of character
    int tempChar;
    // While there are more characters in the buffer, get them and discard them
    while ((tempChar = getchar() != '\n' && tempChar != EOF))
        ;
}