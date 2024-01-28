// Includes section
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

void bin2hex();

int main(int argc, char **argv)
{
    if (argc < 2)
    { // if two programs are run in a pipeline
        char binary[64];
        if (scanf("%s", binary) != 1)
        {
            printf("Error reading binary input\n");
            return 0;
        }
        else
        {
            bin2hex(atoi(binary));
        }
    }
    else
    {
        bin2hex((atoi(argv[1])));
    }
    return 0;
}

void bin2hex(long binaryNum)
{
    long hexVal = 0;
    int i = 1;
    long remainder;
    while (binaryNum != 0)
    {
        remainder = binaryNum % 10;
        hexVal = hexVal + remainder * i;
        i = i * 2;
        binaryNum = binaryNum / 10;
    }
    printf("%lX\n", hexVal);
}
