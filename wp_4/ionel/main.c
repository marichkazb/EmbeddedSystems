#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * Testing for "abc"
 *      size of outputArray = 3! -> 6
 *
 * removeIndexes = [-1, -1, -1]
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
 *
 *
 *
 */

#define MAX_LENGTH 10

int factorial(int n)
{
    if (n <= 1)
    {
        return 1;
    }

    return n * factorial(n - 1);
}

void freeArray(char **input, int size)
{
    for (int i = 0; i < size; i++)
    {
        free(input[i]);
    }

    free(input);
}

void printPermutations(char **input, int size, char *inputString)
{
    printf("All permutations of the string %s are: ", inputString);
    for (int i = 0; i < size; i++)
    {
        printf("%s ", input[i]);
    }
    printf("\n");
}

// inputString = "abc" removeIndexes = [-1, -1, -1]
// Maybe I can pass an int, and just use bitShifting
// removeIndexes is a binaryNumber, where I just keep track of the indexes
// For example 0b100 means that index 2 is in the remove list
void calculatePermutations2(char *inputString, int removeIndexes, int inputStringLength, char *currentPermutation, int currentPermutationIdx, int *permutationCounter, char **permutations)
{
    if (strlen(currentPermutation) == inputStringLength)
    {
        strcpy(permutations[*permutationCounter], currentPermutation);
        *permutationCounter += 1;

        // printf("\tCurrent permutation: %s | %d\n", currentPermutation, *permutationCounter);
        currentPermutation[currentPermutationIdx - 1] = '\0';
        return;
    }
    // 0 -> 0b0
    for (int i = 0; i < inputStringLength; i++)
    {
        // 0 >> i -> 0b0
        int binaryTest = removeIndexes >> i;
        // If the current index is not in the removeIndexes list
        if (((removeIndexes >> i) & 1) == 0)
        {
            int newPosition = 1 << i;
            int newRemove = removeIndexes | newPosition;
            // printf("%c\n", inputString[i]);
            currentPermutation[currentPermutationIdx] = inputString[i];
            calculatePermutations2(inputString, newRemove, inputStringLength, currentPermutation, currentPermutationIdx + 1, permutationCounter, permutations);
        }
    }
}

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        printf("Invalid. Incorrect number of arguments\n");
        printf("Please input only 1 argument for the permutation\n");

        return 0;
    }

    // char *inputString = "abcde";
    char *inputString = argv[1];

    int n = strlen(inputString);

    if (n > 10)
    {
        printf("Invalid. String exceeds the maximum number of characters\n");
        return 0;
    }

    int numberOfPermutations = factorial(n);

    char **permutations = (char **)malloc(numberOfPermutations * sizeof(char *));

    for (int i = 0; i < numberOfPermutations; i++)
    {
        permutations[i] = (char *)calloc((n + 1), sizeof(char));
    }

    char *currentPermutation = (char *)calloc((n + 1), sizeof(char));
    // calculatePermutations(inputString, permutations, 0);
    int permutationCounter = 0;
    calculatePermutations2(inputString, 0b0, n, currentPermutation, 0, &permutationCounter, permutations);

    printPermutations(permutations, numberOfPermutations, inputString);

    freeArray(permutations, numberOfPermutations);
    free(currentPermutation);

    return 0;
}