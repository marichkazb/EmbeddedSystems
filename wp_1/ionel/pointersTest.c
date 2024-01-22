#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// TODO: ask why it doesn't give me an error if freq[10] doesn't exist
// TODO: ask if I can modify the signatures

#define MAX 20         // Defines the maximum number of the values in the table
#define MAXNUMBER 15    // Defines the maximum value of random numbers

// ------ Function declarations ----------

// This function generates a set of random numbers
// and fills the table *tab with these numbers
void create_random(int *tab);

// This function takes the *tab of random numbers
// and creates a table with the frequency counts for these numbers
void count_frequency(int *tab, int *freq);

// This function takes the frequency count table
// and draws a histogram of the values in that frequency table
void draw_histogram(int *freq);

// TEST
void print_array(int *arr, int n);

// ------ Function definitions ----------

// ------ Main --------------------------

// The main entry point for the program
//
// If you choose to go for the optional part
// Please modify it accordingly
int main(void)
{
    srand(time(0));

    // int table[MAX], n;
    int table[] = {1,2,12,5,1,0,0,5,9,12,0,2,3,0};
    int frequency[MAXNUMBER];

    // create_random(table);
    print_array(table, 14);

    count_frequency(table, frequency);
    print_array(frequency, MAXNUMBER);

    draw_histogram(frequency);
}

void create_random(int *tab)
{
    for (int i = 0; i < MAX; i++)
    {
        tab[i] = rand() % (MAXNUMBER);
    }
}

void count_frequency(int *tab, int *freq)
{
    for (int i = 0; i < MAXNUMBER; i++)
    {
        // Initialize the array to {0, 0, 0, ..., 0}
        freq[i] = 0;
    }

    for (int i = 0; i < 14; i++)
    {
        int currentNumber = tab[i];
        freq[currentNumber] += 1;
    }
}

void print_array(int *arr, int n)
{
    printf("Printing array...\n");
    printf("[");
    for (int i = 0; i < n - 1; i++)
    {
        printf("%d, ", arr[i]);
    }
    printf("%d]\n", arr[n - 1]);
    printf("That was the array :)\n\n");
}

void draw_histogram(int *freq)
{
    printf("Printing histogram...\n");
    for (int i = 0; i < MAXNUMBER; i++)
    {
        if (freq[i] != 0)
        {
            printf("%d\t", i);

            for (int j = 0; j < freq[i]; j++)
            {
                printf("X");
            }

            printf("\n");
        }
    }
    printf("End of the histogram :)\n\n");
}