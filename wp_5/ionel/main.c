// Include section
#include <stdio.h>

// Define section
#define NUMBER_OF_ARGUMENTS 6 // Correct number of command line arguments the program needs
#define ENGINE_ON 7           // Number of bitshifts needed to store ENGINE_ON
#define FLOOR_POS 4           // Number of bitshifts needed to store FLOOR_POS
#define DOOR_POS 2            // Number of bitshifts needed to store DOOR_POS
#define BRAKE1 1              // Number of bitshifts needed to store BRAKE1
#define BRAKE2 0              // Number of bitshifts needed to store BRAKE2

/**
 * Define a new type byte that stores an unsigned char
 * to store the elevator bits
 */
typedef unsigned char byte;

/**
 * Helper function to get the length of a string
 *
 * INPUT:
 *  input: the input string to check
 *
 * OUTPUT:
 *  The length of the string
 */
int stringLength(char *input);

/**
 * Helper function that checks if a given string
 * is a digit.
 *
 * INPUT:
 *  input: the input string to check
 *
 * OUTPUT:
 *  If valid, it returns the digit, otherwise it
 *  returns -1
 */
int isDigit(char *input);

/**
 * Function that checks that the user input is in the proper format
 * for all bits to be valid
 *
 * INPUT:
 *  argv: The command line arguments the user input
 *  outputArray: An integer array that will store the bits the user input
 *
 * OUTPUT:
 *  None but if successful, outputArray will contain all the bits the user input
 */
int validateInput(char **argv, int *outputArray);

// Main program
int main(int argc, char **argv)
{
    // Check that the user input the correct number of arguments
    if (argc != NUMBER_OF_ARGUMENTS)
    {
        // If the number of arguments is not correct, output an error message
        printf("Error. Invalid number of arguments\n");
        printf("Please input a valid sequence of bits\n");
        // Return 0 and stop the execution of the program
        return 0;
    }

    int userInput[5];        // Array to store the bits the user input
    byte elevatorBits = 0b0; // byte that stores the elevator bits

    // If the input is not valid
    if (validateInput(argv, userInput) == 0)
    {
        // Return 0 and stop the execution of the program
        return 0;
    }

    /**
     * Assign each bit in elevatorBits to the corresponding user input
     */

    int i = 0;

    // Assign the ENGINE_ON bit
    elevatorBits ^= userInput[i++] << ENGINE_ON; //  1 << 7 -> 1 << 7 -> 1000 0000

    // Assign the FLOOR_POS bits
    elevatorBits ^= userInput[i++] << FLOOR_POS; // 7 << 4 -> 111 << 4 -> 0111 0000

    // Assign the DOOR_POS bits
    elevatorBits ^= userInput[i++] << DOOR_POS; // 3 << 2 -> 11 << 2 -> 0000 1100

    // Assign the BRAKE1 bit
    elevatorBits ^= userInput[i++] << BRAKE1; // 1 << 1 -> 1 << 1 -> 0000 0010

    // Assign the BRAKE2 bit
    elevatorBits ^= userInput[i++] << BRAKE2; // 1 << 0 -> 1 << 0 -> 0000 0001

    // Print the byte elevatorBits in hexadecimal with the proper format
    printf("0x%X\n", elevatorBits);

    // Return 0 and successfully finish the program
    return 0;
}

int stringLength(char *input)
{
    int length = 0; // Length of the string

    // Iterate through the string until we fin a null terminator
    while (*input != '\0')
    {
        // Increment the length counter
        length++;
        // Move the pointer to the next element
        input++;
    }

    // Return the length of the string
    return length;
}

int isDigit(char *input)
{
    // If the length of the string is different than 1, it is not a digit (0 - 9)
    if (stringLength(input) != 1)
    {
        // Return -1 to signify that it's not a digit
        return -1;
    }

    // If the character is between 0 and 9
    if (*input >= '0' && *input <= '9')
    {
        // Return the character as a number (int)
        return *input - '0';
    }
    // Otherwise
    else
    {
        // Return -1 to signify that it's not a digit
        return -1;
    }
}

int validateInput(char **argv, int *outputArray)
{
    // Iterate through all the command line arguments
    for (int i = 1; i < NUMBER_OF_ARGUMENTS; i++)
    {
        int digit = isDigit(argv[i]); // Current command line argument digit

        // If the digit is less than 0
        if (digit < 0)
        {
            // Print an appropiate error message
            printf("Error. Invalid argument\n");
            printf("Argument %d should be a valid digit\n", i);

            // Return 0 to signify that it is not a valid digit
            return 0;
        }

        // If the ENGINE_ON bits are greater than 3 bits
        if (i == 2 && digit > 0b111)
        {
            // Print an appropiate error message
            printf("Error. Invalid argument\n");
            printf("Argument %d should consist of maximum of 3 bits\n", i);

            // Return 0 to signify that it is not a valid sequence of bits
            return 0;
        }
        // Else if the FLOOR_POS bits are greater than 2 bits
        else if (i == 3 && digit > 0b11)
        {
            // Print an appropiate error message
            printf("Error. Invalid argument\n");
            printf("Argument %d should consist of maximum of 2 bits\n", i);

            // Return 0 to signify that it is not a valid sequence of bits
            return 0;
        }
        // Else if the other controllers are greater than 1 bit
        else if (i != 3 && i != 2 && digit > 0b1)
        {
            // Print an appropiate error message
            printf("Error. Invalid argument\n");
            printf("Argument %d should consist of maximum of 1 bit\n", i);

            // Return 0 to signify that it is not a valid sequence of bits
            return 0;
        }

        // Store the current command line argument digit in the outputArray
        outputArray[i - 1] = digit;
    }

    // Return 0 to signify a valid user input
    return 1;
}
