// Include section
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define section
#define MAX_STR_LENGTH 100      // Define maximum length of the string to be encrypted
#define NUMBER_OF_LETTERS 26    // Define the number of possible letters to be encrypted (In this case, the standard english alphabet)

/**
 * Helper function that checks if a character is UPPERCASE or lowercase
 *
 * Returns 1 if c is uppercase, 0 if c is lowercase, -1 if c is a non letter character
 */
int isCharUppercase(char c);

// Main program section

/**
 * This program encrypts a message by shifting the
 * ASCII values of the characters
 *
 * Purpose: Practice ASCII manipulation
 * DIT633
 *
 * Author: Ionel Pop, Joel Celen, Mariia Zabolotnia, 2024
 *
 **/
int main(int argc, char **argv)
{
    // Variable declaration

    // Declare a character array and allocate enough memory to store the user input
    char *userInput = (char *)malloc((MAX_STR_LENGTH + 1) * sizeof(char));

    // Check if the correct number of command line arguments was provided
    if (argc < 2)
    {
        // Print error and return 1
        printf("Error! No encryption shift was provided\n");
        return 1;
    }
    // Else if more than 2 arguments were provided
    else if (argc > 2)
    {
        // Print error and return 1
        printf("Error! Too many arguments\n");
        return 1;
    }

    /**
     * Get the encryption shift from the command line arguments.
     * Use %26 because there are 26 letters.
     *
     * For example, if we get 30, encryptionShift will be 4
     *
     */
    int encryptionShift = atoi(argv[1]) % NUMBER_OF_LETTERS; // Declare encryption shift

    // "Infinite loop"
    while (1)
    {
        char c;          // Declare a char c, to store current characters input by the user
        int counter = 0; // Declare an int counter, to store the length of the string input by the user

        // While the current character is different than `newline('\n')`
        while ((c = getchar()) != '\n')
        {
            // If the current character is equal to EOF
            if (c == EOF)
            {
                // Return 0 and print corresponding message and exit the program
                printf("EOF Detected. Exiting the program\n");
                return 0;
            }
            // Else if character is not a letter nor a space
            else if (isCharUppercase(c) == -1 && c != ' ')
            {
                // Return 0 and print corresponding message and exit the program
                printf("Error. Non alpha character nor space entered\n");
                return 0;
            }

            /**
             * Append the current char to the userInput string
             * Also, update the counter to keep track of the length
             */
            userInput[counter++] = c;
        }

        // When the user input has been processed, append the string terminator character at the end
        userInput[counter] = '\0';

        // Iterate through the string that store the user input
        for (int i = 0; i < strlen(userInput); i++)
        {
            int encrypted = 0; // Variable to keep track of the resulting encrypted character

            // If the character is uppercase
            if (isCharUppercase(userInput[i]) == 1)
            {
                /**
                 * In this case, we don't want our encryption to go into the lowercase letters.
                 *
                 * For example, if we are encrypting Z and encryptionShift is 13:
                 *      'Z' + 13 -> 90 + 13 = 103 -> But 103 is 'g'
                 *      In contrast, the result should be
                 *      65 + (103 % 90) - 1  = 77 -> Which is 'M', the proper result
                 *
                 * We also don't want our encryption to go bellow bounds when having negative shifts.
                 *
                 * For example, if we are encrypting B and encryptionShift is -3:
                 *      'B' - 3 -> 66 - 3 = 63 -> Which is bellow 'A' (65)
                 *      Therefore, we calculate the correct char as it follows:
                 *      encrypted = 90 ('Z') - (65 ('A') - encrypted) + 1;
                 *      Which will give us 98 -> 'Y'
                 */

                // Add the ASCII value of the current character in the user input + the encryption shift
                encrypted = ((int)userInput[i] + encryptionShift);

                // If the encrypted char goes above bounds
                if (encrypted > 'Z')
                {
                    // Do what it is explained above.
                    encrypted = 'A' + (((int)userInput[i] + encryptionShift) % 'Z') - 1;
                }
                // Else if the encrypted char goes bellow bounds
                else if (encrypted < 'A')
                {
                    // Do what it is explained above
                    encrypted = 'Z' - ('A' - encrypted) + 1;
                }
            }
            // Else if the character is lowercase
            else if (isCharUppercase(userInput[i]) == 0)
            {
                /**
                 * Similarly to the previous case, we don't want our encryption to go above bounds.
                 *
                 * For example, if we are encrypting z and encryptionShift is 13:
                 *      'Z' + 13 -> 122 + 13 = 135 -> But it should be 109 which is 'm'
                 *      97 + (135 % 122) - 1  = 109 -> Which is 'm', the proper result
                 */

                // Add the ASCII value of the current character in the user input + the encryption shift
                encrypted = ((int)userInput[i] + encryptionShift);

                // If the encrypted char goes above bounds
                if (encrypted > 'z')
                {
                    // Do what it is explained above.
                    encrypted = 'a' + (((int)userInput[i] + encryptionShift) % 'z') - 1;
                }
                // Else if the encrypted char goes bellow bounds
                else if (encrypted < 'a')
                {
                    // Do what it is explained above
                    encrypted = 'z' - ('a' - encrypted) + 1;
                }
            }

            /**
             * Else if the current character in the input is a space.
             * 
             * This allows us to encrypt sentences instead of only words
             */
            else if (userInput[i] == ' ')
            {
                // We assign the encrypted character to a space
                encrypted = 32;
            }

            // If the character could not be encrypted
            if (encrypted == 0)
            {
                // Print an error message and finish the program
                printf("Oops. Something went wrong :(\n");
                return 0;
            }

            // If everything worked properly, print the encrypted character (or a space)
            printf("%c", encrypted);
        }

        // Print the end of line for the encrypted string
        printf("\n");
    }
    return 0;
}

int isCharUppercase(char c) // Helper function defined in the beginning
{
    // If the character is between 'A' and 'Z' (65 and 90)
    if (c <= 'Z' && c >= 'A')
    {
        // Return 1: It is UPPERCASE
        return 1;
    }
    // Else if the character is between 'a' and 'z' (97 and 122)
    else if (c <= 'z' && c >= 'a')
    {
        // Return 0: It is lowercase
        return 0;
    }
    // Otherwise, if the character is not a letter
    else
    {
        // Return -1
        return -1;
    }
}

/*
Initial idea:

If it's lower case -> ASCII -> [97, 122]

To get the conversion, it's just the current ascii + conversion

For example: 120 + 10 = 130
But because 130 is greater than 122, we do
130%122 = 8 -> 96 + 8 = 104
*/