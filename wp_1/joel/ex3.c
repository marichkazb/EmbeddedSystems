#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NUMBER 10

void gameOver();
int roundCounter = MAX_NUMBER;
int randomNumber;
int guessedNumber;

int main(int argc, char const *argv[])
{
    srand((unsigned int)time(NULL));
    randomNumber = rand() % 101;

    printf("Hello gamer, to play this amazing game you simply have to guess the correct number between 1 and 100. Please input your guess below:\n");
    scanf("%d", &guessedNumber);

    while (roundCounter > 0)
    {
        roundCounter--;
        printf("Guesses left: %d\n", roundCounter);

        if (roundCounter == 0)
        {
            printf("Too bad, you are out of guesses.\n");
            gameOver();
        }
        else if (guessedNumber > randomNumber)
        {
            printf("Oh no! you chose a number that is too high, try again!\n");
            scanf("%d", &guessedNumber);
        }
        else if (guessedNumber < randomNumber)
        {
            printf("Womp womp, too low of a number, try again!\n");
            scanf("%d", &guessedNumber);
        }
        else
        {
            printf("Great job!! You found the correct integer!\n");
            gameOver();
        }
    }
    printf("Thanks for playing!\n");
    return 0;
}

void gameOver()
{

    char keepPlaying[3];

    printf("Do you wanna play again? y/n\n");
    scanf(" %c", &keepPlaying[0]);
    if (keepPlaying[0] == 'y')
    {
        randomNumber = rand() % 101;
        roundCounter = MAX_NUMBER;
        printf("Great choice my friend, now input your next guess!\n");
        scanf("%d", &guessedNumber);
    }
    else
    {
        roundCounter = 0;
    }
}
