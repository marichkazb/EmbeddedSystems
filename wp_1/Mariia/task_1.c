// Includes section
#include <stdio.h>
#include <stdlib.h>

// Variable declaration
int userInput;
// Declare the function prototype
void scanner();

// Main function declaration
int main(int argc, char **argv)
{
    // Declare array of strings that will be used for output.
    // Since array of strings is by definition two-dimensional,
    // we assume that 5 is the max number of elements in the array and
    // 10 is the max number of characters in the string
    char outputArr[5][60] = {
        "Have a good day!",
        "You discovered a hidden treasure, congratulations!",
        "Gothenburg is a lovely city!",
        "Hint for the day: everything will work out in your favour",
        "Gratitude is a key to happiness"};
    // check if a number is provided when starting the program
    if (argc >= 2)
    {
        // if yes, then we will use is as a userInput value
        userInput = atoi(argv[1]);
    }
    // if number wasn't provided, the program will scan it
    else
        // call the helper function that contains functionality of prompting a string and reading the number
        scanner();
    // Continuously execute the function as long as the user input is in the range between 1 and 5
    while (userInput >= 1 && userInput <= 5)
    {
        // if the condition is true, then print one string from array that corresponds to the number user provided
        printf("%s\n", outputArr[userInput - 1]);
        // reuse the helper function to read user input
        scanner();
    }
    // print error message since the condition is not met
    printf("Number is out of range. Thank you for using the system, see you later. :)\n");
    // terminate the program
    return 0;
}
// helper function that contains reused functionality of printing a prompt and reading user input
void scanner()
{
    // print a prompt to user, so he is aware what he needs to do
    printf("Please input the number between 1 and 5.\n");
    // read user inout and store to userInput variable
    scanf("%d", &userInput);
}