#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LENGTH 100

int main(int argc, char** argv)
{
    char userInput[MAX_STR_LENGTH] = "";

    if (argc < 2)
    {
        printf("Error! No encription shift was provided\n");
        return 1;
    }
    else if (argc > 2)
    {
        printf("Error! Too many arguments\n");
        return 1;
    }

    int encriptionShift = atoi(argv[1]);

    while (1)
    {
        // printf("Enter a phrase: \n");
        scanf("%s", userInput);

        // printf("Your phrase is: %s\n", userInput);

        for (int i = 0; i < strlen(userInput); i++)
        {
            int encripted = (int)userInput[i] + encriptionShift;
            if (encripted > 122)
            {
                encripted = encripted%122 + 96;
            }
            else if (encripted > 90 && encripted < 97)
            {
                encripted = encripted%90 + 64;
            }

            printf("%c", encripted);

            // printf("\tOriginal: %c | %d ", userInput[i], userInput[i]);
            // printf("\tEncripted: %c | %d\n", encripted, encripted);
        }

        printf("\n");

    }

    return 0;
}

/*
If it's lower case -> ASCII -> [97, 122]

To get the conversion, it's just the current ascii + conversion

For example: 120 + 10 = 130
But because 130 is greater than 122, we do
130%122 = 8 -> 96 + 8 = 104
*/