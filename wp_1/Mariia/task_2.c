// Includes section
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// declare a variable that will hold the value of user input
char userInput[] = "";
// function prototype
void encrypt();
// Main function declaration
int main(int argc, char **argv)
{
    // in case there are no command line arguments
    if (argc < 2) // argv[0] is the name of the program and argv[1] is the command line argument. hence, if first element is missing, then the length < 2
    {
        // print user prompt to inform of the error that happened
        printf("Please enter the number of characters that the program should shift the sentence by.");
        // terminate the program
        return 0;
    }
    // convert provided command line argument to int and assign it to a variable
    int encryptNum = atoi(argv[1]);
    // declare int variable to act as a boolean to indicate if EOF character was inputted
    int isTerminated = 0;
    // iteratively execute the program until encountered EOF symbol
    while (!isTerminated)
    {
        // scan user input to be encrypted
        scanf("%s", userInput);
        // update the value of isTerminated depending if EOF was given
        isTerminated = userInput[0] == EOF;
        // call helper function
        encrypt(encryptNum);
    }
    // terminate the program
    return 0;
}

// define helper function encrypt. takes num of elements to shift by as a parameter
void encrypt(int encryptNum)
{
    // declare a counter variable
    int i = 0;
    // iterate on the input array until encounter the end of string character
    while (userInput[i] != '\0')
    {
        // cast every char to ASCII value, so it becomes int and add the encryptNum provided by user
        int encr = (int)userInput[i] + encryptNum;
        // in ASCII uppercase letters A-Z are at positions 65-90 and lowercase a-z have a range of 97-122
        // we need to handle edge cases when the result of shifting the number is not in this range
        // for this we need to handle the case when encr exceeds lowercase limit
        if (encr > 122)
        {
            // create a temp to store the amount of characters by which encrypted number exceeds the limits
            int temp = encr - 122;
            // starting from the first character a at a position 96 shift by temp
            encr = 96 + temp;
        }
        // another edge case is when encrypted character is in the range of 90-97
        else if (encr > 90 && encr < 97)
        {
            // we calculate amount of characters by which encrypted number exceeds the limits
            int temp = encr - 90;
            // starting from the first character A at a position 90 shift by temp
            encr = 64 + temp;
        }
        // print encrypted character
        printf("%c", encr);
        // increment counter
        i++;
    }
    // print newline for better formatting
    printf("\n");
}