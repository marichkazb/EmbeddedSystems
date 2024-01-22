#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char **argv)
{
    char buffer[100];
    scanf("%s", buffer);

    // printf("This is the output from the previous program %s\n", buffer);

    int len = strlen(buffer);
    // printf("The length of the output is %d\n", len);

    int sum = 0;

    // 1010
    int counter = 0;
    char hexNumber[64][3];
    int hexCounter = 0;

    for (int i = len - 1; i >= 0; i--)
    {
        if (counter == 4)
        {
            counter = 0;

            // Just sum to get the ASCII
            // printf("\t sum: %d\n", sum);
            // printf("\nNew batch\n");

            if (sum > 9)
            {
                sum -= 10;
                int test = 65 + sum;
                // printf("This should be: %c\n", test);
                sprintf(hexNumber[hexCounter], "%c", test);
            }
            else
            {
                sprintf(hexNumber[hexCounter], "%d", sum);
            }

            // hexNumber[hexCounter] = str;
            hexCounter++;
            sum = 0;
        }

        // printf("%c", buffer[i]);
        int current = buffer[i] - '0';
        int powerOf2 = pow(2, counter);
        sum += current * powerOf2;
        counter++;
    }

    // Leftover sum
    // printf("\t sum: %d\n", sum);
    // hexNumber[hexCounter] = sum;

    if (sum > 9)
    {
        sum -= 10;
        int test = 65 + sum;
        // printf("This should be: %c\n", test);
        sprintf(hexNumber[hexCounter], "%c", test);
    }
    else
    {
        sprintf(hexNumber[hexCounter], "%d", sum);
    }
    // sprintf(hexNumber[hexCounter], "%d", sum);

    // printf("\n");
    // for (int i = 0; i < 4; i++)
    // {
    //     int current = buffer[i] - '0';
    //     int powerOf2 = pow(2, 3 - i);
    //     sum += current * powerOf2;
    // }

    // Print the hex number
    // printf("In hex: ");
    for (int i = hexCounter; i >= 0; i--)
    {
        printf("%s", hexNumber[i]);
    }

    printf("\n");

    // printf("The sum is: %d\n", sum);

    return 0;
}

// gcc bin2hex.c -o bin2hex.out -lm