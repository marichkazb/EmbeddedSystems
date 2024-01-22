#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LOWER_BOUND 1
#define UPPER_BOUND 100
#define MAX_NUMBER 10

int main()
{
    srand(time(0)); // Seed

    int targetNumber = (rand() % (UPPER_BOUND - LOWER_BOUND + 1)) + LOWER_BOUND;

    int currentAttemps = 0;
    int currentGuess = 0;


    printf("The program generated a random number, try to guess it!\n");

    while (currentAttemps < MAX_NUMBER)
    {
        printf("Input a number: ");
        scanf("%d", &currentGuess);
        currentAttemps++;

        if (currentGuess == targetNumber)
        {
            printf("You have guessed %d times and your guess is correct!\n", currentAttemps);
            break;
        }
        else if (currentGuess > targetNumber) printf("Too high\n");
        else if (currentGuess < targetNumber) printf("Too low\n");
        
        if (currentAttemps >= MAX_NUMBER) printf("Sorry, you exceeded the number of attempts :(\n");
    }
    
    return 0;
}