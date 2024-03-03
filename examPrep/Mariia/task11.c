#include <stdio.h>
#include <stdlib.h>

// Write a C program to input any number from user and toggle or invert or flip nth bit of the given
// number using bitwise operator

int main(int argc, char *argv[])
{
    int num, bitNum;
    printf("Input number: \n");
    scanf("%d", &num);
    printf("Input nth bit to flip: \n");
    scanf("%d", &bitNum);

    unsigned char mask;
    mask = 1 << bitNum;
    num = num ^ mask;

    printf("After toggling a bit in decimal: %d\n", num);

    return 0;
}