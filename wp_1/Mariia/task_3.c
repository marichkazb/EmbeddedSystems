#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int MAX_NUMBER = 100;
int playGame();
void successfulGuess();

int main(int argc, char **argv)
{
    playGame();
    return 0;
}

int playGame()
{
    int randomNum = 1 + (rand() % 100);
    int userInput = 0;
    int guessCounter = 0;
    printf("Guess the number between 1 and 100\n");

    while (guessCounter < MAX_NUMBER)
    {
        int isValidInput = 0;
        while (!isValidInput)
        {
            if (scanf("%d", &userInput) != 1 || userInput > 100 || userInput < 1)
            {
                // Clear input buffer to prevent infinite loop
                // https://www.tutorialspoint.com/clearing-input-buffer-in-c-cplusplus#:~:text=The%20function%20fflush(stdin)%20is,feof%20error%20indicator%20is%20set.
                fflush(stdin);
                printf("Your input is out of bound. Enter a number between 1 and 100.\n");
            }
            else
            {
                isValidInput = 1;
            }
        }
        if (userInput == randomNum)
        {
            successfulGuess(guessCounter);
            return 0;
        }
        else if (userInput < randomNum)
            printf("Your number is too low, try again\n");
        else
            printf("Your number is too high, try again\n");

        guessCounter++;
    }
    return 0;
}

void successfulGuess(int guessCounter)
{
    printf("Congratulations! You have guessed %i times and your guess is correct!\n", guessCounter);
    printf("Do you want to play again? y-Yes n-No\n");
    char playAgain;
    scanf("%s", &playAgain);
    if (strcmp(&playAgain, "n") == 0)
    {
        printf("Good bye!\n");
    }
    else
    {
        playGame();
    }
}