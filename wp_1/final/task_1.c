// (C) __Mariia Zabolotnia, Joel Celén, Ionel Pop, group: 8__ (2024)
// Work package 1
// Exercise 1
// Submission code: 098890 (provided by your TA-s)

// Includes section
#include <stdio.h>
#include <string.h>

// Declare global variable
int input;

// Function prototype declaration
void takeInput();

/**
 *
 * Purpose: Learning C programming
 * DIT633
 *
 * Author: Joel Celén, Ionel Pop, Mariia Zabolotnia 2024
 *
 **/

// Main function
int main(int argc, char **argv)
{
    // If there are no user arguments
    if (argc == 1)
    {
        // Invoke takeInput() function, see line 66
        takeInput();

        // While input is within accepted range (1-5), continue the loop
        while (input >= 1 && input <= 5)
        {
            // If input is 1, print corrsponding message
            if (input == 1)
            {
                printf("Wow, great job, entering the lowest in the range.\n");
            }
            // If input is 2, print corrsponding message
            else if (input == 2)
            {
                printf("Next lowest integer, got it.\n");
            }
            // If input is 3, print corrsponding message
            else if (input == 3)
            {
                printf("Did you really choose the most mid integer? Lame.\n");
            }
            // If input is 4, print corrsponding message
            else if (input == 4)
            {
                printf("Four is a good number, great choice.\n");
                // Invoke takeInput() function, see line 66
            }
            // If input is 5, print corrsponding message
            else if (input == 5)
            {
                printf("The largest integer? Try-hard.\n");
            }
            // Invoke takeInput() function, see line 66
            takeInput();
        }
        // If integer entered is out of accepted range, print error message
        printf("The integer you picked is outside of the allowed range, great job of reading the instructions.\n");
    }
    // Return 0 for successful execution
    return 0;
}

// Function for prompting user to input an integer and saving the input to the specified memory location, returns void
void takeInput()
{
    // Prints prompt message
    printf("Please enter an integer between 1 and 5.\n");
    // Takes input in decimal and save it to the specified memory address
    scanf("%d", &input);
}
