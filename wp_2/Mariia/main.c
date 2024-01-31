// Includes section
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

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

// Helper function declaration
void delay(int delay);

// Main function declaration
int main(int argc, char **argv)
{
    // declare variable week of type enum weeks
    enum weeks week;
    // declare variable day of type enum daysOfWeek
    enum daysOfWeek day;
    // scan first number as input for week
    scanf("%u", &week);
    // scan second number as input for day
    scanf("%u", &day);
    // if both inputs are not valid
    if ((week > 5 || week < 1) && (day > 7 || day < 1))
    {
        // print general invalid statement
        printf("invalid \n");
        // terminate the program
        return 0;
    }
    // check the validity of the week input
    if (week > 5 || week < 1)
    {
        // print error message
        printf("invalid week\n");
        // terminate the program
        return 0;
    }
    // check the validity of the day input
    if (day > 7 || day < 1)
    {
        // print error message
        printf("invalid day\n");
        // terminate the program
        return 0;
    }
    // execute the body of the loop while the week count is less than 5 as stated in the task
    while (week <= 5)
    {
        // take the variable day and execute body of the function while day is not 7 (7 days in the week)
        for (; day <= 7; day++)
        {
            // print week number
            printf("Week %d, ", week);
            switch (day) // start control flow based on the value of variable day
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
            delay(100); // delay printing by one second
        }
        // when all days in current week have been printed
        // increment week to continue printing
        week++;
        // reassign day to 1 to start printing from Monday of the new week
        day = 1;
    }
    // terminate the program
    return 0;
}

// helper function to create delay between printing to console
void delay(int delay) // delay is in seconds
{
    // utilising in-built function clock() create a variable to store time at the moment
    clock_t timeStamp = clock();
    // until time now - clock() - is less than the start time incremented by delay in milliseconds
    // then execute empty body of while loop, so basically do nothing
    while (clock() < (timeStamp + delay * 1000))
        ; // empty body since we want to stop the program while waiting
}