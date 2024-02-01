// Include section
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Enum declarations

/**
 * Enum to account for weeks 1 to 5
*/
enum Weeks
{
    WEEK_1 = 1,
    WEEK_2 = 2,
    WEEK_3 = 3,
    WEEK_4 = 4,
    WEEK_5 = 5
};

/**
 * Enum to account for days of the week
*/
enum Days
{
    MONDAY = 1,
    TUESDAY = 2,
    WEDNESDAY = 3,
    THURSDAY = 4,
    FRIDAY = 5,
    SATURDAY = 6,
    SUNDAY = 7
};

// Function declarations
/**
 * Takes a week from the enum Weeks (or an integer),
 * and returns the correct string that represents it.
*/
char *getWeekString(enum Weeks weeks);

/**
 * Takes a day from the enum Days (or an integer),
 * and returns the correct string that represents it.
*/
char *getDayString(enum Days days);


/**
 * This program expects a week (1 to 5) and a day
 * of the week (1 to 7), and increments the days after
 * every second ending at week 5, sunday.
 * 
 * Purpose: Bonus question work package 2
 * DIT633
 * 
 * Author: Ionel Pop, 2024
 * 
**/
int main()
{
    char userInput[10];     // Buffer to register user input

    int startingWeek = 0;   // Variable to assign the starting week
    int startingDay = 0;    // Variable to assign the starting day

    printf("Provide starting week: \n");

    // Scan user input and save it into the buffera
    scanf("%s", userInput);

    // Convert the user input into an integer that represents the starting week
    startingWeek = atoi(userInput);

    printf("Provide starting day: \n");

    // Scan user input and save it into the buffer
    scanf("%s", userInput);

    // Convert the user input into an integer that represents the starting day
    startingDay = atoi(userInput);

    /**
     * Note: atoi will return 0 whenever the user input is invalid
    */

    // If the starting week is invalid
    if (startingWeek < 1 || startingWeek > 5)
    {
        // Print an appropiate error message and return 0
        printf("Invalid week\n");
        return 0;
    }

    // If the starting day is invalid
    if (startingDay < 1 || startingDay > 7)
    {
        // Print an appropiate error message and return 0
        printf("Invalid day\n");
        return 0;
    }

    // Iterate from starting week to WEEK_5
    for (int i = startingWeek; i <= WEEK_5; i++)
    {
        // Get the string representation of the current week
        char * currentWeek = getWeekString(i); // String that represents the current week

        // Iterate from starting day to SUNDAY
        for (int j = startingDay; j <= SUNDAY; j++)
        {
            // Get the string representation of the current day
            char * currentDay = getDayString(j); // String that represents the current day

            // Print according to the format "Week x, y"
            printf("%s, %s\n", currentWeek, currentDay);

            // Wait 1 second to continue the loop
            sleep(1);
        }

        /**
         * Reset starting day to 1.
         * This is used because the program needs to print every
         * day of the week after the starting week has been printed
        */
        startingDay = 1;
    }

    // Return 0 and finish the program when the execution was successful
    return 0;
}

char *getWeekString(enum Weeks weeks)
{
    /**
     * Switch statement to determine the string representation of a given week
    */
    switch (weeks)
    {
    case WEEK_1:
        // If the week is WEEK_1 (1), return "Week 1"
        return "Week 1";
    case WEEK_2:
        // If the week is WEEK_2 (2), return "Week 2"
        return "Week 2";
    case WEEK_3:
        // If the week is WEEK_3 (3), return "Week 3"
        return "Week 3";
    case WEEK_4:
        // If the week is WEEK_4 (4), return "Week 4"
        return "Week 4";
    case WEEK_5:
        // If the week is WEEK_5 (5), return "Week 5"
        return "Week 5";
    default:
        // Otherwise, return an empty string
        return "";
    }
}

char *getDayString(enum Days days)
{
    /**
     * Switch statement to determine the string representation of a given day
    */
    switch (days)
    {
    case MONDAY:
        // If the week is MONDAY (1), return "Monday"
        return "Monday";
    case TUESDAY:
        // If the week is TUESDAY (2), return "Tuesday"
        return "Tuesday";
    case WEDNESDAY:
        // If the week is WEDNESDAY (3), return "Wednesday"
        return "Wednesday";
    case THURSDAY:
        // If the week is THURSDAY (4), return "Thursday"
        return "Thursday";
    case FRIDAY:
        // If the week is FRIDAY (5), return "Friday"
        return "Friday";
    case SATURDAY:
        // If the week is SATURDAY (6), return "Saturday"
        return "Saturday";
    case SUNDAY:
        // If the week is SUNDAY (7), return "Sunday"
        return "Sunday";
    default:
        // Otherwise, return an empty string
        return "";
    }
}
