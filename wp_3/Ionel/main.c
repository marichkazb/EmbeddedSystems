// Includes section
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Prototype function declarations

/**
 * Prompts the user to input the size of the matrix, and
 * checks if it's within the valid range (2x2 to 4x4)
 * 
 * Input:
 *  matrixDimension: an array to store the dimensions of the matrix
 * 
 * Output:
 *  If the input is valid, returns the number of elements in the matrix (multiplication of the dimension)
 *  If the input is invalid, returns -1
 *  It also modifies the matrixDimension array according to the input dimensions
*/
int getSize(int *matrixDimension);

/**
 * Prompts the user to input the elements in the corresponding matrix.
 * It also checks if the user input is valid or not. (There should only be numbers)
 * 
 * Input:
 *  matrix: The empty matrix to store the input
 *  numberOfElements: The number of elements in the matrix (Multiplication of the dimension)
 * 
 * Output:
 *  If the input is valid, returns 1, otherwise, returns -1.
 *  It also modifies the values inside matrix to store the user input.
*/
int getMatrix(int *matrix, int numberOfElements);

/**
 * Sum 2 matrices A, and B, and stores the sum in Sum
 * 
 * Input:
 *  A, B: Matrices to sum.
 *  numberOfElements: Number of elements in either matrix (They have to have the same number of elements).
 *  Sum: Placeholder matrix to store the result
 * 
 * Output:
 *  Nothing but it stores the sum in Sum.
*/
void sumMatrices(int *A, int *B, int numberOfElements, int *Sum);

/**
 * Formats and prints a 1D array in the form of a matrix according to the specified dimensions
 * 
 * Input:
 *  M: The matrix to print
 *  size: The dimensions of the matrix
 * 
 * Ouput:
 *  Nothing
*/
void printMatrix(int *M, int *size);

/**
 * Helper functions that check if a given string contains only integers (positives or negatives)
 * 
 * Input:
 *  string: the string to check.
 * 
 * Output:
 *  returns 1 if it has only integers, -1 otherwise.
*/
int isInteger(char *string);

/**
 * Helper function to clean the buffer
*/
void cleanBuffer();

/**
 * This program expects the size of a matrix with minimum
 * dimensions of 2x2 and maximum of 4x4.
 * Then asks the user to input the values for 2 matrices,
 * and displays the result of the sum of them.
 * 
 * The program stores the matrices in 1D arrays for simplicity.
 * 
 * Purpose: Bonus question work package 3
 * DIT633
 * 
 * Author: Ionel Pop, 2024
 * 
**/
int main()
{
    int *A; // The first matrix
    int *B; // The second matrix
    int *Sum; // The matrix that will store the sum of A and B

    int matrixDimension[2]; // Array to store the dimensions of the matrices

    // Get the dimension of the matrix by asking the user to input it
    // Returns the number of elements in each matrix
    int numberOfElements = getSize(matrixDimension); // The number of elements in each matrix

    // If the numberOfElements is -1, it means that there was an error with the user input
    if (numberOfElements == -1)
    {
        // Print error message
        printf("invalid\n");
        // Return 0 to finish the execution
        return 0;
    }

    // Allocate memory in A to store numberOfElements integers
    A = (int *)malloc(numberOfElements * sizeof(int));

    // Allocate memory in B to store numberOfElements integers
    B = (int *)malloc(numberOfElements * sizeof(int));

    // printf("Input elements of matrix 1: ");
    /**
     * Ask the user to input the elements of matrix A.
     * 
     * If there was an error, -1 is returned
    */
    if (getMatrix(A, numberOfElements) == -1)
    {
        // If getMatrix() returned -1, there was an error with the input
        // Print error message
        printf("invalid\n");
        // Return 0 to finish the execution
        return 0;
    }

    // printf("Input elements of matrix 2: ");
    /**
     * Ask the user to input the elements of matrix A.
     * 
     * If there was an error, -1 is returned
    */
    if (getMatrix(B, numberOfElements) == -1)
    {
        // If getMatrix() returned -1, there was an error with the input
        // Print error message
        printf("invalid\n");
        // Return 0 to finish the execution
        return 0;
    }

    // Print the sum of the matrices
    printf("The sum is:\n");

    // Allocate enough memory in Sum to store numberOfElements integers
    Sum = (int *)malloc(numberOfElements * sizeof(int));

    // Sum matrices A, and B, and store the result in Sum
    sumMatrices(A, B, numberOfElements, Sum);

    // Format and print the result (Sum)
    printMatrix(Sum, matrixDimension);


    // Free the allocated memory
    free(A);
    free(B);
    free(Sum);

    // Return 0 and finish the execution of the program
    return 0;
}

