#include <stdio.h>
#include <stdlib.h>

#define MAX 21

int findNewLine(char *input)
{
    while (*input != '\0')
    {
        if (*input == '\n')
        {
            return 1;
        }
        input++;
    }
    return 0;
}

void cleanBuffer()
{
    char c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

void copyString(char* source, char* dest)
{
    // int counter = 0;
    while (*source != '\0')
    {
        *dest = *source;
        source++;
        dest++;
    }
    *dest = '\0';
}

void removeNewLine(char* input)
{
    while (*input != '\0')
    {
        if (*input == '\n')
        {
            *input = '\0';
            return;
        }
        input++;
    }
}

int stringLength(char* input)
{
    int length = 0;
    while (*input != '\0')
    {
        length++;
        input++;
    }

    return length;    
}

int main()
{
    char userInput[MAX];
    printf("Please input a string: ");
    fgets(userInput, MAX, stdin);
    if (findNewLine(userInput) == 0)
    {
        cleanBuffer();
    }
    else
    {
        removeNewLine(userInput);
    }

    int length = stringLength(userInput);

    char* copy = (char*)malloc((length + 1) * sizeof(char));

    copyString(userInput, copy);

    printf("The copied string is: %s\n", copy);

    return 0;
}