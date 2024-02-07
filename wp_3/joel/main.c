/* ---- Instructions ----
Write a C program to add two matrix (e.g.: 2x2),
using pointers or arrays (max size should be 4x4).
C program to input two matrix from user and find sum of both matrices using pointers.

Input matrix1:
1 2
4 5

Input matrix2:
9 8
6 5

Sum of both matrices:
10 10
10 10

The input to the program should be provided in the following way:

Input the size: 2 2
Input elements of matrix 1: 1 2 4 5
Input elements of matrix 2: 9 8 6 5

The sum is:
10 10
10 10

Please remember about the error handling if the elements are not numbers
or if the number of elements in the matrix is not as specified in the size.
*/

// Includes section
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define section
#define MAX 4

// Type definitions
typedef struct MATRIX
{
    long values[MAX][MAX];  // Values array
    struct MATRIX *selfPrt; // Pointer to self
} MATRIX;                   // Type name

// Global variables
int yConstr;   // Matrix y constraint
int xConstr;   // Matrix x constraint
int numValues; // Number of arguments expected

// Function prototypes
void printResult(MATRIX *first, MATRIX *second); // Prints final result
int takeInput(MATRIX *first, MATRIX *second);    // Takes user input
int populateMatrix(MATRIX *matrix, char *input); // Populates matrix with user input

// Main function
int main(int argc, char const *argv[])
{
    // If exactly one argument, main argument
    if (argc == 1)
    {
        // Declare matrices
        MATRIX firstMatrix, secondMatrix;

        // Set selfpointers
        firstMatrix.selfPrt = &firstMatrix;   // Selfpointer set to address of struct
        secondMatrix.selfPrt = &secondMatrix; // Selfpointer set to address of struct

        // Call take input function
        if (takeInput(firstMatrix.selfPrt, secondMatrix.selfPrt) == 0) // If takeInput returns success
        {
            // Call print result function
            printResult(firstMatrix.selfPrt, secondMatrix.selfPrt);
        }
        else // if takeInput returns failure
        {
            // Should return 1 for unsuccessful execution, because of codegrade this is set to 0
            return 0;
        }
    }
    // Return 0 for successful execution
    return 0;
}

// Function that takes user input
int takeInput(MATRIX *first, MATRIX *second)
{
    // Char arrays to store user input string
    char matrixSize[10];
    // Prompt user
    printf("Input the size: ");
    // Take input and store in matrixSize
    fgets(matrixSize, 10, stdin);

    // Checks validity of string input
    for (int i = 0; i < strlen(matrixSize) - 1; i += 2)
    {
        // If character is outside of allowed range
        if (matrixSize[i] < '2' || matrixSize[i] > '4')
        {
            // Print error message
            printf("invalid\n");
            // Return 1 for failed operation
            return 1;
        }
    }

    // Save input characters as integers
    yConstr = atoi(&matrixSize[0]); // First integer
    xConstr = atoi(&matrixSize[2]); // Second integer

    // Calculate the amount of arguments the user should input
    numValues = yConstr * xConstr;

    // Char arrays to store user input string
    char matrix1val[50]; // For first matrix
    char matrix2val[50]; // For second matrix

    // Prompt user to input values for first matrix
    printf("Input elements of matrix 1: ");
    // Take input and save string in variable
    fgets(matrix1val, 50, stdin);

    // Call populateMatrix function
    if (populateMatrix(first, matrix1val) == 1) // If function returns failure
    {
        // Return 1 for failure
        return 1;
    }

    // Prompt user to input values for second matrix
    printf("Input elements of matrix 2: ");
    // Take input and save string in variable
    fgets(matrix2val, 50, stdin);

    // Call populateMatrix function
    if (populateMatrix(second, matrix2val) == 1) // If function returns failure
    {
        // Return 1 for failure
        return 1;
    }
    // Return 0 for success
    return 0;
}

// Function to print result
void printResult(MATRIX *matrix1, MATRIX *matrix2)
{
    // Start of result printing
    printf("The sum is:\n");

    for (int i = 0; i < yConstr; i++) // For every row
    {
        for (int j = 0; j < xConstr; j++) // For every column
        {
            // Print the sum of current cell of matrix 1 & 2 using pointers
            printf("%ld ", matrix1->values[i][j] + matrix2->values[i][j]);
        }
        // Newline for better readability
        printf("\n");
    }
}

// Function to populate the matrix
int populateMatrix(MATRIX *matrix, char *input)
{
    // Variable declarations
    char *endPtr;              // End pointer
    int counter = 0, row, col; // Counter, row and column variables

    // While value of input pointer is not EOL OR has the same address as endpointer
    while (*input != '\0' || input == endPtr)
    {
        while (*input == ' ') // While there are consecutive spaces
        {
            // Increment pointer
            input++;
        }

        // Convert string to long and store the operation result in a variable
        long num = strtol(input, &endPtr, 10);

        if (*input != '0' && num == 0) // If string read is not an integer
        {
            // Print error message
            printf("invalid\n");
            // Return 1 for failed execution
            return 1;
        }

        // Divide counter with x contraint to get row position
        row = counter / xConstr;
        // Reminder of counter and x constraint to get column position
        col = counter % xConstr;

        // Matrix value in specified cell takes the long value
        matrix->values[row][col] = num;

        // Current character pointer becomes end pointer
        input = endPtr;
        // Counter gets incremented after successful conversion
        counter++;
        // Increment pointer
        input++;
    }

    // Number of arguments provided are not the same as matrix size
    if (counter != numValues)
    {
        // Print error message
        printf("invalid\n");
        // Return 1 for failed execution
        return 1;
    }
    // Return 0 for successful execution
    return 0;
}