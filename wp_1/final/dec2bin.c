// Includes section
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <errno.h>

// 100011100011100011110100100001001000111010110111111011101110010
// 01000111010110111111011101110010
// 5124104901124421490

    int
    main(int argc, char **argv)
{
    unsigned long userInput = atol(argv[1]);
    int bits = 0;
    while (userInput > 0)
    {
        userInput >>= 1;
        bits++;
    }
    printf("Number of bits: %d\n", bits);
    // min size of num
    int numSize = 8;
    int bitSizes[4] = {8, 16, 32, 64};

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
        if (atol(argv[1]) >> i & 1)
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
