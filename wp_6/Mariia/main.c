// Include section
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// define variable to store max number of elements in the array
int MAX = 5;
// define MAX_LENGTH of the string that user can input to the program
#define MAX_LENGTH 200

// declare a function that finds and removes the shortest string in arr[MAX]
// it returns pointer to the removed string
char *find_remove_str(char *arr[MAX]);
// function that prints the content of array
void printArray(char *arr[MAX]);

// main function declaration
int main(int argc, char *argv[])
{
    // initialize pointer to the array that will store user input strings
    char *arr[MAX];
    // in a loop read user input, allocate memory and save it to the array
    for (int i = 0; i < MAX; i++)
    {
        // declare a buffer of max number of characters, include some extra for the new line
        char buffer[MAX_LENGTH + 5];
        // print user message
        printf("String %d: ", i + 1);
        // scan user input from the terminal
        fgets(buffer, sizeof(buffer), stdin);
        // allocate memory in the array for a new string
        arr[i] = malloc(strlen(buffer) + 1);
        // copy user input from buffer to the array
        strcpy(arr[i], buffer);

        // Remove the trailing newline character
        size_t len = strlen(arr[i]);
        // if the last character was new line
        if (len > 0 && arr[i][len - 1] == '\n')
        {
            // then replace it with the end of line character
            arr[i][len - 1] = '\0';
        }
    }

    // print user message
    printf("\nArray before removal:\n");
    // use helper function to print array
    printArray(arr);

    // create a pointer element and execute find and remove string functionality.
    // It will return a pointer to removed string
    char *element = find_remove_str(arr);
    // print the shortest string that was removed
    printf("\nShortest string removed: %s\n", element);

    // print user message
    printf("\nArray after removal:\n");
    // use helper function to print array
    printArray(arr);

    // free allocated memory, starting from 0 to MAX in array
    for (int i = 0; i < MAX; i++)
    {
        // free the memory of every cell that was allocated for array
        free(arr[i]);
    }
    // terminate the program
    return 0;
}

// helper function to find and remove shortest string, it takes a pointer to the first element of array of chars
char *find_remove_str(char *arr[MAX])
{
    // initialize variable to store min length
    int min_len = 0;
    // find index of the shortest string
    for (int i = 0; i < MAX; i++)
    {
        // if the length of string at position i is less than at position min_len
        if ((strlen(*(arr + i))) < (strlen(*(arr + min_len))))
        {
            // reassign min_len to i
            min_len = i;
        }
    }

    // declare a pointer for the shortest string and allocate memory for it
    char *shortestString = malloc(MAX_LENGTH);
    // copy the value cell where pointer min_len points starting from the beginning of array to shortest string
    strcpy(shortestString, *(arr + min_len));

    // remove this string and reduce array length
    if (min_len != MAX - 1)
    {
        // iteratively go through the elements starting at position of min_len
        // and remember that new length is MAX - 1 now
        for (int i = min_len; i < MAX - 1; i++)
        {
            // and copy the value of the string 1 cell backward
            strcpy((*(arr + i)), (*(arr + i + 1)));
        }
    }
    // decrease the MAX amount of elements in the array since the string was removed
    MAX--;
    // return pointer to the string that was removed
    return shortestString;
}

// helper function to print array, receives a pointer to the first element of array of chars
void printArray(char *arr[MAX])
{
    // in a loop where i < MAX
    for (int i = 0; i < MAX; i++)
    {
        // print the element of the array at position i
        printf("%s\n", *(arr + i));
    }
}
