#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <number>\n", argv[0]);
        return 1;
    }

    int decimal = atoi(argv[1]);
    int loopCount;

    if (decimal <= 255)
    {
        loopCount = 8;
    }
    else if (decimal > 255 && decimal <= 65535)
    {
        loopCount = 16;
    }
    else if (decimal > 65535 && decimal <= 16777215)
    {
        loopCount = 24;
    }
    else
    {
        loopCount = 32;
    }

    
    for (int i = loopCount -1; i >= 0; i--)
    {
        int binary = (decimal >> i) & 1;
        printf("%d", binary);
    }

    printf("\n");

    return 0;
}