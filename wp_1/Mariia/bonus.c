#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    char *userInput = argv[1];
    // handling errors
    if (argc < 2)
    {
        printf("No command line argument provided, please provide a number.\n");
        return 0;
    }

    int i = 0;
    while (userInput[i] != '\0')
    {
        if (!isdigit(userInput[i]))
        {
            printf("Provided argument is of incorrect type, please provide a decimal number.\n");
            return 0;
        }
        i++;
    }
    printf("Number: %s\n", userInput);

    int numb = atoi(userInput);

    int numOfZeros = 0;
    int numOfOnes = 0;

    int numSize = sizeof(numb) * 8;
    int firstOneFound = 0;

    printf("Binary: 0b");

    for (int i = numSize - 1; i >= 0; i--)
    {
        if (numb >> i & 1)
        {
            firstOneFound = 1;
            printf("1");
            numOfOnes++;
        }
        else if (firstOneFound)
        {
            printf("0");
            numOfZeros++;
        }
    }
    printf("\n");
    printf("Number of 0s: %i\nNumber of 1s: %i\n", numOfZeros, numOfOnes);
    return 0;
}