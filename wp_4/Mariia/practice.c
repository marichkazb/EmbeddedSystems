// Include section
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// practice pointers to understand them better

double getAverage(int *arr, int size);
void modifyValue(int *ptr);

int main(void)
{
    int arr[] = {2, 3, 4, 9};
    double result = getAverage(arr, 4);
    printf("Result is: %f\n", result);

    int a = 5;
    printf("A is %d\n", a);
    modifyValue(&a);
    printf("A is incremented! %d\n", a);

    int test[5] = {1, 2, 3, 4, 5};
    int *ptrArr = test; // Array name gives the base address

    int element = *(ptrArr + 2); // Access the third element (index 2)
    printf("element: %i\n", *ptrArr);
    return 0;
}

// passing pointers to function
double getAverage(int *arr, int size)
{
    // printf("arr: %d", arr);
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum = sum + arr[i];
    }
    return sum / size;
}

// passing pointer to function
void modifyValue(int *ptr)
{
    (*ptr)++;
}