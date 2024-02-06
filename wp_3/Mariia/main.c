// Include section
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// declare helper function to clear input buffer
void clearBuffer();
// declare helper function for handling matrix input and validating its values
// it returns a pointer to the first element of the array
int *inputMatrix(int num, int numEl);

// Main function declaration
int main(void)
{
    // declare variables to store user input of matrix dimensions and array to store result of sum
    int row, col, sum[16];
    // ask user to input the matrix size
    printf("Input the size ");
    // scan user input to the variables
    scanf("%d %d", &row, &col);
    // validate user input, as the matrix can be 4x4 max
    if (row > 4 || col > 4)
    {
        // in case of incorrect dimensions, print the error
        printf("Error: invalid matrix size. max is 4x4\n");
        // exit the program
        exit(0);
    }
    // clear buffer of the most recent user input
    clearBuffer();

    // calculate the total number of elements that the matrix will have
    int numEl = (row * col);

    // get input of the matrix 1 and assign pointer to the first element
    int *matrix1 = inputMatrix(1, numEl);
    // get input of the matrix 2 and assign pointer to the first element
    int *matrix2 = inputMatrix(2, numEl);

    // sum the values of the matrices
    for (int i = 0; i < numEl; i++)
    {
        // create a temporary value
        int temp;
        // temp is the sum of values of matrices to where the pointer will point after moving i positions from the start of the array
        temp = *(matrix1 + i) + *(matrix2 + i);
        // assign the value of temp to the element of the sum arr to which the pointer will point after moving it by i positions from start
        *(sum + i) = temp;
    }

    // print the message
    printf("The sum is: \n");
    // initialize helper variable
    int j = col;
    // print the array in the form of matrix
    for (int i = 0; i < j; i++)
    {
        // print the element at the i position
        printf("%d ", sum[i]);
        // if we reached the last element in the column, then we will need to start printing from next line
        // ex: arr[2][4]
        // x x x
        // x x x
        if (i == j - 1)
        {
            // if j has not overflown the max number of elements, then increase it by the amount of columns
            // to be able to start the next row of printing matrix
            // otherwise assign it a value of number of all elements to print them till the end
            j < numEl ? j += col : numEl;
            // print new line character
            printf("\n");
        }
    }
    // terminate the program
    return 0;
}

// helper function to get the matrix input and validate it according to the specification
int *inputMatrix(int num, int numEl)
{
    // initialize pointer to an integer and allocate memory for 16 integers following the first one
    // this way we initialize the space for matrix array
    int *matrix = malloc(16 * sizeof(int));
    // print user message
    printf("Input elements of the matrix %d: ", num);
    // declare helper variable for user input
    int input;
    // declare variable for i outside the for loop to be able to validate the number of iterations == the number of given elements
    int i;
    // declare variable to store character for end of line validation
    char c;
    // loop until i = 16, so that max number of the elements in the matrix is 16, since max matrix is 4x4
    for (i = 0; i <= 16; i++)
    {
        // scan integer and validate it
        if (scanf("%d", &input) != 1)
        {
            // print error message
            printf("invalid character\n");
            // terminate the program
            exit(0);
        }
        // scan next character and check if it is the end of input
        if (((c = getchar()) == '\n') || c == EOF)
        {
            // add input to the matrix
            matrix[i] = input;
            // exit the loop since we encountered the end of input
            break;
        }
        // in case the character wasn't the end character, we put it back not to loose data
        else
        {
            // put back the character to correctly scan the next integer
            // if it's not done, then the array will miss some items
            ungetc(c, stdin);
        }
        // add input to the matrix
        matrix[i] = input;
    }
    // if the amount of elements we scanned is different from expected, then print error
    if (i != numEl - 1)
    {
        // print the error message
        printf("invalid number of arguments\n");
        // terminate the program
        exit(0);
    }
    // return pointer to the first element of the matrix
    return matrix;
}

// helper function for clearing buffer
void clearBuffer()
{
    // declare userInput helper variable
    int userInput;
    // clear input buffer iteratively
    while ((userInput = getchar()) != '\n' && (userInput != EOF))
        ; // do nothing, since we just want to reach the end of input
}
