// Includes section
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

// Create enumeration to store week numbers
// we will further use this enum to save and operate on the user input of week
enum weeks
{
    week1 = 1,
    week2 = 2,
    week3 = 3,
    week4 = 4,
    week5 = 5
};

// Create enumeration to store day numbers
// we will further use this enum to save and operate on the user input of day
enum daysOfWeek
{
    Mon = 1,
    Tue = 2,
    Wed = 3,
    Thu = 4,
    Fri = 5,
    Sat = 6,
    Sun = 7
};

// Helper function declaration, functions puprose is to clear buffer to prevent saving extra characters
void clearBuffer();

/**
 * This program takes two numbers for week and day and prints all days until the end of week 5
 *
 * Purpose: Learn and practice Enum usage in C
 * DIT633
 *
 * Author: Mariia Zabolotnia, 2024
 **/

// Main function declaration
int main(int argc, char **argv)
{
    // declare variable week
    int week;
    // declare variable day
    int day;

    // scan first number as input for week
    scanf("%d", &week);
    // clear buffer to prevent saving extra characters from user input
    clearBuffer();
    // scan second number as input for day
    scanf("%d", &day);
    // clear buffer to prevent saving extra characters from user input
    clearBuffer();

    // --- validation ---
    // if both inputs are not valid
    if ((week > week5 || week < week1) && (day > Sun || day < Mon))
    {
        // print general invalid statement
        printf("invalid\n");
        // terminate the program
        return 0;
    }
    // check the validity of the week input
    if (week > week5 || week < week1)
    {
        // print error message
        printf("invalid week\n");
        // terminate the program
        return 0;
    }
    // check the validity of the day input
    else if (day > Sun || day < Mon)
    {
        // print error message
        printf("invalid day\n");
        // terminate the program
        return 0;
    }

    // ---- printing result -----
    // execute the body of the loop while the week count is less than 5 as stated in the task
    for (int inputWeek = week; inputWeek <= week5; inputWeek++)
    {
        // take the variable day and execute body of the function while day is not 7 (7 days in the week)
        for (int inputDay = day; inputDay <= Sun; inputDay++)
        {
            // print week number
            printf("Week %d, ", inputWeek);
            switch (inputDay) // start control flow based on the value of variable day
            {
            case Mon:                  // if day == 1
                printf("Monday\n");    // print day of week
                break;                 // exit switch statement
            case Tue:                  // if day == 2
                printf("Tuesday\n");   // print day of week
                break;                 // exit switch statement
            case Wed:                  // if day == 3
                printf("Wednesday\n"); // print day of week
                break;                 // exit switch statement
            case Thu:                  // if day == 4
                printf("Thursday\n");  // print day of week
                break;                 // exit switch statement
            case Fri:                  // if day == 5
                printf("Friday\n");    // print day of week
                break;                 // exit switch statement
            case Sat:                  // if day == 6
                printf("Saturday\n");  // print day of week
                break;                 // exit switch statement
            case Sun:                  // if day == 7
                printf("Sunday\n");    // print day of week
                break;                 // exit switch statement
            default:                   // default fallback case when the value of day never matched aforementioned
                break;                 // exit switch statement
            }
            sleep(1); // delay printing by one second
        }
        // when all days in current week have been printed
        // reassign day to 1 to start printing from Monday of the new week
        day = Mon;
    }
    // terminate the program
    return 0;
}

// helper function to clear buffer
void clearBuffer()
{
    // declare helper variable
    int userInput;
    // Clear input buffer to prevent infinite loop
    while ((userInput = getchar()) != '\n' && (userInput != EOF))
        ; // empty body because we intend to just iterate on input characters
}
