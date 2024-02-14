// Include section
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void swap(char *a, char *b);
int getNumElements(int size);
void strPermutations(char **arr, char *srt, int start, int end, int *j);

const int MAX_NUM = 10; // max number of elements in the array

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        printf("invalid: Please provide parameters\n");
        return 0;
    }
    else if (argc > 2)
    {
        printf("invalid: Too many arguments\n");
        return 0;
    }

    char *userString = argv[1];
    // char userString[] = "abc1";            // for testing
    int numOfLetters = strlen(userString); // numOfLetters row

    if (numOfLetters > MAX_NUM) // calculate number of characters in the input based on the sizes
    {
        printf("invalid: Max number of arguments is 10\n");
        return 0;
    }
    // validate all members of array are characters
    // char *ptr = userString;
    // while (*ptr)
    // {
    //     if (!isalpha(*ptr))
    //     {
    //         printf("invalid: %s contains not only characters\n", userString);
    //         return 0;
    //     }
    //     ptr++;
    // }

    int cols = numOfLetters;
    int rows = getNumElements(cols); // numOfPermutations

    // allocate memory for pointers to the beginning of every row
    char **permutations = (char **)malloc(rows * sizeof(char *)); // allocate space for rows. permutations if an array of pointers to pointers
    for (int i = 0; i < rows; i++)
    {
        permutations[i] = (char *)malloc((cols + 1) * sizeof(char)); // 1 extra character for end of string character
    }
    if (permutations == NULL)
    { // if error occurred when allocating memory
        printf("Error when allocating memory");
        return 0;
    }

    int j = 0; // counter of permutations
    strPermutations(permutations, userString, 0, cols - 1, &j);

    printf("String permutations: \n");
    for (int i = 0; i < rows; i++)
    {
        printf("%s\n", permutations[i]);
    }
    for (int i = 0; i < rows; i++)
    {
        free(permutations[i]);
    }
    free(permutations);
    return 0;
}

void strPermutations(char **arr, char *str, int start, int end, int *j)
{
    // base case
    if (start == end)
    {
        strcpy(arr[*j], str);
        (*j)++;
        return;
    }
    for (int i = start; i <= end; i++)
    {
        swap(&str[start], &str[i]);
        strPermutations(arr, str, start + 1, end, j);
        swap(&str[start], &str[i]); // back swap
    }
}

int getNumElements(int size)
{
    int num = 1;
    for (int i = size; i > 1; i--)
    {
        num = num * i;
    }
    return num;
}

void swap(char *a, char *b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}
