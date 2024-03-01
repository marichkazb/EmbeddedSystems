#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Write a program to read a string from the console/stdin and count the number of chars, words, and
// lines, and print these quantities.

int main(int argc, char *argv[])
{
    char userString[200] = "abcd new line \n new line \n nwe \n";
    printf("Input a string: \n");
    // fgets(userString, sizeof(userString), stdin);

    int numChars = 0, numWords = 0, numLines = 0;
    int i = 0;
    char *str = userString;
    int isInWord = 0;
    while (i < strlen(userString))
    {
        if (*str == '\n')
        {
            numLines++;
        }
        else if (*str != ' ')
        {
            isInWord = 1;
            numChars++;
        }
        else
        {
            isInWord == 1 && numWords++;
            isInWord = 0;
        }
        str++;
        i++;
    }

    printf("\n*******************\n");
    printf("Number of chars: %d\n", numChars);
    printf("Number of words: %d\n", numWords);
    printf("Number of lines: %d\n", numLines);

    return 0;
}