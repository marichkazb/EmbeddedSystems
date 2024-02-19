// Include section
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 21 // 20 char + end character

void copyString(char *str, char *userStr);

int main(int argc, char *argv[])
{
    char userString[MAX];
    printf("Input a string: \n");
    fgets(userString, sizeof(userString), stdin);

    char *newString = (char *)malloc(MAX * sizeof(char));

    copyString(newString, userString);
    printf("New string is: %s\n", newString);

    // for using library function
    // char newString[20];
    // strcpy(newString, userString);
    // printf("New string is: %s\n", newString);
}

void copyString(char *str, char *userStr)
{
    while (*userStr != '\0')
    {
        *str = *userStr;
        str++;
        userStr++;
    }
}