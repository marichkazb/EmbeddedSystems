#include <stdio.h>
#include <stdlib.h>

// Write a program in C to count the number of vowels and consonants in a string using a pointer.

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Incorrect amount of arguments\n");
        return 0;
    }
    char *str = argv[1];
    int vowels = 0, consonants = 0;
    while (*str != '\0')
    {
        if (*str == 'A' || *str == 'a' || *str == 'E' || *str == 'e' || *str == 'I' || *str == 'i' || *str == 'O' || *str == 'o' || *str == 'U' || *str == 'u')
        {
            vowels++;
        }
        else
        {
            consonants++;
        }
        str++;
    }
    printf("\n*******************\n");
    printf("Number of vowels: %d\n", vowels);
    printf("Number of consonants: %d\n", consonants);
    return 0;
}