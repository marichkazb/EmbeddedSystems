#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int mapShiftspacesMask(int input)
{
    switch (input)
    {
    case 0:
        return 1;
        break;
    case 1:
        return 3;
        break;
    case 2:
        return 2;
        break;
    case 3:
        return 1;
        break;
    case 4:
        return 1;
        break;
    default:
        break;
    }
}

int hexToDec(char* hex)
{
    int result = 0;
    int powerOf16 = 1;
    for (int i = strlen(hex) - 1; i >= 0; i--)
    {
        int number = hex[i];

        if (hex[i] == 'A')
        {
            number = 10;
        }
        else if (hex[i] == 'B')
        {
            number = 11;
        }
        else if (hex[i] == 'C')
        {
            number = 12;
        }
        else if (hex[i] == 'D')
        {
            number = 13;
        }
        else if (hex[i] == 'E')
        {
            number = 14;
        }
        else if (hex[i] == 'F')
        {
            number = 15;
        }

        int expMultiply = 1;
        for (int exp = 1; exp < powerOf16; exp++)
        {
            expMultiply = expMultiply * 16;
        }

        powerOf16++;

        result = result + (number * expMultiply);
    }

    return result;
}

char * formatPart(int i)
{
    switch (i)
    {
    case 0:
        return "engine_on";
    case 1:
        return "gear_pos";
    case 2:
        return "key_pos";
    case 3:
        return "brake1";
    case 4:
        return "brake2";
    default:
        break;
    }
}

int main(int argc, char **argv)
{
    // TODO: perform validation of the input

    char* argument = "AB";

    int hexValueInDecimal = hexToDec(argument);
    int mask = 0b11111111;

    for (int i = 0; i < 5; i++)
    {
        int shiftSpaces = mapShiftspaces(i);
        int current = hexValueInDecimal >> shiftSpaces;
        printf("%s | %d\n", formatPart(i), current);

        // 10101011
        // 00001111
        mask = mask >> mapShiftspacesMask(i);
        hexValueInDecimal &= mask;
    }
}