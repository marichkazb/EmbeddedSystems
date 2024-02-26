// Include section
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Define section
#define NUM_OF_STRINGS 5 // The maximum number of strings the program should ask the user for and store
#define MAX_LENGTH 300 // The maximum length of any string that can be stored

// Function declarations

/**
 * Removes the shortest string of a given array that contains MAX_LENGTH strings.
 * 
 * INPUT:
 *  inputArray: An array of strings to remove the shortest string from. The array has to have MAX_LENGTH items.
 * 
 * OUTPUT:
 *  A pointer to the new array of strings that contains all the strings in inputArray minus the shortest.
*/
char **removeShortest(char (*inputArray)[MAX_LENGTH]);

/**
 * Helper function to free memory from an array of strings.
 * 
 * INPUT:
 *  inputArray: A pointer to the array of strings that will be freed.
 *  size: The size of inputArray.
 * 
 * OUTPUT:
 *  NONE but the memory allocated for inputArray will be freed.
*/
void freeArrayOfStrings(char** inputArray, int size);

/**
 * Helper function to print an array.
 * 
 * INPUT:
 *  inputArray: The array of strings to be printed.
 *  size: The size of inputArray.
 * 
 * OUTPUT:
 *  NONE but the array will be printed.
*/
void printArray(char** inputArray, int size);

/**
 * This program expects 5 strings to be stored in an array,
 * then shows and removes the shortest string.
 *
 * Purpose: Bonus question work package 6
 * DIT633
 *
 * Author: Ionel Pop, 2024
 *
 **/
// Main program
int main()
{
    char stringsArray[NUM_OF_STRINGS][MAX_LENGTH]; // Store 5 strings that are at most 100 characters long

    // Iterate from 0 to 5 to get the strings from the user input
    for (int i = 0; i < NUM_OF_STRINGS; i++)
    {
        // Prompt the user to input a string
        printf("Please input the string #%d: ", i);

        // Store the input string in stringsArray at the proper index i
        scanf("%s", stringsArray[i]);
    }

    // Remove the shortest string in the array and return a pointer to a new array of  characters
    char **newArray = removeShortest(stringsArray);

    // Print a message to the user
    printf("Array after removal:\n");

    // Print the new array of strings
    printArray(newArray, NUM_OF_STRINGS - 1);

    // Free the allocated memory
    free(newArray);

    // Return 0 and finish the program execution
    return 0;
}

char **removeShortest(char (*inputArray)[MAX_LENGTH])
{
    int shortestIndex = 0; // Index to store the shortest string

    // Iterate through the strings in inputArray
    for (int i = 0; i < NUM_OF_STRINGS; i++)
    {
        // If the current string length is less than the string at shortestIndex
        if (strlen(inputArray[i]) < strlen(inputArray[shortestIndex]))
        {
            // Reassign shortestIndex to the current index
            shortestIndex = i;
        }
    }

    // Print a message to the user showcase the string that was removed
    printf("Shortest string removed: %s\n", inputArray[shortestIndex]);

    // Allocate memory for a new array of strings that contains all the previous strings but the shortest
    char **returnArray = (char **)malloc((NUM_OF_STRINGS - 1) * (sizeof(char *)));
    int newArrayIndex = 0; // "Pointer (not as in c pointer but as in an algorithm pointer)" to keep track of the new array index
    int oldIndex = 0; // Pointer to keep track of the old index of the array

    // Iterate through the new array of strings
    while (newArrayIndex < NUM_OF_STRINGS - 1)
    {
        // If the old index is equal to the shortest index
        if (oldIndex == shortestIndex)
        {
            // We skip this execution of this step since we don't want to add the shortest string to the new array
            oldIndex++;
            // Skip the execution of this loop
            continue;
        }

        // Allocate enough memory to store a string at the specific index
        returnArray[newArrayIndex] = (char *)malloc(MAX_LENGTH * sizeof(char));

        // Copy the current string to the new array
        strcpy(returnArray[newArrayIndex++], inputArray[oldIndex++]);
    }

    // Return the new array
    return returnArray;
}

void freeArrayOfStrings(char** inputArray, int size)
{
    // Iterate through the size of inputArray
    for (int i = 0; i < size; i++)
    {
        // Free the allocated memory for a string
        free(inputArray[i]);
    }

    // Free the allocated memory for the array of strings
    free(inputArray);
}

void printArray(char** inputArray, int size)
{
    // Iterate over the inputArray size
    for (int i = 0; i < size; i++)
    {
        // Print the items in the array
        printf("%s\n", inputArray[i]);
    }
}
