#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b);
int compare(const void *a, const void *b);
typedef struct
{
    char lname[20];
    char fname[20];
    char street[20];
    int age;
} REGTYPE;
int main()
{
    // swap two numbers
    int a = 5;
    int b = 7;
    printf("a = %i, b = %i\n", a, b);
    printf("&a = %p, &b = %p\n", &a, &b);
    swap(&a, &b);
    printf("a = %i, b = %i\n", a, b);

    // quick sort
    int arr[] = {10, 5, 15, 12, 90, 80};
    // gets number of elements in the array
    // by dividing size of all elements in the arr by size of type stored in the arr
    int n = sizeof(arr) / sizeof(arr[0]), i;
    printf("%d, %lu, %lu\n", n, sizeof(arr), sizeof(arr[0]));

    qsort(arr, n, sizeof(int), compare);

    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    REGTYPE records[3];
    REGTYPE *postP = records;
    fgets(postP->fname, 20, stdin);
    postP = postP + 2;
    fgets(postP->fname, 20, stdin);
    for (int i = 0; i < 3; i++)
    {
        printf("Record %i: fname - %s lname - %s\n", i, records[i].fname, records[i].lname);
    }

    return 0;
}
int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}