// (C) __Mariia Zabolotnya, Joel Cellen, Ionel Pop, group: 8 __ (2024)
// Work package 0
// Exercise 1
// Submission code: XXXXXX (provided by your TA-s)
#include <stdio.h>
#include <string.h>

int printHelp()
{
    printf("Please input \"-h\" to get help\n");
    char userInput[10]; // Change his thing

    scanf("%s", userInput);

    while (strcmp("-h", userInput) != 0)
    {
        printf("Please input \"-h\" to get help\n");
        scanf("%s", userInput);
    }

    printf("To use the program, provide just one name with no spaces as a comand line argument\n");

    printf("Please try again\n");

    char userInput2[10];
    scanf("%s", userInput2);

    if (strcmp("-h", userInput2) == 0)
    {
        printHelp();
    }

    printf("Hello World! - I'm %s!\n", userInput2);
    return 0;
}

void printHelp2()
{
    
}

// Main function in the program, program arguments supported
int main(int argc, char **argv)
{
    if (argc != 2)
    {
        printf("Please input \"-h\" to get help\n");
        char userInput[10]; // Change his thing

        scanf("%s", userInput);

        while (strcmp("-h", userInput) != 0)
        {
            printf("Please input \"-h\" to get help\n");
            scanf("%s", userInput);
        }

        printf("To use the program, provide just one name with no spaces as a comand line argument\n");

        printf("Please try again\n");

        char userInput2[10];
        scanf("%s", userInput2);

        printf("Hello World! - I'm %s!\n", userInput2);
        return 0;
    }
    else if (strcmp(argv[1], "-h") == 0)
    {
        printf("To use the program, provide just one name with no spaces as a comand line argument\n");
        return 0;
    }

    // Print a string to the console
    printf("Hello World! - I'm %s!\n", argv[1]);

    return 0;
}
