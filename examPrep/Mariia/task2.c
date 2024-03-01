#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

void print_bin(int num);
// void print_bin2(int num); // alternative solution ??
uint16_t make_16bit(uint8_t least_significant, uint8_t most_significant);
void clearBuffer();

int main(int argc, char *argv[])
{
    int num = 0;

    // first task

    // while (1)
    // {
    //     printf("Input the number to convert: \n");
    //     scanf("%d", &num);
    //     if (num == -1)
    //     {
    //         break;
    //     }
    //     print_bin(num);
    //     clearBuffer();
    // }

    int num1, num2;
    while (1)
    {
        printf("\n****************************\n");
        printf("Input the number to convert: \n");
        scanf("%d", &num1);

        printf("Input the number to convert: \n");
        scanf("%d", &num2);

        print_bin(num1);
        print_bin(num2);
        uint16_t result = make_16bit(num1, num2);
        clearBuffer();
    }

    return 0;
}

void print_bin(int num)
{
    printf("Bin representation of num %i is: \n", num);
    for (int i = 31; i >= 0; i--)
    {
        int binNum = num >> i & 1;
        printf("%d", binNum);
        if (i != 0 && i % 8 == 0)
        {
            printf(".");
        }
    }
    printf("\n");
}

uint16_t make_16bit(uint8_t num1, uint8_t num2) // least, most
{
    uint16_t bin = 0;
    // Alternative 1
    bin |= (num2 << 0); // bin = bin | (num2 << 0)
    bin |= (num1 << 8); // bin = bin | (num1 << 8)
    print_bin(bin);
    return bin;
}

void clearBuffer()
{
    int temp;
    while ((temp = getchar()) != '\n' && temp != EOF)
    {
        ;
    }
}