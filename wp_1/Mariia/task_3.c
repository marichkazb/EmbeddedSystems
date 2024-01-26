// Includes section
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int MAX_NUMBER = 100;   // defines max number of allowed guesses
int playGame();         // defines prototype of the helper function
void successfulGuess(); // defines prototype of the helper function

// Main function declaration
int main(int argc, char **argv)
{
    // execute game functionality
    playGame();
    // terminate the program
    return 0;
}

// helper function that contains the game logic
int playGame()
{
    int randomNum = 1 + (rand() % 100);             // generate random num from 1 to 100 utilizing rand() in-build function
    int userInput = 0;                              // initialize user input to 0
    int guessCounter = 0;                           // initialize counter of guesses to 0
    printf("Guess the number between 1 and 100\n"); // print user prompt

    // repeat the function while number of guesses doesn't exceed defined max number
    while (guessCounter < MAX_NUMBER)
    {
        int isValidInput = 0; // initialize the variable to keep track of validity check of the input
        while (!isValidInput) // keep asking for user input until it is of correct format and is valid
        {
            // in case if the user input is not of correct type of number or the number is not in the range of 1-100
            if (scanf("%d", &userInput) != 1 || userInput > 100 || userInput < 1)
            {
                // Clear input buffer to prevent infinite loop
                // https://www.tutorialspoint.com/clearing-input-buffer-in-c-cplusplus#:~:text=The%20function%20fflush(stdin)%20is,feof%20error%20indicator%20is%20set.
                fflush(stdin);
                // print user message to explain the mistake
                printf("Your input is out of bound. Enter a number between 1 and 100.\n");
            }
            else // in case user input has passed validity check
            {
                // terminate while loop for validity
                isValidInput = 1;
            }
        }
        // case when user guessed the game
        if (userInput == randomNum)
        {
            // call helper function to handle success scenario
            successfulGuess(guessCounter);
            // terminate the program since if the successfulGuess control flow returned here, then user presses "n" meaning stop the game
            return 0;
        }
        else if (userInput < randomNum)
            // print a prompt to navigate the user
            printf("Your number is too low, try again\n");
        else
            // print a prompt to navigate the user
            printf("Your number is too high, try again\n");
        // increase guess counter by 1
        guessCounter++;
    }
    // terminate the program
    return 0;
}

// helper function to execute when user guessed the number
void successfulGuess(int guessCounter)
{
    printf("Congratulations! You have guessed %i times and your guess is correct!\n", guessCounter); // print success message
    printf("Do you want to play again? y-Yes n-No\n");                                               // suggest to play again or end the game
    char playAgain;                                                                                  // initialize variable to contain user input if he wants to continue the game
    scanf("%s", &playAgain);                                                                         // get user input if he wants to continue
    if (strcmp(&playAgain, "n") == 0)                                                                // in case if he typed n the game will print the message and finish
    {
        // print final message of the game
        printf("Good bye!\n");
    }
    else // case for when user wants to continue the game
    {
        // call helper function to start the game again
        playGame();
    }
}