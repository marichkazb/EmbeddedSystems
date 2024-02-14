// Include section
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void generator(char **permutations, char *str, int start, int end, int *j);
void swap(char *a, char *b);

int main(void)
{
    // if (argc < 2)
    // {
    //     printf("invalid: Please provide parameters\n");
    //     return 0;
    // }
    // else if (argc > 2)
    // {
    //     printf("invalid: Too many arguments\n");
    //     return 0;
    // }
    // else if (sizeof(argv) > sizeof(char) * 10) // calculate number of characters in the input based on the sizes
    // {
    //     printf("invalid: Max number of arguments is 10\n");
    //     return 0;
    // }
    char initialStr[] = "abcd";

    int numElements = strlen(initialStr);
    int numPermutations = 1;

    for (int i = numElements; i > 1; i--)
    {
        numPermutations = numPermutations * i; // max number of permutations that will be in the array of chars
    }
    int j = 0;
    // char permutations[numElements][numPermutations]; // store as a two-dimensional array
    char **permutations = (char **)malloc(numPermutations * sizeof(char *));
    for (int i = 0; i < numPermutations; i++)
    {
        permutations[i] = (char *)malloc((numElements + 1) * sizeof(char)); // +1 for null terminator
    }
    generator(permutations, initialStr, 0, numElements - 1, &j);
    for (int i = 0; i < numPermutations; i++)
    {
        printf("%s\n", permutations[i]);
    }
}

void generator(char **permutations, char *str, int start, int end, int *j)
{
    if (start == end)
    {
        strcpy(permutations[*j], str);
        (*j)++;
        return;
    }
    for (int i = start; i <= end; i++)
    {
        swap(&str[start], &str[i]);
        generator(permutations, str, start + 1, end, j);
        swap(&str[start], &str[i]);
    }
}

void swap(char *a, char *b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}
