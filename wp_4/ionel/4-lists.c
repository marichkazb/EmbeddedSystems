#include <stdio.h>

int search_number(int number, int tab[], int size);

void sort(int tab[], int size);

void printArray(int *arr, int n);

void swap(int arr[], int idxA, int idxB);

int main()
{
    int test[] = {1, 2, 34, 5, 67, 3, 23, 12, 13, 10};
    int size = sizeof(test) / sizeof(int);

    printf("Find 1: %d\n", search_number(1, test, size));
    printf("Find 67: %d\n", search_number(67, test, size));
    printf("Find 124: %d\n", search_number(124, test, size));

    printf("Sorting array\n");
    sort(test, size);
    printf("Sorted array:\n");
    printArray(test, size);
    return 0;
}

int search_number(int number, int tab[], int size)
{
    int indexResult = -1;

    for (int i = 0; i < size; i++)
    {
        if (tab[i] == number)
        {
            indexResult = i;
            return i;
        }
    }

    return indexResult;
}

void sort(int tab[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf(".");
        int minItemIdx = i;
        for (int j = i + 1; j < size; j++)
        {
            if (tab[j] < tab[minItemIdx])
            {
                minItemIdx = j;
            }
        }
        // Swap
        swap(tab, i, minItemIdx);
    }
    printf("\n");
}

void printArray(int arr[], int n)
{
    printf("[");
    for (int i = 0; i < n - 1; i++)
    {
        printf("%d, ", arr[i]);
    }
    printf("%d]\n", arr[n - 1]);
}

void swap(int arr[], int idxA, int idxB)
{
    int tmp = arr[idxA];
    arr[idxA] = arr[idxB];
    arr[idxB] = tmp;
}
