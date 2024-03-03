#include <stdio.h>
#include <stdlib.h>

// Write a C program to input any number from user and check whether nth bit of the given number is set(1) or not(0).
void clearBuffer();

int main(int argc, char *argv[])
{
    int num, bitNum;
    printf("Input number: \n");
    scanf("%d", &num);
    printf("Input nth bit: \n");
    scanf("%d", &bitNum);

    unsigned char selected_bit;
    selected_bit = (num >> bitNum) & 1;
    printf("Bit number %d is set to %d\n", bitNum, selected_bit);

    return 0;
}

void clearBuffer()
{
    int temp;
    while ((temp = getchar()) != '\n' || temp != EOF)
    {
        ;
    }
}