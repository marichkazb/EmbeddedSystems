// Includes section
#include <stdio.h>
#include <stdlib.h>

// try casting ?
int main(int argc, char **argv)
{
    int userInput = atoi(argv[1]);
    int bits = 0;
    while (userInput > 0)
    {
        userInput >>= 1;
        bits++;
    }
    // min size of num
    int numSize = 8;
    int bitSizes[4] = {8, 16, 32, 64};

    // cast int, short, double, long

    for (int i = 0; i < sizeof(bitSizes); i++)
    {
        if (bitSizes[i] >= bits)
        {
            numSize = bitSizes[i];
            break;
        }
    }
    for (int i = numSize - 1; i >= 0; i--)
    {
        if (atoi(argv[1]) >> i & 1)
        {
            printf("1");
        }
        else
        {
            printf("0");
        }
    }
    printf("\n");
    return 0;
}
