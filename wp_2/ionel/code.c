#include <stdio.h>

int mapShiftspaces(int input)
{
    switch (input)
    {
    case 0:
        return 7;
        break;
    case 1:
        return 4;
        break;
    case 2:
        return 2;
        break;
    case 3:
        return 1;
        break;
    case 4:
        return 0;
        break;
    default:
        break;
    }
}

int main(int argc, char **argv)
{
    // if (argc < 6)
    // {
    //     printf("Error. You must input 5 arguments\n");
    //     return 0;
    // }

    // TODO: perform validation of the input

    int arguments[] = {1, 2, 2, 1, 1};

    /**
     *                                     current ^ bit
     *                                       ---------
     * 1 = 0000 0001 -> << 7 -> 1000 0000 -> 1 000 00 0 0
     * 2 = 0000 0010 -> << 4 -> 0010 0000 -> 1 010 00 0 0
     * 2 = 0000 0010 -> << 2 -> 0000 1000 -> 1 010 10 0 0
     * 1 = 0000 0001 -> << 1 -> 0000 0010 -> 1 010 10 1 0
     * 1 = 0000 0001 -> << 0 -> 0000 0001 -> 1 010 10 1 0
     */
    int bit = 0b00000000;

    for (int i = 0; i < 5; i++)
    {
        int shiftSpaces = mapShiftspaces(i);
        int current = arguments[i] << shiftSpaces;
        bit ^= current;
    }

    printf("%X\n", bit);

    return 0;
}