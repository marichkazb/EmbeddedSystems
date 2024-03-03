#include <stdio.h>
#include <stdlib.h>

// Write a C program to input a number from user and count total number of ones (1s) and zeros (0s) in the given number using bitwise operator.

int main(int argc, char *argv[])
{
    int num, bit = 0, zeros, ones;
    printf("Input number: \n");
    scanf("%d", &num);

    // num = 12;

    int counter = 0;
    while (counter < 32)
    {
        (num & 1) == 0 ? zeros++ : ones++; // check less significant bit
        num = num >> 1;
        counter++;
    }

    printf("Number of ones: %d\n", ones);
    printf("Number of zeros: %d\n", zeros);

    return 0;
}
