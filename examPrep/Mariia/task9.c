#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX 20
// Write a program in C to check whether two given strings are an anagram. You must use pointers in
// this task.int main(int argc, char *argv[])
void clearBuffer();

int main(int argc, char *argv[])
{
    char str1[MAX], str2[MAX];
    printf("Input first string: \n");
    scanf("%s", str1);
    // fgets(str1, sizeof(str1), stdin);
    printf("Input second string: \n");
    scanf("%s", str2);
    // fgets(str2, sizeof(str2), stdin);

    // for debugging
    // strcpy(str1, "pears");
    // strcpy(str2, "spare");

    if (strlen(str1) != strlen(str2))
    {
        printf("Strings are not anagrams\n");
        return 0;
    }

    char *ptr1 = str1;
    char *ptr2 = str2;

    int len = strlen(str1);
    int match = 0;
    for (int i = 0; i < len; i++)
    {
        for (int k = 0; k < len; k++)
        {
            if (*(ptr1 + i) == *(ptr2 + k))
            {
                match++;
                break;
            }
        }
    }

    printf("%s and %s are ", str1, str2);
    if (match == len)
    {
        printf("anagrams\n");
    }
    else
    {
        printf("NOT anagrams\n");
    }

    return 0;
}

void clearBuffer()
{
    char temp;
    while ((temp = getchar()) != '\n' || temp != EOF)
    {
        ;
    }
}