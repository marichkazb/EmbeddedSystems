#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 20

#define MAX_VALUE 99

int main()
{
    printf("Creating a random array with %d items\n\n", MAX);
    srand(time(0));
    int* randomArray = (int*)malloc(MAX * sizeof(int));
    for (int i = 0; i < MAX; i++)
    {
        randomArray[i] = 1 + (int)rand()%MAX_VALUE;
    }

    printf("The value of the address of the array (pointer) is: %p\n", (void*)&randomArray);
    printf("First integer in the array is (array[0]): %d\n", randomArray[0]);
    printf("The last integer in the array is: %d\n", randomArray[MAX - 1]);
    printf("The size of an integer (number of bytes) is: %ld\n", sizeof(int));
    printf("The size of the whole array in bytes is: %ld\n\n", MAX * sizeof(int));

    int counter = 0;
    int *pArray = randomArray;
    printf("Printing each value: \n");
    while (counter < MAX)
    {
        printf("\tValue: %d \t|\t Value times 2: %d\n", *pArray, *pArray * 2);
        pArray++;
        counter++;
    }
    printf("\n");
}