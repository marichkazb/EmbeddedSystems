// Include section
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void printBinary(int num);

int main(int argc, char *argv[])
{
    if (argc > 2) // since we have 8 bits, than the hex num can have max 2 characters
    {
        printf("invalid: can't have more than 1 element\n");
        return 0;
    }

    char *userInput = argv[1];

    char *endptr;                                           // To capture the end of the conversion
    int decimalValue = (int)strtol(userInput, &endptr, 16); // convert hex to decimal
    printf("Decimal value: %d\n", decimalValue);
    // decimal to bin

    // int decimalValue = 171;
    int bin = 0;
    int position = 1;

    while (decimalValue > 0)
    {
        int remainder = decimalValue % 2;
        bin = bin | (remainder << (position - 1));
        decimalValue = decimalValue / 2;
        position = position + 1;
    }

    unsigned char binNum = (unsigned char)(bin & 0xFF); // cut 8 rightmost bits
    unsigned char engine_on = (binNum >> 7) & 1;
    unsigned char gear_pos = (binNum >> 4) & 7;
    unsigned char key_pos = (binNum >> 2) & 3;
    unsigned char brake1 = (binNum >> 1) & 1;
    unsigned char brake2 = binNum & 1;

    printf("Name              Value\n"
           "-----------------------------\n"
           "engine_on         %d\n"
           "gear_pos          %d\n"
           "key_pos           %d\n"
           "brake1            %d\n"
           "brake2            %d\n",
           engine_on, gear_pos, key_pos, brake1, brake2);
    return 0;
}
