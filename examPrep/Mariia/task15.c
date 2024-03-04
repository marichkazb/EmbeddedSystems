#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Write a C program to concatenate two strings in single string.
// You cannot use the built-in function here. You should use dynamic memory allocation at the heap.

#define MAX 200

int main(void)
{
    char *str1 = (char *)malloc(MAX * sizeof(char));
    char *str2 = (char *)malloc(MAX * sizeof(char));
    // strcpy(str1, "hello\n");
    // strcpy(str2, "world\n");
    printf("Input first string: \n");
    fgets(str1, MAX, stdin);
    printf("Input second string: \n");
    fgets(str2, MAX, stdin);

    int len1 = 0, len2 = 0;

    char *temp = str1;
    while (*temp != '\n')
    {
        len1++;
        temp++;
    }
    *(temp + len1) = '\0';

    temp = str2;
    while (*temp != '\n')
    {
        len2++;
        temp++;
    }
    *(temp + len2) = '\0';

    int len = len1 + len2;

    char *ptr = (char *)malloc((len + 1) * sizeof(char));

    for (int i = 0; i <= len1; i++)
    {
        *(ptr + i) = *(str1 + i);
    }

    for (int j = len1; j < len; j++)
    {
        int reverse = j - len1;
        *(ptr + j) = *(str2 + reverse);
    }
    *(ptr + len) = '\0';

    printf("Concatented string is %s\n", ptr);
    free(ptr);
    return 0;
}
