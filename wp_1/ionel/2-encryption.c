#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LENGTH 100

int isCharUppercase(char c);

int main(int argc, char** argv)
{
    char* userInput = malloc(MAX_STR_LENGTH);

    if (argc < 2)
    {
        printf("Error! No encryption shift was provided\n");
        return 1;
    }
    else if (argc > 2)
    {
        printf("Error! Too many arguments\n");
        return 1;
    }

    int encryptionShift = atoi(argv[1]) % 26;

    while (1)
    {
        char c;
        int counter = 0;
        while ((c = getchar()) != '\n')
        {
            if (c == EOF)
            {
                printf("EOF Detected. Exiting the program\n");
                return 0;
            }
            // Else if, check if alpha and not a space
            else if (isCharUppercase(c) == -1 && c != ' ')
            {
                printf("Error. Non alpha character nor space entered\n");
                return 0;
            }
            userInput[counter] = c;
            counter++;
        }
        userInput[counter] = '\0';

        for (int i = 0; i < strlen(userInput); i++)
        {
            int encrypted = 0;
            if (isCharUppercase(userInput[i]) == 1)
            {
                // Z + 13 -> 90 + 13 = 103 -> should not be g, it should be 65 + 13 - 1 -> 77 -> M
                encrypted = ((int)userInput[i] + encryptionShift);

                encrypted = encrypted <= 90 ? encrypted : 65 + (((int)userInput[i] + encryptionShift) % 90) - 1;
            }
            // Input is lowercase
            else if (isCharUppercase(userInput[i]) == 0)
            {
                // z + 13 -> 122 + 13 = 135 -> it should be 109 -> 135 -> M
                encrypted = ((int)userInput[i] + encryptionShift);

                encrypted = encrypted <= 122 ? encrypted : 97 + (((int)userInput[i] + encryptionShift) % 122) - 1;
            }
            else if (userInput[i] == ' ')
            {
                encrypted = 32;
            }

            if (encrypted == 0)
            {
                printf("Oops. Something went wrong :(\n");
                return 0;
            }

            printf("%c", encrypted);
        }

        printf("\n");
    }
    return 0;
}

int isCharUppercase(char c)
{
    if (c <= 'Z' && c >= 'A')
    {
        return 1;
    }
    else if (c <= 'z' && c >= 'a')
    {
        return 0;
    }
    else
    {
        return -1;
    }
}

/*
If it's lower case -> ASCII -> [97, 122]

To get the conversion, it's just the current ascii + conversion

For example: 120 + 10 = 130
But because 130 is greater than 122, we do
130%122 = 8 -> 96 + 8 = 104
*/