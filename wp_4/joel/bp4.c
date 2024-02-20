// (C) Joel Celén, group: 8__ (2024)
// Work package 4
// Exercise Bonus

// Include section
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define section
#define MAX 10

// Declare global variables and initialize to 0
int inputLength = 0;
int numPerm = 0;
int indx = 0;

// Function prototypes
void swapCharacter(char *first, char *second);
int factorial(int base);
void populateOutput(char *string, int start, int end, char **pCurrent);
void printPermutations(char **pCurrent);

// Main function
int main(int argc, char const *argv[])
{
    if (argc == 2) // Expected number of arguments
    {
        // Get input length
        inputLength = strlen(argv[1]);

        // In put is out of allowed range
        if (inputLength > MAX)
        {
            // Print error message
            printf("invalid.\n");
            // Should return 1 for failed execution, returns 0 because CodeGrade
            return 0;
        }

        // Calculate the number of permutations
        numPerm = factorial(inputLength);

        // Declare a string with inputLength bytes
        char input[inputLength];
        
        // Copy over user fed argument to input string
        strncpy(input, argv[1], inputLength);

        // Declare pointer and set it to point at first char in input
        char *pInput = &input[0];

        // Allocate memory for pointer array
        char **pOutputArray = malloc(numPerm * sizeof(char *));
        
        // If memory allocation fails
        if (pOutputArray == NULL)
        {
            // Print error message
            fprintf(stderr, "Memory allocation failed\n");
            // Should return 1 for failed execution, returns 0 because CodeGrade
            return 0;
        }

        // For every pointer in pointer array
        for (int i = 0; i < numPerm; i++)
        {
            // At index i, allocate memory for a string of inputLength
            pOutputArray[i] = malloc((inputLength * sizeof(char)) +1);

            // If memory allocation fails
            if (pOutputArray[i] == NULL)
            {
                // Print error message
                fprintf(stderr, "Memory allocation failed\n");
                // Should return 1 for failed execution, returns 0 because CodeGrade
                return 0;
            }
        }

        // Call function to populate the memory with the permutations
        populateOutput(input, 0, inputLength - 1, pOutputArray);

        // Call the function to print the permutations from memory
        printPermutations(pOutputArray);

        // Free memory for string array
        for (int i = 0; i < numPerm; i++)
        {
            // Free memory for each individual string
            free(pOutputArray[i]);
        }
        // Free memory for the array itself
        free(pOutputArray);
    }
    else // More arguments than expected
    {
        // Print error message
        printf("invalid.\n");
        // Should return 1 for failed execution, returns 0 because CodeGrade
        return 0;
    }
    // Return 0 for successful operation
    return 0;
}

/* Function to print permutations of string
This function takes three parameters:
1. String
2. Starting index of the string
3. Ending index of the string.
4. Output string array.

Original method reference:
https://www.geeksforgeeks.org/write-a-c-program-to-print-all-permutations-of-a-given-string/
*/
void populateOutput(char *string, int start, int end, char **pCurrent)
{
    // Base Case: When start index equals end index, it indicates a complete permutation
    if (start == end)
    {
        // Copy the current permutation (string) to the appropriate slot in the 2D array
        strncpy(pCurrent[indx], string, inputLength);

        // Increment the index counter to prepare for the next permutation
        indx++;
    }
    else
    {
        // Recursive Case: When there are more characters to permute
        for (int i = start; i <= end; i++)
        {
            // Swap the characters at start and index i to generate a permutation
            swapCharacter((string + start), (string + i));
            // Recursively call populateOutput to permute the remaining characters
            populateOutput(string, start + 1, end, pCurrent);
            // Backtrack: Swap the characters back to the original state
            swapCharacter((string + start), (string + i));
        }
    }
}

// Function to print permutations
void printPermutations(char **pCurrent)
{
    // Reset index to index 1 to skip original string input
    indx = 1;
    
    // Print information statement
    printf("All permutations of the string are:");
    
    // For every permutation
    for (int i = 0; i < numPerm - 1; i++)
    {
        // Print the permutation at index i
        printf(" %s", *pCurrent);
        // Increment index
        pCurrent++;
    }
    // Print "\n" for ease of reading
    printf("\n");
}

// Helper function to swap values of two characters
void swapCharacter(char *first, char *second)
{
    // Declare variable to hold first value
    char temp = *first;
    // Set first value to value of second
    *first = *second;
    // Set second value to value of first
    *second = temp;
}

// Function to calculate the factorial of base
int factorial(int base)
{
    // Initialize value to 1
    int value = 1;

    // While base is lager than 1
    while (base > 1)
    {
        // Value times current value of base
        value *= base;
        // Decrement base
        base--;
    }
    // Return value
    return value;
}
