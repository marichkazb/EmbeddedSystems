// Include section
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// TODO: ask why it doesn't give me an error if freq[10] doesn't exist
// TODO: ask if I can modify the signatures
// TODO: ask if it's ok to remove 'n'

// #define MAX 100         // Defines the maximum number of values in the table
// #define MAXNUMBER 20    // Defines the maximum value of random numbers

// ------ Function declarations ----------

// This function generates a set of random numbers
// and fills the table *tab with these numbers
void create_random(int *tab, int n, int maxNumber);

// This function takes the *tab of random numbers
// and creates a table with the frequency counts for these numbers
void count_frequency(int *tab, int *freq, int n, int maxNumber);

// This function takes the frequency count table
// and draws a histogram of the values in that frequency table
void draw_histogram(int *freq, int maxNumber);

// This function prints an array
void print_array(int *arr, int n);

// ------ Main --------------------------

/**
 * This program generates a random integer array,
 * counts the frequency of each number in the array,
 * and prints an histogram with the values
 *
 * Purpose: Pointers
 * DIT633
 *
 * Author: Ionel Pop, Joel Celen, Mariia Zabolotnia, 2024
 *
 **/
int main(int argc, char** argv)
{
    // If the provided command line arguments are not enough
    if (argc < 3)
    {
        // If the command line arguments are 2
        if (argc == 2)
        {
            // Check if the command line argument provided is the flag `-h`
            if (strcmp(argv[1], "-h") == 0)
            {
                // Print instructions for the program
                printf("To use this program provide:\n\t- the `maximum number of values`,and\n\t- the `maximum value`\nas command line arguments\n");
                return 0;
            }
        }
        // Otherwise, print an appropiate error message and return 0
        printf("Error! Not enough arguments\n");
        printf("Provide flag -h to display instructions\n");
        return 0;
    }

    // Generate a seed based on the current time to use with the random function
    srand(time(0));

    int maxValues = atoi(argv[1]); // Maximum number of values from the command line arguments
    int maxNumber = atoi(argv[2]); // Maximum value from the command line arguments

    // If one of those values is 0
    if (maxValues == 0 || maxNumber == 0)
    {
        // Print an appropiate error message and return 1
        printf("Error! Can't provide '0' as argument\n");
        return 1;
    }

    int table[maxValues]; // Initialize an array of maxValues integers
    int frequency[maxNumber]; // Initialize an array of maxNumber integers

    // Call the function create_random
    create_random(table, maxValues, maxNumber);
    // Call a  helper function to print the table array
    print_array(table, maxValues);

    // Call the function count_frequency
    count_frequency(table, frequency, maxValues, maxNumber);
    // Call a  helper function to print the table array
    print_array(frequency, maxNumber);

    // Call the function draw_histogram
    draw_histogram(frequency, maxNumber);
}

// ------ Function definitions ----------

void create_random(int *tab, int n, int maxNumber)
{
    // Iterate from 0 to n
    for (int i = 0; i < n; i++)
    {
        // Populate the current location in the array with a random number between 0 and maxNumber
        tab[i] = rand() % (maxNumber);
    }
}

void count_frequency(int *tab, int *freq, int n, int maxNumber)
{
    // Iterate from 0 to maxNumber
    for (int i = 0; i < maxNumber; i++)
    {
        // Initialize the array to {0, 0, 0, ..., 0}
        freq[i] = 0;
    }

    // Iterate from 0 to n
    for (int i = 0; i < n; i++)
    {
        // Get the current number from the table
        int currentNumber = tab[i];

        // Update the counter for that number in the frequency table
        freq[currentNumber] += 1;
    }
}

void draw_histogram(int *freq, int maxNumber)
{
    printf("Printing histogram...\n");
    // Iterate from 0 to maxNumber in the frequency table
    for (int i = 0; i < maxNumber; i++)
    {
        // If the frequency count for the current number in the frequency table is more than 0
        if (freq[i] > 0)
        {
            // Print the number
            printf("%d\t", i);

            // Iterate from 0 to the frequency count
            for (int j = 0; j < freq[i]; j++)
            {
                // Print the corresponding number of Xs to the frequency
                printf("X");
            }

            // Print end of line to account for proper formatting
            printf("\n");
        }
    }
    printf("End of the histogram :)\n\n");
}

void print_array(int *arr, int n)
{
    printf("Printing array...\n");
    printf("[");
    // Iterate through the array
    for (int i = 0; i < n - 1; i++)
    {
        // Print the data in the array
        printf("%d, ", arr[i]);
    }
    // Print the last element of the array + formatting
    printf("%d]\n", arr[n - 1]);
    printf("That was the array :)\n\n");
}
