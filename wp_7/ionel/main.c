// Include section
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define sections
#define NUM_OF_ARGS 2 // Number of necessary command line arguments for the program to run

/**
 * Use a struct as a node of a single-Linked-List
 * The node contains the following data:
 *  value: the value of the node
 *  prev: a pointer to the previous node
 *  next: a pointer to the next node
 * It is defined as NODE
 */
typedef struct node
{
    unsigned long value; // The value of the node
    struct node *prev;   // A pointer to the previous node
    struct node *next;   // A pointer to the next node
} NODE;

// Prototype function declaration
void freeList(NODE *head);

int main(int argc, char **argv)
{
    // If the number of command line arguments is less than NUM_OF_ARGS
    if (argc != NUM_OF_ARGS)
    {
        // Print an appropiate error message
        printf("Error. Invalid number of command line arguments passed\n");
        // Return 0 and finish the program execution
        return 0;
    }

    // Create the first element fib(0)
    NODE *head = (NODE *)malloc(sizeof(NODE)); // allocate memory for NODE * head; the first element in the Fibonacci list
    // Initialize the allocated memory to 0
    memset(head, 0, sizeof(NODE));
    // Set the prev pointer of the node to NULL
    head->prev = NULL;
    // Set the next pointer of the node to NULL
    head->next = NULL;
    // Set the value of the current node to 1 (fib(0))
    head->value = 1;

    NODE *current = head->next; // Declare a NODE* that will point to the second element of the linked list (Currently NULL)
    NODE *prev = head;          // Declare a NODE* that will point to the first element of the linked list (fib(0))

    // Cast the command line argument passed by the user as an integer
    int inputNumber = atoi(argv[1]); // The user input in the form of an integer

    // If inputNumber is less than 0. (For any number less or equal than 0 we just output 0)
    if (inputNumber < 0)
    {
        // Print 0
        printf("0\n");
        // Return 0 and finish the program execution
        return 0;
    }

    int counter = 1; // Counter that will keep track of how many nodes we need to add to the list

    // While the counter is less than inputNumber - 1 -> For example, input number is 5, 1 + 1 = 2 -> 2 + 1 = 3 -> 3 + 2 = 5
    while (counter < inputNumber - 1)
    {
        // Allocate memory for the current node
        current = (NODE *)malloc(sizeof(NODE));
        // Initialize the memory allocated to 0
        memset(current, 0, sizeof(NODE));

        // If we are not in one of the first two nodes
        if (prev != NULL && prev->prev != NULL)
        {
            // fib(n) = fib(n - 1) + fib(n - 2)
            // Assign the current node value to the sum of the two previous node values
            current->value = prev->value + prev->prev->value;
        }
        // Otherwise, if we are in any other node than the first 2
        else
        {
            // fib(0) = 1, fib(1) = 1
            // Assign the current value to 1
            current->value = 1;
        }
        // Assign the next pointer of the previous node to the current node
        prev->next = current;
        // Assign the previous pointer of the current node to the previous node
        current->prev = prev;
        // Assign the prev pointer to the current node
        prev = current;
        // Update the current counter to the next node
        current = current->next;
        // Add +1 to the counter to keep track of the number of nodes we need in the list
        counter++;
    }

    unsigned long fibonacciNumber = prev->value; // A long variable containing the fibonacci number for the requested value

    // Print the fibonacci number of the requested value
    printf("Fibonacci of %d: %lu\n", inputNumber, fibonacciNumber);

    // Free the memory allocated for the list
    freeList(head);

    // Return 0 and finish the program execution
    return 0;
}

void freeList(NODE *head)
{
    // Iterate over the linked list until the next pointer is null
    while (head->next != NULL)
    {
        NODE *remove = head; // Assign the current node to remove
        head = head->next;   // Assign head to the next node to continue the iteration
        free(remove);        // Free the allocated memory for the current node
    }
    free(head); // Free memory allocated for the last node left in the list
}

/**
 * fib(0) = 1
 * fib(1) = 1
 * fib(2) = fib(1) + fib(0) = 1 + 1 = 2
 * fib(3) = fib(2) + fib(1) = 2 + 1 = 3
 * fib(4) = fib(3) + fib(2) = 3 + 2 = 5
 * fib(5) = fib(4) + fib(3) = 3 + 5 = 8
 *
 * ./main 5
 * counter = 0
 * node -> 1, prev, next
 * node ->
 */