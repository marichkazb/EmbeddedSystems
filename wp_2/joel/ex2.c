// Includes section
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define section
#define MAX 5

// Type definitions
typedef struct NODE
{
    int number;            // Variable to store the random value
    struct NODE *nextNode; // Pointer to the next node in the list
    struct NODE *prevNode; // Pointer to the previous node in the list
} NODE;                    // Declare type name

// Function prototypes
NODE *random_list(void);               // Generates linked list of size MAX with random values
NODE *add_first(NODE *temp, int data); // Adds a node to the head of the list

// Main function
int main(int argc, char *argv[])
{
    // Declare and assign a counter value
    int nr = 1;
    // Declare NODE pointers and set value to NULL
    NODE *currentNode = NULL, *head = NULL;
    // Create a seed based on current time
    srand(time(0));
    // Call rand_list which generates a random linked list and store the head address in the pointer head
    head = random_list();
    // Current node becomes whatever node the head pointer is pointing to
    currentNode = head;
    // Loop to iterate over the list and print the values of the nodes
    while (currentNode != NULL) // While there is nodes left in the list
    {
        // Print the position and the value of the current node
        printf("Node nr %d : %d\n", nr++, currentNode->number);
        // Current node becomes the next node in the list
        currentNode = currentNode->nextNode;
    }

    // Add new node and set the head to point at that
    head = add_first(head, 1);
    // Current node set to head
    currentNode = head;
    // Reset counter
    nr = 1;

    // If creating of new node fails
    if(head == NULL){
        // Print error message
        printf("Failed to add new node.\n");
        // Return 1 for failed execution
        return 1;
    }

    // Print success message
    printf("\nNew node added\n\n");

    // Loop to iterate over the list and print the values of the nodes
    while (currentNode != NULL) // While there is nodes left in the list
    {
        // Print the position and the value of the current node
        printf("Node nr %d : %d\n", nr++, currentNode->number);
        // Current node becomes the next node in the list
        currentNode = currentNode->nextNode;
    }

    // loop to free the allocated memory
    while ((currentNode = head) != NULL) // While there are still nodes in the list
    {
        // Head becomes the next node
        head = currentNode->nextNode;
        // Free the memory allocated to the currentNode
        free(currentNode);
    }
    // Return 0 for successful execution
    return 0;
}

// Function to create MAX amounts of nodes and link them together
NODE *random_list(void)
{
    // Create a pointer that points to null since there are no nodes in the list yet
    NODE *head = NULL;

    // For loop to create MAX amount of nodes and link them
    for (int i = 0; i < MAX; i++)
    {
        // Declare and assign a random integer between 0 and 99
        int randNum = rand() % 100;
        // Call the add_first function with the current head and random number, update head pointer to the returned pointer
        head = add_first(head, randNum);
    }
    // Return the pointer to the current head of the list
    return head;
}

// Function to create a new node and return the address as a pointer
NODE *add_first(NODE *currentHead, int data)
{
    // Allocate the size of NODE in memory and stor the address in a pointer
    NODE *newNode = (NODE *)malloc(sizeof(NODE));

    if (newNode == NULL) // If memory allocation fails
    {
        // Print error message
        printf("Memory allocation failed\n");
        // Exit out of program
        exit(1);
    }

    newNode->number = data;          // Set number to the data that was fed into the function
    newNode->nextNode = currentHead; // Set nextNode pointer to address of current head
    newNode->prevNode = NULL;        // Set the pointer to nextNode to NULL

    if (currentHead != NULL) // If there is a previous node in the list
    {
        // make the current heads prevNode pointer point to the address of the newly created node
        currentHead->prevNode = newNode;
    }

    // Return the address to the new head
    return newNode;
}