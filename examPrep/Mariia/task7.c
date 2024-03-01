#include <stdlib.h>
#include <stdio.h>
#include <string.h>
// Write a program in C to print all permutations of a given string using pointers.
void getPermutations(char *string, char **arr, int start, int end, int *j);
int getFactorial(int num);
void swap(char *a, char *b);

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("invalid amount of arguments, try again\n");
        return 0;
    }
    // char *string = strdup("abcd"); // for debugging
    char *string = argv[1];
    int col = strlen(string);
    int row = getFactorial(col);
    char **permutations = (char **)malloc(row * sizeof(char *));
    for (int i = 0; i < row; i++)
    {
        // 1 extra character for end of string character
        permutations[i] = (char *)malloc((col + 1) * sizeof(char));
    } // keep track of rows
    int j = 0;
    getPermutations(string, permutations, 0, col - 1, &j);
    printf("String permutations: \n");
    for (int i = 0; i < row; i++)
    {
        printf("%s\n", permutations[i]);
    }
    for (int i = 0; i < row; i++)
    {
        free(permutations[i]);
    }
    free(permutations);
    return 0;
}

void getPermutations(char *string, char **arr, int start, int end, int *j)
{
    if (start == end)
    {
        strcpy(arr[*j], string);
        (*j)++;
        return;
    }
    for (int i = start; i <= end; i++)
    {
        swap(&string[start], &string[i]);
        getPermutations(string, arr, start + 1, end, j);
        swap(&string[start], &string[i]);
    }
}

void swap(char *a, char *b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}
int getFactorial(int num)
{
    int factorial = 1;
    for (int i = num; i > 1; i--)
    {
        factorial = factorial * i;
    }
    return factorial;
}
