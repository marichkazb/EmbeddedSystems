#include <stdio.h>
#include <stdlib.h>

// Write a C program to input any number and check whether the given number is even or odd using bitwise operator.

int main(int argc, char *argv[])
{
    int num, lastBit;
    printf("Input number: \n");
    scanf("%d", &num);

    // num = 12;

    lastBit = num & 1;
    if (lastBit == 0)
    {
        printf("Number %d is even\n", num);
    }
    else
    {
        printf("Number %d is odd\n", num);
    }
    return 0;
}
