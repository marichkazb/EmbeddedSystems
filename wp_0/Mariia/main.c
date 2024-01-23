// (C)__Your names here, group : 123 __(2022)
// Work package 0
// Exercise 1
// Submission code: XXXXXX (provided by your TA-s)

#include <stdio.h>
#include <string.h>

// To run the program
// gcc main.c -o main
// ./main Tom

// Main function in the program, takes argument count and array or chars as arguments
int main(int argc, char **argv)
{
    char userInput[10];
    if (argc != 2)
    // check if the number of provided arguments is more or less than 2
    //(argv[0] is the name of the program and argv[1] is element provided by user)
    {
        printf("Input -h to get help\n");
        scanf("%s", userInput); // read user input
        if (strcmp("-h", userInput) == 0)
        {
            printf("Provide one name when starting the program\n");
            return 0;
        }
        else
        {
            printf("Symbol is not recognised\n"); // if user typed smth different than "-h"
            return 0;
        }
    }
    if (strcmp(argv[1], "-h") == 0) // If user initially typed "-h" when running the program
    {
        printf("Provide one name when starting the program");
        return 0;
    }
    // Final successful case outputs hello world with the user name
    printf("Hello World! – I’m %s!\n", argv[1]);
    return 0;
}