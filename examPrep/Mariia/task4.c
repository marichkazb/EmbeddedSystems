#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Write a program that, given a date, three ints (for example, 11 27 1997), will print the number of
// that day within its year: i.e. Jan 1st is always 1, Dec 31st is either 365 or 366.

void clearBuffer();
int daysInMonth(int month, int year);

int main(int argc, char *argv[])
{
    int day, month, year;
    printf("Input day ");
    scanf("%d", &day);
    clearBuffer();
    printf("Input month ");
    scanf("%d", &month);
    clearBuffer();
    printf("Input year ");
    scanf("%d", &year);
    clearBuffer();
    if (day <= 0 || day > 32 || month <= 0 || month > 12 || year <= 0)
    {
        printf("Invalid parameters\n");
        return 0;
    }
    int dayCounter = day;
    for (int i = 1; i < month; i++)
    {
        if (month == 1)
        {
            break;
        }
        dayCounter += daysInMonth(i, year);
    }
    printf("Days in the given date: %d\n", dayCounter);
    return 0;
}

int daysInMonth(int month, int year)
{
    if (month <= 7 && month % 2 == 1) // The odd months up to and including month 7 have 31 days
    {
        return 31;
    }
    else if (month >= 8 && month % 2 == 0) // The even months from 8 upwards, have 31 days.
    {
        return 31;
    }
    else if (month == 2) // Month 2 has 28 days except in a leap year when it has 29 days.
    {
        return year % 4 == 0 ? 29 : 28;
    }
    else
    {
        return 30; // The rest of the months have 30 days.
    }
}
void clearBuffer()
{
    char temp;
    while ((temp = getchar()) != '\n' && temp != EOF)
    {
        ;
    }
}
