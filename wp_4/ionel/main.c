// Include section
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LENGTH 10 // Maximum length a string can be to calculate its permutations

// Prototype function declarations

/**
 * Function that returns the factorial of n
 */
int factorial(int n);

/**
 * Helper function that frees the allocated memory
 * used for the array of permutations
 *
 * INPUT:
 *  input: the array of permutations
 *  size: the size of the array of permutations
 *
 * OUTPUT:
 *  None
 */
void freeArray(char **input, int size);

/**
 * Helper function that prints the array of permutations
 *
 * INPUT:
 *  input: the array of permutations
 *  size: the size of the array of permutations
 *  inputString: the original string
 */
void printPermutations(char **input, int size, char *inputString);

/**
 * Helper function to Initialize allocated memory for a string with 0s
 *
 * I'm aware that calloc exists, but to be safe I implemented my own function.
 */
void initializeStringWith0s(char *inputString, int length);

/**
 * Recursive function that calculates all the permutations of a given array
 * and stores them in an output array.
 *
 * INPUT:
 *  inputString: the string to calculate the permutations
 *  removeIndexes: a counter that it's used to keep track of the removed indexes for the permutations
 *  inputStringLength: the length of the original string
 *  currentPermutation: the current permutation that is being calculated
 *  currentPermutationIdx: the index of the current permutation that is being calculated
 *  permutationCounter: the number of current permutations calculated
 *  permutations: an array of strings that stores every permutation
 *
 * OUTPUT:
 *  None but the permutations array now contains all the calculated permutations
 */
void calculatePermutations(char *inputString, int removeIndexes, int inputStringLength, char *currentPermutation, int currentPermutationIdx, int *permutationCounter, char **permutations);

/**
 * This program expects a string of 10 characters or less,
 * and generates all the permutations for that given string.
 *
 * Purpose: Bonus question work package 4
 * DIT633
 *
 * Author: Ionel Pop, 2024
 *
 **/
int main(int argc, char **argv)
{
    // Variable declarations
    char *inputString;        // The string provided by the user
    int n;                    // The length of the input string
    int numberOfPermutations; // The number of possible permutations for a given string
    char **permutations;      // An array of strings that stores all the possible permutations
    char *currentPermutation; // String that will allow the program to keep track of the current permutation
    int permutationCounter;   // Integer to keep track of the number of permutations calculated so far

    // If the number of arguments provided is different than 2
    if (argc != 2)
    {
        // Print an appropiate error message
        printf("Invalid. Incorrect number of arguments\n");
        printf("Please input only 1 argument for the permutation\n");

        // Return 0 and exit the program
        return 0;
    }

    // Assign the second command line argument provided to inputString
    inputString = argv[1];

    // Calculate the length of the input string and assign it to n
    n = strlen(inputString);

    // If the length of the provided string is greater than 10
    if (n > MAX_LENGTH)
    {
        // Print an appropiate error message
        printf("Invalid. String exceeds the maximum number of characters\n");

        // Return 0 and exit the program
        return 0;
    }

    // Calculate the number of possible permutations and assign it to numberOfPermutations
    numberOfPermutations = factorial(n);

    // Memory allocation

    /**
     * Allocate enough memory for all the possible permutations.
     * In this, case we allocate the memory necessary to store n! char*
     */
    permutations = (char **)malloc(numberOfPermutations * sizeof(char *));

    /**
     * Iterate through the permutations array until i is greater or equal than numberOfPermutations.
     * This will allocate memory for each individual string in the permutations array.
     */
    for (int i = 0; i < numberOfPermutations; i++)
    {
        /**
         * Allocate enough memory to store every permutation of size (n + 1).
         */
        permutations[i] = (char *)malloc((n + 1) * sizeof(char));
        // Initialize the string with 0s
        initializeStringWith0s(permutations[i], n);
    }

    // Allocate memory to store the current permutation
    currentPermutation = (char *)malloc((n + 1) * sizeof(char));
    // Initialize the string with 0s
    initializeStringWith0s(currentPermutation, n);

    // Initialize the current permutations calculated to 0
    permutationCounter = 0;

    // Calculate all the possible permutations and store those results in permutations
    calculatePermutations(inputString, 0b0, n, currentPermutation, 0, &permutationCounter, permutations);

    // Print all the permutations
    printPermutations(permutations, numberOfPermutations, inputString);

    // Free the allocated memory for the permutations array
    freeArray(permutations, numberOfPermutations);
    // Free the allocated memory for currentPermutation
    free(currentPermutation);

    // Return 0 and exit the program
    return 0;
}

int factorial(int n)
{
    /**
     * The factorial of n is:
     *  n * (n - 1) * (n - 2) * (n - 3) ... * (1)
     */

    // If n is equal to 1, we return 1 because 1! is 1
    if (n <= 1)
    {
        return 1;
    }

    // Otherwise, we return n * (n-1)!
    return n * factorial(n - 1);
}

void freeArray(char **input, int size)
{
    // Iterate through the array of strings we want to free
    for (int i = 0; i < size; i++)
    {
        // Free each individual string
        free(input[i]);
    }

    // Free the allocated memory for the outer array
    free(input);
}

void printPermutations(char **input, int size, char *inputString)
{
    // Print appropiate message
    printf("All permutations of the string %s are: ", inputString);

    // Iterate through the input array of strings
    for (int i = 0; i < size; i++)
    {
        // Print each individual string
        printf("%s ", input[i]);
    }

    // Print a new line character for formatting
    printf("\n");
}

void initializeStringWith0s(char *inputString, int length)
{
    // Iterate through the string
    for (int i = 0; i < length + 1; i++)
    {
        // Assign a \0 or null terminator to each character
        inputString[i] = '\0';
    }
}

