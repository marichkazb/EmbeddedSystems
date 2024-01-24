#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char **argv)
{
    // handling errors
    if (argc < 2)
    {
        printf("No command line argument provided, please provide a number.\n");
        return 0;
    }
    int i = 0;
    while (argv[1][i] != '\0')
    {
        if (!isdigit(argv[1][i]))
        {
            printf("Provided argument is of incorrect type, please provide a decimal number.\n");
            return 0;
        }
        i++;
    }
    int binary = 0;
    int numOfZeros = 0;
    int numOfOnes = 0;
    // output
    printf("Number: %s\nBinary: %i\nNumber of 0s: %i\nNumber of 1s: %i\n", argv[1], binary, numOfZeros, numOfOnes);
    return 0;
}