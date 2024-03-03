#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Write a C program to input any number from user and find highest order set bit of given number using bitwise operator

int main(void)
{
    int num, lastBit, bit;
    printf("Input number: \n");
    scanf("%d", &num);
    int temp = num;

    for (int i = 0; i < 32; i++)
    {
        bit = temp & 1;
        if (bit == 1)
        {
            lastBit = i;
        }
        temp = temp >> 1;
    }

    printf("Highest order set bit in %d is: %d\n", num, lastBit);

    return 0;
}