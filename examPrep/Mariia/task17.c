#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Write a C program to input marks of five subjects Physics, Chemistry, Biology, Mathematics and Computer
// calculate percentage and grade according to given conditions:

void clearBuffer()
{
    char temp;
    while ((temp = getchar()) != '\n' || temp != EOF)
    {
        ;
    }
}
int main(void)
{
    int physics, chemistry, biology, mathematics, computer;
    printf("Input 5 grades: \n");
    scanf("%d %d %d %d %d", &physics, &chemistry, &biology, &mathematics, &computer);

    double percentage = (physics + chemistry + biology + mathematics + computer) / 5.0;
    char grade;
    if (percentage >= 90)
    {
        grade = 'A';
    }
    else if (percentage >= 80)
    {
        grade = 'B';
    }
    else if (percentage >= 70)
    {
        grade = 'C';
    }
    else if (percentage >= 60)
    {
        grade = 'D';
    }
    else if (percentage >= 40)
    {
        grade = 'E';
    }
    else
    {
        grade = 'F';
    }
    printf("Percentage is: %.2f\n", percentage);
    printf("Grade is: %c\n", grade);
    return 0;
}