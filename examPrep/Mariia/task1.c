// include section
#include <stdio.h>
#include <stdlib.h>

int addFraction(int a, int c, int b, int d);
int subFraction(int a, int c, int b, int d);
int mulFraction(int a, int c, int b, int d);

int main(int argc, char *argv[])
{
    int userInput[] = {};
    for (int i = 0; i < 4; i++)
    {
        printf("Please input number %d ", i + 1);
        scanf("%d", &userInput[i]);
    }

    // ADD
    int addResult = addFraction(userInput[0], userInput[1], userInput[2], userInput[3]);
    if (addResult == 1)
    {
        printf("Operation successful!\n");
    }
    else
    {
        printf("Something went wrong...\n");
    }

    // SUBTRACT

    int subResult = subFraction(userInput[0], userInput[1], userInput[2], userInput[3]);
    if (subResult == 1)
    {
        printf("Operation successful!\n");
    }
    else
    {
        printf("Something went wrong...\n");
    }

    // MULTIPLY

    int mulResult = mulFraction(userInput[0], userInput[1], userInput[2], userInput[3]);
    if (mulResult == 1)
    {
        printf("Operation successful!\n");
    }
    else
    {
        printf("Something went wrong...\n");
    }
}

int addFraction(int a, int c, int b, int d)
{
    if (c == 0 || d == 0)
    {
        printf("Divisor can't be 0\n");
        return 0;
    }
    double mul = ((a * d) + (c * b));
    double result = mul / (c * d);
    printf("Result of adding fraction is %.2f\n", result);
    return 1;
}

int subFraction(int a, int c, int b, int d)
{
    if (c == 0 || d == 0)
    {
        printf("Divisor can't be 0\n");
        return 0;
    }
    double mul = ((a * d) - (c * b));
    double result = mul / (c * d);
    printf("Result of subtracting fraction is %.2f\n", result);
    return 1;
}

int mulFraction(int a, int c, int b, int d)
{
    if (c == 0 || d == 0)
    {
        printf("Divisor can't be 0\n");
        return 0;
    }
    double ab = a * b;
    double cd = c * d;
    double result = ab / cd;
    printf("Result of multiplying fraction is %.2f\n", result);
    return 1;
}