void calculatePermutations(char *inputString, int removeIndexes, int inputStringLength, char *currentPermutation, int currentPermutationIdx, int *permutationCounter, char **permutations)
{
    /**
     * My thought process for this function is explained in a long comment at the end of the file.
     * 
     * Basically, the function works by doing recursive calls of itself and checking if an element is already used in the permutation or not.
     * 
     * So for example, 'abc', would be something like this:
     * 
     * iterate over 'abc'
     * choose 'a' -> currentPermutation = 'a'
     * recursive call to calculatePermutations
     * choose 'a' -> 'a' is already in currentPermutation
     * choose 'b' -> currentPermutation = 'b'
     * recursive call to calculatePermutations
     * choose 'a' -> 'a' is already in currentPermutation
     * choose 'b' -> 'b' is already in currentPermutation
     * choose 'c' -> currentPermutation = 'abc'
     * return to the previous function call
     * return to the previous function call
     * 
     * choose 'b' -> currentPermutation = 'b'
     * recursive call to calculatePermutations
     * choose 'a' -> currentPermutation = 'ba'
     * recursive call to calculatePermutations
     * choose 'a' -> 'a' is already in currentPermutation
     * choose 'b' -> 'b' is already in currentPermutation
     * choose 'c' -> currentPermutation = 'bac'
     * return to the previous function call
     * return to the previous function call
     * 
     * and so on
    */
    /**
     * If the length of the current permutation is equal to the length of the input string
     * 
     * This means that whenever we reach a full permutation, we execute this code block
    */
    if (strlen(currentPermutation) == inputStringLength)
    {
        // Copy the permutation to the permutations array in the appropiate index given by permutationCounter
        strcpy(permutations[*permutationCounter], currentPermutation);
        // Update permutationCounter
        *permutationCounter += 1;

        // Assign a null terminator character at the end of the string just to be sure
        currentPermutation[currentPermutationIdx - 1] = '\0';

        // Return from this function
        return;
    }

    // Iterate through the input string
    for (int i = 0; i < inputStringLength; i++)
    {
        /**
         * I used bitwise operations to keep track of the elements that are already in the permutation.
         * 
         * For example, if the original string is 'abc' and I choose 'a', my only possible choices are
         * b or c for the next elements. Therefore, my binary number removeIndexes will look like this 0b001.
         * Which means that 'a' is already being used.
         * 
         * Whenever we want to check a specific character we can just do removeIndexes >> indexToCheck.
         * In the same scenario, if we want to check if we can use 'a' in our permutation we would just do 0b001 >> 0 = 1.
         * Therefore, we can't use 'a' so we move to the next item.
        */
        //  If the current index is not in the removeIndexes list.
        if (((removeIndexes >> i) & 1) == 0)
        {
            /**
             * Similarly, once we encounter a new element, we need to add it to the list of removeIndexes.
             * 
             * To do this, we just bitshift 1 the necessary number of spaces. For example, in the case of 'a',
             * we do 1 << 0 = 1. Therefore our new list of remove indexes will be:
             * 
             * removeIndexes | 1 -> 0b0000 | 0b0001 = 0b1
             * 
             * Finally, we pass that result to calculate the next permutation
            */

            // bitshift 1 the necessary number of spaces as explained above
            int newPosition = 1 << i;

            // Initialize a new list of remove indexes to be pass to the next recursive function call
            int newRemove = removeIndexes | newPosition;

            // Assign the current character to the current index of the permutation that is being calculated
            currentPermutation[currentPermutationIdx] = inputString[i];

            // Recursive call of the function with the same parameters with the exception of the new updated "list" of removed indexes, and the updated currentPermutationIdx to continue iterating over the string
            calculatePermutations(inputString, newRemove, inputStringLength, currentPermutation, currentPermutationIdx + 1, permutationCounter, permutations);
        }
    }
}

/**
 * My thought process for coming up with this algorithm:
 *
 * Testing for "abc"
 *      size of outputArray = 3! -> 6
 *
 * removeIndexes = [-1, -1, -1] -> This indicates which characters are used in the permutation
 * Iterate through abc
 *  If a character is not in the removeIndexes list:
 *      print(a);
 *    1 calculatePermutations(abc, [0, -1, -1]); // I need to find a way to create this array locally
 *      print(b);
 *    2 calculatePermutations(abc, [-1, 0, -1]);
 *      print(c);
 *    3 calculatePermutations(abc, [-1, -1, 0]);
 *
 * 1:
 *  Iterate through abc -> removeIndexes = [0, -1, -1]
 *      If a character is not in the removeIndexes list:
 *          print(b);
 *        4 calculatePermutations(abc, [0, 0, -1]);
 *          print(c);
 *        5 calculatePermutations(abc, [0, -1, 0]);
 *
 * 4:
 *  Iterate through abc -> removeIndexes = [0, 0, -1]
 *      If a character is not in the removeIndexes list:
 *          print(c);
 *        6 calculatePermutations(abc, [0, 0, 0]);
 * 4:
 *  Iterate through abc -> removeIndexes = [0, -1, 0]
 *      If a character is not in the removeIndexes list:
 *          print(b);
 *        7 calculatePermutations(abc, [0, 0, 0]);
 *
 * Iterate through abc
 * a:
 *  removeIndexes = [-1, -1, -1]
 *  a -> idx 0 -> add 0 to the removeIndexes list
 *  removeIndexes = [0, -1, -1]
 *  print(a)
 *  call calculatePermutations for _bc
 *
 * Iterate through _bc
 *      if a character is not in the removeIndexes -> (b or c):
 */
