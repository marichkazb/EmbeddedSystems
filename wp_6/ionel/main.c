#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NUM_OF_STRINGS 5
#define MAX_LENGTH 300

char **removeShortest(char (*inputArray)[MAX_LENGTH])
{
    int shortestIndex = 0;
    for (int i = 0; i < NUM_OF_STRINGS; i++)
    {
        if (strlen(inputArray[i]) < strlen(inputArray[shortestIndex]))
        {
            shortestIndex = i;
        }
    }

    printf("Shortest string removed: %s\n", inputArray[shortestIndex]);

    char **returnArray = (char **)malloc((NUM_OF_STRINGS - 1) * (sizeof(char *)));
    int newArrayIndex = 0;
    int oldIndex = 0;

    while (newArrayIndex < NUM_OF_STRINGS - 1)
    {
        if (oldIndex == shortestIndex)
        {
            oldIndex++;
            continue;
        }

        returnArray[newArrayIndex] = (char *)malloc(MAX_LENGTH * sizeof(char)); 
        strcpy(returnArray[newArrayIndex++], inputArray[oldIndex++]);
    }

    return returnArray;
}

void freeArrayOfStrings(char** inputArray, int size)
{
    for (int i = 0; i < size; i++)
    {
        free(inputArray[i]);
    }

    free(inputArray);
}

void printArray(char** inputArray, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%s\n", inputArray[i]);
    }
}

int main()
{
    char stringsArray[NUM_OF_STRINGS][MAX_LENGTH]; // Store 5 strings that are at most 100 characters long
    for (int i = 0; i < NUM_OF_STRINGS; i++)
    {
        printf("Please input the string #%d: ", i);
        scanf("%s", stringsArray[i]);
    }

    char **newArray = removeShortest(stringsArray);

    printf("Array after removal:\n");
    printArray(newArray, NUM_OF_STRINGS - 1);

    free(newArray);
    return 0;
}
