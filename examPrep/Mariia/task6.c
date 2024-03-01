#include <stdio.h>
#include <stdlib.h>

// Write a program in C to add two numbers using pointers.
int main(int argc, char *argv[])
{
    int a, b, result;
    printf("Input the first num\n");
    scanf("%d", &a);
    printf("Input the second num\n");
    scanf("%d", &b);

    int *ptr_a, *ptr_b;
    ptr_a = &a;
    ptr_b = &b;
    result = *ptr_a + *ptr_b;
    printf("The sum of the entered numbers is : %d\n", result);
    return 0;
}