// Includes section
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Declare the function prototype
void scanner();

// Main function declaration
int main(int argc, char **argv)
{
    char userInput[] = "";
    if (argc < 2)
    {
        printf("Please enter the number of characters that the program should shift the sentence by.");
        return 0;
    }
    int encryptNum = atoi(argv[1]);
    int isTerminated = 0;
    while (!isTerminated)
    {
        scanf("%s", userInput);
        isTerminated = userInput[0] == EOF;
        int i = 0;
        while (userInput[i] != '\0')
        {
            int encr = (int)userInput[i] + encryptNum;
            if (encr > 122)
            {
                int temp = encr - 122;
                encr = 96 + temp;
            }
            else if (encr > 90 && encr < 97)
            {
                int temp = encr - 90;
                encr = 64 + temp;
            }
            printf("%c", encr);
            i++;
        }
        printf("\n");
    }

    return 0;
}

//[97-122]
