// (C) __Mariia Zabolotnia, Joel Celén, Ionel Pop, group: 8__ (2024)
// Work package 2
// Exercise 1
// Submission code: 355721 (provided by your TA-s)

// include libraries
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// #### Constants #####
#define MAX 5

// ##### typedefs ####
// define structure REGTYPE that will hold information of the current node - value, link to previous and next node
typedef struct q
{
    int number;     // attribute to store the value of the current node
    struct q *next; // attribute to store the pointer to the next node
    struct q *prev; // attribute to store thr pointer to the previous node
} REGTYPE;          // assign structure the name REGTYPE for convenient reuse

// ##### Function declarations #####
REGTYPE *random_list(void);                  // declare helper function that creates a double linked list of nodes with random values
REGTYPE *add_first(REGTYPE *temp, int data); // declare helper function that inserts a node as a head of the linked list
void printList(REGTYPE *act_post);           // declare helper function aimed to assist in printing the linked list for debugging

/**
 *
 * Purpose: Learning C programming
 * DIT633
 *
 * Author: Mariia Zabolotnia, Joel Celén, Ionel Pop 2024
 *
 **/

// ###### Main program #######
int main(int argc, char *argv[])
{
    // declare pointer to actual position and head of type REGTYPE
    REGTYPE *act_post, *head = NULL;
    srand(time(0)); // Random seed to generate random numbers

    // print title for convenient debugging
    printf("\nPrint list before insertion: \n");
    // assign pointer of head to point at the first element of the randomly generated double linked list
    head = random_list();
    // assign actual position to the first element of the linked list
    act_post = head;

    // print the list for convenient debugging
    printList(act_post);

    // print title to denote the list after insertion of the first node
    printf("\nPrint list after insertion: \n");

    // insert a new element 123 as the head of the linked list stored in head and assign pointer to the first element of the new list to act_pos
    act_post = add_first(head, 123);
    // output the result of insertion
    printList(act_post);

    // --- Free the allocated memory ---
    // iterate over all elements until the end of the list
    while ((act_post = head) != NULL)
    {
        // move head to point to the next node after the current one
        head = act_post->next;
        // free the allocated memory of the current node
        free(act_post);
    }
    // terminate the program
    return 0;
}
// ==== End of main ======================================

// helper function to generate a linked list of the nodes with random values
REGTYPE *random_list(void)
{
    // create pointers to top and old
    // let's assume that top pointer will be dedicated to have the value of the head of the list
    REGTYPE *top = NULL, *old = NULL;
    // allocate memory for top, so that we don't face segmentation error
    top = (REGTYPE *)malloc(sizeof(REGTYPE));

    // assign the value of the top node to random in range 0-99
    top->number = rand() % 100;
    // initialize the link to prev as null
    top->prev = NULL;
    // initialize the link to next as null
    top->next = NULL;
    // assign node of top to be the old. Because in order for the following node to access it's previous node, it needs to know a link to top
    old = top;

    // in the loop create a linked list of MAX amount of items
    for (int i = 0; i < MAX; i++)
    {
        // Important! Have to keep item as a local pointer, since it's value is continuously reset
        // and values from different iterations shouldn't mix up
        REGTYPE *item; // declare pointer to the current item
        // allocate memory for the current item
        item = (REGTYPE *)malloc(sizeof(REGTYPE));
        // initialize a link to next of the item to null
        item->next = NULL;
        // initialize a link to prev of the item to null
        item->prev = NULL;

        // store a random number in range 0-99 in a variable value
        int value = (rand() % 100);
        // assign the value of the current item as a random
        item->number = value;

        // assign link of the previous node to its next node to the current item
        old->next = item;
        // and item's previous node is consecutively old node
        item->prev = old;
        // node of current item is created, so time to assign it as old node for the next iteration
        old = item;
    }
    // return the head node of the linked list. it can be used to iterate on the elements of the whole linked list
    return top;
}

//==========================================================
// helper function to insert an element with value @param data as a head node of the linked list @param *temp
REGTYPE *add_first(REGTYPE *temp, int data)
{
    // allocate memory in the heap for the new Head of size of it's type structure
    REGTYPE *newHead = (REGTYPE *)malloc(sizeof(REGTYPE));

    // assign the value of the current node to @param data
    newHead->number = data;
    // assign link to previous node to null, since it's the very first node of the linked list
    newHead->prev = NULL;
    // assign link to the next node of the new element to the previous head of the linked list
    newHead->next = temp;
    // assign link of the previous head of the linked list to the prev to the new node
    temp->prev = newHead;
    // return the new head of the list as a pointer from which the whole linked list can be accessed
    return newHead;
}

// helper function for convenient printing of the linked list, takes a pointer to the first element as an argument
void printList(REGTYPE *act_post)
{
    // initialize counter
    int nr = 0;
    // iterate over all items until the end of the linked list
    while (act_post != NULL)
    {
        // print post nr : and the value of the node
        printf("\n Post nr %d : %d", nr++, act_post->number);
        // move on to the next node linked to the current
        act_post = act_post->next;
    }
    // print new line for better visualization
    printf("\n\n");
}
