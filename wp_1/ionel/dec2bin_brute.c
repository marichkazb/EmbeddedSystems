#include <stdio.h>

int main()
{
    int number = 1200;
    int buffer[20];

    int counter = 0;

    while(number > 0)
    {
        buffer[counter++] = number % 2;
        number /= 2;
    }

    counter--;

    while (counter >= 0)
    {
        int current = buffer[counter];
        printf("%d", current);
        counter--;
    }

    return 0;
}