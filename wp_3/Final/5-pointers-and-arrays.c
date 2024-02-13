// (C) __Mariia Zabolotnia, Joel Celén, Ionel Pop, group: 8__ (2024)
// Work package 3
// Exercise 5
// Submission code: 908233 (provided by your TA-s)

/** ----- Instructions -----
 * Write a program that creates an array of integers, array[MAX],
 * and then fill it with MAX number of random integers from 1 to 99.
 * Let then the program prints out the following:
 *
 * The value of the address of the array (pointer) is: xxxxxxxxxx
 * First integer in the array is (array[0]): xxxxxxxxxx
 * The last integer in the array is: xxxxxxxxxx
 * The size of an integer (number of bytes) is: xxxxxxxxx
 * The size of the whole array in bytes is: xxxxxxxxx
 *
 * The program shall then, by use of a pointer, print out each integer value,
 * and then print the value multiplied by two.
 **/

// Includes section
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define section
#define MAX 6

// Function prototypes
void printInfo(int *startPtr, int *endPtr);                      // Function that prints info text
void populateArray(int *startPtr, int *endPtr, int *currentPtr); // Function that populates array with use of pointers
void printArray(int *startPtr, int *endPtr, int *currentPtr);    // Function that prints all values of array with use of pointers

// Main function
int main(int argc, char const *argv[])
{
    // Check for correct argument amount
    if (argc == 1)
    {
        // Set a random seed
        srand(time(0));

        // Array declaration and initialization
        int array[MAX];                // Initialize array with max value of integers
        int *startPtr = &array[0];     // Set pointer to first element in array
        int *endPtr = &array[MAX - 1]; // Set pointer to last element in array
        int *currentPtr = startPtr;    // Set current pointer to startPtr

        // Populate the array with random numbers
        populateArray(startPtr, endPtr, currentPtr);
        // Print info text
        printInfo(startPtr, endPtr);
        // Print every element of the array
        printArray(startPtr, endPtr, currentPtr);
    }
    else
    {
        // Print error message
        printf("Pleas do not enter any arguments.\n");
        // Return 1 for failed execution
        return 1;
    }

    // Return 0 for successful operation
    return 0;
}

// Function that prints info
void printInfo(int *startPtr, int *endPtr)
{
    // Prints the desired info
    printf("\nThe value of the address of the array (pointer) is: %p\n"
           "First integer in the array is (array[0]): %d\n"
           "The last integer in the array is: %d\n"
           "The size of an integer (number of bytes) is: %d\n"
           "The size of the whole array in bytes is: %d\n",
           startPtr,   // Address of start
           *startPtr,  // Value stored at address of start pointer
           *endPtr,    // Value stored at address of end pointer
           4,          // Size of an integer in bytes
           (MAX * 4)); // Number of integers in array * bytes
}

// Function that prints every index of array using pointer arithmetics
void printArray(int *startPtr, int *endPtr, int *currentPtr)
{
    // For every index in the array
    while (currentPtr <= endPtr) // While currentPtr is lower or equal to endPtr
    {
        // Print information of current index
        printf("\nThe value of the address of current pointer is: %p\n"
               "The value of integer: %d\n"
               "Double value of integer: %d\n",
               currentPtr,         // Address of currentPtr
               *currentPtr,        // Value stored at address of currentPtr
               (*currentPtr * 2)); // Value stored at address of start pointer * 2

        // Increment pointer
        currentPtr++;
    }
    // Reset currentPtr to the address at the start of the array
    currentPtr = startPtr;
}

// Function that populates array using pointer arithmetics
void populateArray(int *startPtr, int *endPtr, int *currentPtr)
{
    // For every index in array
    while (currentPtr <= endPtr) // While currentPtr is lower or equal to endPtr
    {
        // Generate a random number between 0 - 99
        int randNum = rand() % 100;
        // Populate value at currentPtr
        *currentPtr = randNum;
        // Increment pointer
        currentPtr++;
    }
    // Reset currentPtr to the address at the start of the array
    currentPtr = startPtr;
}
