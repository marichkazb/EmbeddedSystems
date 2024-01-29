#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv)
{
    int numberOfBits = 0;
    char* test = argv[1];
    // char* test = "12";
    if ((int)atoi(test) < 256)
    {
        // printf("This should be a byte\n");
        numberOfBits = 8;
    }
    else if ((int)atoi(test) < 65536)
    {
        // printf("This should be a short\n");
        numberOfBits = 16;
    }
    else if ((int)atoi(test) < 4294967296)
    {
        // printf("This should be an int\n");
        numberOfBits = 32;
    }
    else
    {
        // printf("This should be a long\n");
        numberOfBits = 64;
    }

    for (int i = numberOfBits - 1; i >= 0; i--)
    {
        int k = atoi(test) >> i;
        if (k & 1)
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

    /*
    For example
    4 -> 100 in binary
    4 >> 4 -> shift 4 spaces to the right 000[0100] -> 0
    4 >> 3 -> shift 3 spaces to the right 000[100]  -> 0
    4 >> 2 -> shift 2 spaces to the right 001[00]   -> 1
    4 >> 1 -> shift 1 spaces to the right 010[0]    -> 2
    4 >> 0 -> shift 0 spaces to the right 100       -> 4i
    */

   /*
   11111111 -> in dec -> 255
   byte -> 8 bits -> [0, 255]
   int -> 4 bytes -> 32 bits -> [0, 4294967296]
   long -> 8 bytes -> 64 bits -> [0, 1.8446744e+19 - 1]

   */
}