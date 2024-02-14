// Include section
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// helper function to swap two chars when performing algorithm
void swap(char *a, char *b);
// helper function to get the number of all possible combinations of the given string
int getNumElements(int size);
// helper function to recursively modify the string to get all possible permutations
void strPermutations(char **arr, char *srt, int start, int end, int *j);

const int MAX_NUM = 10; // max number of elements in the array

// main function
int main(int argc, char **argv)
{
    // check for the command line arguments, if they are not provided, print error
    if (argc < 2)
    {
        // print error
        printf("invalid: Please provide parameters\n");
        // terminate the program
        return 0;
    }
    // if too many arguments are provided
    else if (argc > 2)
    {
        // print error
        printf("invalid: Too many arguments\n");
        // terminate the program
        return 0;
    }

    // initialize pointer to the first element of the user string
    char *userString = argv[1];
    // char userString[] = "abc1";            // uncomment for debugging
    // get the number of elements in the user string
    int numOfLetters = strlen(userString); // also equal to rows number

    // in case there are more than 10 letters provided
    if (numOfLetters > MAX_NUM)
    {
        // print error
        printf("invalid: Max number of arguments is 10\n");
        // terminate the program
        return 0;
    }

    // to store permutations it's possible to use 2D array
    // amount of columns is equal to the amount of letters in the string
    int cols = numOfLetters;
    // amount of rows is equal to the amount of max possible combinations of the letters
    int rows = getNumElements(cols); // numOfPermutations

    // allocate memory for pointers to the beginning of every row
    char **permutations = (char **)malloc(rows * sizeof(char *)); // allocate space for rows. permutations if an array of pointers to pointers
    // also allocate memory for all rows in 2D array. Each row length is equal to col + 1 because in the end we need to attach end of line character
    for (int i = 0; i < rows; i++)
    {
        // 1 extra character for end of string character
        permutations[i] = (char *)malloc((cols + 1) * sizeof(char));
    }
    // if error occurred when allocating memory
    if (permutations == NULL)
    {
        // print error
        printf("Error when allocating memory");
        // terminate the program
        return 0;
    }

    // initialize counter of permutations, that is equal to the row number in the matrix
    int j = 0;
    // call the helper function, passing start as 0 and end as last element
    strPermutations(permutations, userString, 0, cols - 1, &j);

    // print user message
    printf("String permutations: \n");
    // print all rows of strings
    for (int i = 0; i < rows; i++)
    {
        // print the permutation row that forms a string
        printf("%s\n", permutations[i]);
    }

    // free allocated memory
    for (int i = 0; i < rows; i++)
    {
        // free every row of the matrix
        free(permutations[i]);
    }
    // finally free the variable
    free(permutations);
    // terminate the program
    return 0;
}

// helper function that recursively finds all string permutations
void strPermutations(char **arr, char *str, int start, int end, int *j)
{
    // base case for terminating the recursion is when start = end
    if (start == end)
    {
        // copy the found string to the row in the matrix pointed by the j
        strcpy(arr[*j], str);
        // increment row
        (*j)++;
        // terminate
        return;
    }
    // loop over the string characters from start to end
    for (int i = start; i <= end; i++)
    {
        // swap two elements, start and i-th element
        swap(&str[start], &str[i]);
        // recursively call the function for the remaining characters
        strPermutations(arr, str, start + 1, end, j);
        // swap the elements back to ensure that new executions will operate on the original string
        swap(&str[start], &str[i]);
    }
}

// helper function to get the combinatorial number of max possible combinations of letters
int getNumElements(int size)
{
    // initialize num as 1
    int num = 1;
    // for abcd: for the first position we have 4 options, for second 3 (since they can't be repeated), for third 2, for fourth 1
    // will result in 4*3*2*1 = 24 combinations
    for (int i = size; i > 1; i--)
    {
        // multiply by the number of options
        num = num * i;
    }
    // return the result
    return num;
}

// helper function to swap two chars in place
// takes pointers to the chars that need to be swapped
void swap(char *a, char *b)
{
    // dereference a and save value of the first char to temp
    char temp = *a;
    // assign value of the second to first
    *a = *b;
    // assign second to temp that is storing the first value
    *b = temp;
}