int getSize(int *matrixDimension)
{
    // Buffer to store the user input
    char userInput[20];

    // printf("Input the size: ");
    // Get the user input and store it in userInput
    fgets(userInput, sizeof(userInput), stdin);
    // cleanBuffer();

    int counter = 0; // Counter to keep track of the number of elements in userInput

    /**
     * Split userInput into spaces and assign the pointer
     * currentDimension to the first section
    */
    char *currentDimension = strtok(userInput, " ");

    /**
     * Loop until is no longer possible to split userInput into spaces
     * 
     * For example: "2 3" -> "2" -> "3" -> NULL
    */
    while (currentDimension != NULL)
    {
        // If we encounter an end of line
        if (*currentDimension == '\n')
        {
            // Break the loop
            break;
        }
        
        // Cast the current string to integer to get the first dimension
        int dimension = atoi(currentDimension);

        // If the dimension is less than 2 or bigger than 4
        if (dimension < 2 || dimension > 4)
        {
            // The dimension is invalid and we return -1
            return -1;
        }

        // If we have processed less than 2 arguments
        if (counter < 2)
        {
            // Assign the current dimension to the corresponding index of the array matrixDimension
            matrixDimension[counter++] = dimension;
        }

        // Continue splitting the userInput into spaces to keep iterating over it
        currentDimension = strtok(NULL, " ");
    }

    // If there were not exactly 2 elements in the userInput. For example "2" or "2 3 3"instead of "2 3"
    if (counter != 2)
    {
        // Print an error message
        printf("Error. Wrong arguments\n");

        // Return -1 to signify invalid input
        return -1;
    }

    // Return the number of elements in the matrix
    return (matrixDimension[0] * matrixDimension[1]);
}

int getMatrix(int *matrix, int numberOfElements)
{
    // Buffer to store the user input
    char userInput[256];

    // Get the user input
    fgets(userInput, sizeof(userInput), stdin);

    /**
     * When using fgets, the new line character '\n' also becomes part of the input.
     * To get rid of that, I found this really quick solution in StackOverflow.
     * 
     * https://stackoverflow.com/questions/2693776/removing-trailing-newline-character-from-fgets-input
    */
    userInput[strcspn(userInput, "\n")] = 0;

    // Split userInput into spaces and assign elements to the first of these splits
    char *elements = strtok(userInput, " ");

    int i = 0; // Counter to keep track of the corresponding index

    // Iterate until we can not longer split the userInput into spaces
    while (elements != NULL)
    {
        // If we have space in the array
        if (i < numberOfElements)
        {
            // Check if the current element is an integer
            if (isInteger(elements) == -1)
            {
                // If it's not an integer, return -1
                return -1;
            }
            // Cast the element to integer and assign it to the matrix in the corresponding index
            matrix[i] = atoi(elements);
        }
        // Continue splitting userInput into spaces to keep iterating over it
        elements = strtok(NULL, " ");
        // Update index
        i++;
    }

    // If not exactly numberOfElements elements were added
    if (i != numberOfElements)
    {
        // Return -1 to represent an error
        return -1;
    }
    else
    {
        // Else if exactly numberOfELements were assigned 
        // Return 1 to represent a proper execution
        return 1;
    }
}

void sumMatrices(int *A, int *B, int numberOfElements, int *Sum)
{
    int counter = 0; // Counter to keep track of the number of elements

    // Loop over A, B, and S, as long as counter is less than numberOfElements
    // Note: All three of the matrices, A, B, and Sum have the same number of elements
    while (counter < numberOfElements)
    {
        // Assign the sum of the corresponding elements of A and B to Sum
        *Sum = *A + *B;
        // Move the Sum pointer to the next element
        Sum++;
        // Move the A pointer to the next element
        A++;
        // Move the B pointer to the next element
        B++;
        // Update counter
        counter++;
    }
}

void printMatrix(int *M, int *size)
{
    int rowCounter = 1; // Counter to keep track of the current row
    int colCounter = 1; // Counter to keep track of the current column

    int index = 0; // Counter to keep track of the current index

    // Iterate until we go over the number of rows
    while (rowCounter <= size[0])
    {
        // If the current column is not the last column
        if (colCounter < size[1])
        {
            // We print the element normally
            printf("%d ", M[index]);
        }
        // Otherwise, if the current column is the last column
        else
        {
            // Print the current element with a new line to account for the formatting
            printf("%d\n", M[index]);
            // Reset the currentColumn to 0
            colCounter = 0;
            // Update the currentRow
            rowCounter++;
        }

        // Update the index
        index++;
        // Update the current column
        colCounter++;
    }
}

int isInteger(char *string)
{
    // Iterate over string until we encounter the null terminator
    while (*string != '\0')
    {
        // If the character is not a digit, nor a '-'
        if ((*string < '0' || *string > '9') && *string != '-')
        {
            // Return -1 to represent that string is not an integer
            return -1;
        }
        // Move the pointer to the next element
        string++;
    }

    // Return 1 to represent that string is an integer
    return 1;
}

void cleanBuffer()
{
    char c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}
