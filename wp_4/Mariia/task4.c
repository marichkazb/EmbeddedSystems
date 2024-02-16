// Include section
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// function finds the number in the array and returns its index, or returns -1 if the num is not in the array
int search_number(int number, int tab[], int size);
// function sorts array in place utilizing bubble sort algorithm
void bubble_sort(int number, int tab[]); // bubble sort
// function sorts array in place utilizing selection sort algorithm
void selection_sort(int number, int tab[]); // selection sort
// function to swap two elements, takes pointers to the elements to be swapped
void swap(int *a, int *b);

// main function declaration
int main(int argc, char *argv[])
{
    // declare array to store items we will be iterating over
    int test[] = {1, 2, 34, 5, 67, 3, 23, 12, 13, 10};
    // declare a variable to store item we are looking for
    int num_to_find = 3;
    // finding number of elements in the array by dividing size of the array by the size of every element
    int array_size = sizeof(test) / sizeof(test[0]);
    // execute function to get number index
    int result = search_number(num_to_find, test, array_size);
    // print the message depending on the result
    result == -1 ? printf("Didn't find number %d in the array\n", num_to_find) : printf("Index of number %d is: %d\n", num_to_find, result);

    // execute function to sort the array using bubble_sort
    // bubble_sort(array_size, test);

    // execute function to sort the array using bubble_sort
    selection_sort(array_size, test);

    // print user message
    printf("Sorted array: \n");
    // iterate over all elements of the sorted array
    for (int i = 0; i < array_size; i++)
    {
        // print all elements of the sorted array
        printf("%d ", test[i]);
    }
    printf("\n");
    // terminate the program
    return 1;
}

// function finds the number in the array and returns its index, or returns -1 if the num is not in the array
int search_number(int number, int tab[], int size)
{
    // initialize pointer to the first element of the array
    int *ptr = tab;
    // while pointer doesn't reach the address of the last element in the array search for the number
    while (ptr < &tab[size - 1])
    {

        // if the value of the cell pointer is pointing to is equal to the number we are looking for
        if (*ptr == number)
        {
            // return the index of the element
            return ptr - tab;
        }
        // move pointer to the next element
        ptr++;
    }
    // if n is not in the array, then return -1
    return -1;
}

// function that sorts the array in place
void bubble_sort(int number, int *tab)
{
    // loop over the elements starting with 0. for the current element we need to check if there are any items that are smaller that curr
    for (int i = 0; i < number - 1; i++)
    {
        // check the items in the right part of the array and see if there are any that are less than the current one
        for (int j = 0; j < number - i - 1; j++)
        {
            // if we found element that is smaller
            // we are using pointer to the first element of the array and j as a counter to how many positions to shift pointer in the array
            if (*(tab + j) > *(tab + j + 1))
            {
                // swap current and found element
                swap((tab + j), (tab + j + 1));
            }
        }
    }
}

// function that sorts the array in place using selection sort
void selection_sort(int number, int tab[])
{
    // for every item in the array, execute the following
    for (int i = 0; i < number - 1; i++)
    {
        // initialize minimum as the first element of the array
        int min = i;
        // then repetitively check every other item in the array to find the new min
        for (int j = i + 1; j < number; j++)
        {
            // if the element is less than the current minimum
            if (tab[j] < tab[min])
            {
                // assign the new minimum
                min = j;
            }
        }
        // swap current item and the found minimum item
        swap(&tab[min], &tab[i]);
    }
}

// function to swap two items, takes pointers to the items to be able to pass them as pass-by-reference and swap
void swap(int *a, int *b)
{
    // store value of the first item in temp
    int temp = *a;
    // assign value of the second one to the first one
    *a = *b;
    // assign value of the temp to the second one
    *b = temp;
}