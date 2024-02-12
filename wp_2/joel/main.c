// Includes section
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

// Enum declaration for day
enum day
{
    MON = 1, // Setting the first value == 1
    TUE, // == 2
    WED, // == 3
    THU, // == 4
    FRI, // == 5
    SAT, // == 6
    SUN  // == 7
};

// Enum declaration for week
enum week
{
    WEEK1 = 1, // Setting the first value == 1
    WEEK2, // == 2
    WEEK3, // == 3
    WEEK4, // == 4
    WEEK5  // == 5
};

// Function prototype, helper method to print the associated day
void printDay(int day, int week);

// Function prototype, helper method to clear buffer
void clearBuffer();

/**
 * This program takes two integers and prints the remaining days and weeks
 *
 * Purpose: To learn about enums
 * DIT633
 *
 * Author: Joel Celén, 2024
 **/

// Main program function
int main(int argc, char const *argv[])
{
    // Variable declarations for user input
    int weekInput, dayInput;

    // Take user and save it in the weekInput variable
    scanf("%d", &weekInput);
    // Function call to clear any remaining characters in the buffer
    clearBuffer();

    // Take user and save it in the dayInput variable
    scanf("%d", &dayInput);
    // Function call to clear any remaining characters in the buffer
    clearBuffer();

    // Error handling conditionals to prevent inputs that are outside of the allowed range
    if ((weekInput < WEEK1 || weekInput > WEEK5) && (dayInput < MON || dayInput > SUN)) // If both day and week inputs are out of allowed range
    {
        // Print error message
        printf("invalid\n");
        // Return to end program, should be 1 for unsuccessful execution, but because CodeGrade does not allow it this is 0
        return 0;
    }
    else if (dayInput < MON || dayInput > SUN) // If day value is out of allowed range
    {
        // Print error message
        printf("invalid day\n");
        // Return to end program, should be 1 for unsuccessful execution, but because CodeGrade does not allow it this is 0
        return 0;
    }
    else if (weekInput < WEEK1 || weekInput > WEEK5) // If week value is out of allowed range
    {
        // Print error message
        printf("invalid week\n");
        // Return to end program, should be 1 for unsuccessful execution, but because CodeGrade does not allow it this is 0
        return 0;
    }

    // Loop to print the messages to the user
    for (int week = weekInput; week <= WEEK5; week++) // From starting week up to and including week 5
    {
        for (int day = dayInput; day <= SUN; day++) // From starting day in the week up to and including Sunday
        {
            // Sleep for one second before proceeding to print
            sleep(1);
            // Prints message by calling the helper function printDay with the day and week fed as arguments
            printDay(day, week);
        }
        // After first loop, set "first day" to Monday for the consecutive weeks
        dayInput = MON;
    }
    // Return 0 for successful execution
    return 0;
}

// Helper function to prinnt the message that corresponds to the correct day and week
void printDay(int day, int week)
{
    // Beginning of switch case
    switch (day)
    {
    case MON: // If case is Monday
        // Print week and day
        printf("Week %d, Monday\n", week);
        // Break once day match case
        break;
    case TUE: // If case is Tuesday
        // Print week and day
        printf("Week %d, Tuesday\n", week);
        // Break once day match case
        break;
    case WED: // If case is Wednesday
        // Print week and day
        printf("Week %d, Wednesday\n", week);
        // Break once day match case
        break;
    case THU: // If case is Thursday
        // Print week and day
        printf("Week %d, Thursday\n", week);
        // Break once day match case
        break;
    case FRI: // If case is Friday
        // Print week and day
        printf("Week %d, Friday\n", week);
        // Break once day match case
        break;
    case SAT: // If case is Saturday
        // Print week and day
        printf("Week %d, Saturday\n", week);
        // Break once day match case
        break;
    case SUN: // If case is Sunday
        // Print week and day
        printf("Week %d, Sunday\n", week);
        // Break once day match case
        break;
    default: // Default case if "day" is out of range, prevented by error handling
        // Print default case
        printf("Invalid day of the week\n");
        // Break if argument does not match any case
        break;
    }
}

// Helper function to clear the buffer of any characters left after taking user input
void clearBuffer()
{
    // Declare temporary variable as int, this covers all ascii characters
    int tempChar;
    // While loop that uses the getchar function to clear every character in the buffer until it hits newline or EOF
    while ((tempChar = getchar()) != '\n' && tempChar != EOF){}
}