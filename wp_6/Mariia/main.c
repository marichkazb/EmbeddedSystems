// Include section
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int MAX = 5;
#define MAX_LENGTH 200

char *find_remove_str(char *arr[MAX]);
void printArray(char *arr[MAX]);

// main function declaration
int main(int argc, char *argv[])
{
    char *arr[MAX];
    char buffer[MAX_LENGTH];
    for (int i = 0; i < MAX; i++)
    {
        printf("String %d: ", i + 1);
        fgets(buffer, MAX_LENGTH, stdin);
        arr[i] = malloc(strlen(buffer) + 1);
        strcpy(arr[i], buffer);

        // Remove the trailing newline character
        size_t len = strlen(arr[i]);
        if (len > 0 && arr[i][len - 1] == '\n')
        {
            arr[i][len - 1] = '\0';
        }
    }

    printf("\nArray before removal:\n");
    printArray(arr);

    char *element = find_remove_str(arr);
    printf("\Shortest string removed: %s\n", element);

    printf("\nArray after removal:\n");
    printArray(arr);

    // free allocated memory
    for (int i = 0; i < MAX; i++)
    {
        free(arr[i]);
    }
    return 0;
}

char *find_remove_str(char *arr[MAX])
{
    int min_len = 0;
    // find index of the shortest string
    for (int i = 0; i < MAX; i++)
    {
        if ((strlen(*(arr + i))) < (strlen(*(arr + min_len))))
        {
            min_len = i;
        }
    }

    printf("min len, %d\n", min_len);

    char *shortestString = malloc(MAX_LENGTH);
    strcpy(shortestString, *(arr + min_len));

    // remove this string and reduce array length
    if (min_len != MAX - 1)
    {
        for (int i = min_len; i < MAX - 1; i++)
        {
            strcpy((*(arr + i)), (*(arr + i + 1)));
        }
    }
    MAX--;
    return shortestString;
}

void printArray(char *arr[MAX])
{
    for (int i = 0; i < MAX; i++)
    {
        printf("%s\n", *(arr + i));
    }
}
