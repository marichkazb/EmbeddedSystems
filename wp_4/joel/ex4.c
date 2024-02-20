// (C) Joel Celén, group: 8__ (2024)
// Work package 4
// Exercise 4
// Submission code:  (provided by your TA-s)

// Include section
#include <stdio.h>
#include <stdlib.h>

// Define section
#define ARRAY_SIZE 10

// Function prototypes
int search_number(int number, int tab[], int size);
void sort(int tab[]);
void swapValue(int *pFirst, int *pSecond);
void printArray(int tab[], int size);

// Example array
int test[] = {1, 2, 34, 5, 67, 3, 23, 12, 13, 10};

// Main function
int main(int argc, char const *argv[])
{
    // Print the array before sorting
    printArray(test, ARRAY_SIZE);

    // Search for number in specified array with specified size
    int inList = search_number(100, test, ARRAY_SIZE);

    // If search_number function returns -1
    if (inList == -1)
    {
        // Print message
        printf("Number not in array.\n");
    }
    // If search_number function returns -1
    else
    {
        // Print index of number
        printf("Index is: %d\n", inList);
    }
    // Call soring on specified array
    sort(test);
    // Print array again after sorting
    printArray(test, ARRAY_SIZE);
    // Return 0 for successful execution
    return 0;
}

// Function to search for a number in an array of a specified size
int search_number(int number, int tab[], int size)
{
    // For every number in array
    for (int i = 0; i < size; i++)
    {
        // If provided number is same as number at index i
        if (number == tab[i])
        {
            // Return index
            return i;
        }
    }
    // Else, return -1 for not found
    return -1;
}

// Sorting function, selection sort
void sort(int tab[])
{
    // For every number in array
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        // Minimum value set to first value of array
        int *minVal = &tab[i];
        // For every number in array not already sorted
        for (int j = i; j < ARRAY_SIZE; j++)
        {
            // If value at j is smaller than minVal
            if (tab[j] < *minVal)
            {
                // minVal becomes value at j
                minVal = &tab[j];
            }
        }
        // Call function to swap values at minVal and i
        swapValue(minVal, &tab[i]);
    }
}

// Helper function to swap values of two pointers
void swapValue(int *pFirst, int *pSecond)
{
    // Store value at pFirst in temporary variable
    int tempValue = *pFirst;
    // Value at pFirst takes value at pSecond
    *pFirst = *pSecond;
    // Value at pSecond takes temp value
    *pSecond = tempValue;
}

// Function to print array
void printArray(int tab[], int size)
{
    // Print formatting
    printf("Numbers in the array are: ");

    // For every index in array
    for (int i = 0; i < size; i++)
    {
        // Print value at index i
        printf("%d ", tab[i]);
    }
    // Print newline for ease of reading
    printf("\n");
}