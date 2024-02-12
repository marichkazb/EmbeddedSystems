// Include section
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>

int MAX = 10;
int main(void)
{
    int arr[MAX];
    int i = 0;
    srand(time(0));
    while (i < MAX)
    {
        arr[i] = rand() % 100;
        i++;
    }

    printf("The value of the address of the array (pointer) is %p\n", &arr);
    printf("First integer in the array is (array[0]): %d\n", arr[0]);
    printf("The last integer in the array is %d\n", arr[MAX - 1]);
    printf("The size of an integer (number of bytes) is %lu\n", sizeof(int));
    printf("The size of the whole array in bytes is %d\n", (int)sizeof(arr));

    printf("\nPrint array with pointers\n");
    int *ptr = arr;
    for (int i = 0; i < MAX; i++)
    {
        printf("%d - %d\n", i, *ptr);
        ptr++;
    }

    printf("\nPrint array with pointers multiplied by two\n");
    int *ptr2 = arr;
    for (int i = 0; i < MAX; i++)
    {
        printf("%d - %d\n", i, *ptr2 * 2);
        ptr2++;
    }
}
