#include <stdio.h>
#include <stdlib.h>

// Write a C program to input any number from user and count number of trailing zeros
// in the given number using bitwise operator.

int main(int argc, char *argv[])
{
    int num;
    printf("Input number: \n");
    scanf("%d", &num);

    // num = 12;

    int counter = 0;
    int zeros = 0;
    int hasTrailingZeros = 1;
    while (hasTrailingZeros == 1 && counter < 32)
    {
        if ((num & 1) == 0)
        {
            zeros++;
            counter++;
            num = num >> 1;
        }
        else
            hasTrailingZeros = 0;
    }

    printf("Number of trailing zeros: %d\n", zeros);

    return 0;
}
