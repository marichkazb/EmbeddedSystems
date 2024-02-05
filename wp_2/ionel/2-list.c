// (C) __Mariia Zabolotnia, Joel Celén, Ionel Pop, group: 8__ (2024)
// Work package 2
// Exercise 1
// Submission code: XXXXXX (provided by your TA-s)

// Includes section
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// #### Constants #####
#define MAX 5 // Maximum number of nodes in the linked list

// ##### typedefs ####
/**
 * Struct named REGTYPE that defines a node of the linked list.
 *  number  -> value of the node
 *  next    -> pointer to the next node
 *  prev    -> pointer to the previous node
*/
typedef struct q
{
    int number;
    struct q *next;
    struct q *prev;
} REGTYPE;

// ##### Function declarations #####
/**
 * Initializes a double-linked list with MAX nodes and random values
 * Input:
 *  Nothing
 * 
 * Output:
 *  Returns a pointer of type REGTYPE to the head of the list
*/
REGTYPE *random_list(void);

/**
 * Adds a new node to the start of a double-linked list
 * 
 * Input:
 *  temp: A pointer to the head of the double-linked list
 *  data: The value of the new node to be inserted
 * 
 * Output:
 *  Returns a pointer to the head of the updated list; that is,
 *  the new inserted node.
*/
REGTYPE *add_first(REGTYPE *temp, int data);

// ###### Main program #######
/**
 *
 * Purpose: Work package 2: Linked List
 * DIT633
 *
 * Author: Joel Celén, Ionel Pop, Mariia Zabolotnia 2024
 *
 **/
int main()
{
    int nr = 0;

    REGTYPE *act_post, *head = NULL;

    srand(time(0)); // Random seed
    head = random_list();
    act_post = head;

    while (act_post != NULL)
    {
        printf("Post nr %d : %d\n", nr++, act_post->number);
        act_post = act_post->next;
    }

    act_post = head;
    nr = 0;
    printf("\nList before the insertion\n");

    while (act_post != NULL)
    {
        printf("\n Post nr %d : %d\n", nr++, act_post->number);
        if (act_post->prev != NULL)
        {
            printf("\tPrev: %d\n", act_post->prev->number);
        }
        if (act_post->next != NULL)
        {
            printf("\tNext: %d\n", act_post->next->number);
        }
        act_post = act_post->next;
    }
    printf("\n");

    nr = 0;
    head = add_first(head, 420);
    act_post = head;

    printf("List after the insertion\n");

    while (act_post != NULL)
    {
        printf("\n Post nr %d : %d\n", nr++, act_post->number);
        if (act_post->prev != NULL)
        {
            printf("\tPrev: %d\n", act_post->prev->number);
        }
        if (act_post->next != NULL)
        {
            printf("\tNext: %d\n", act_post->next->number);
        }
        act_post = act_post->next;
    }
    printf("\n");

    // --- Free the allocated memory ---
    while ((act_post = head) != NULL)
    {
        head = act_post->next;
        free(act_post);
    }

    return 0;
}

// ==== End of main ======================================

REGTYPE *random_list(void)
{
    int nr, i = 1;
    REGTYPE *top, *old, *item;

    top = (REGTYPE *)malloc(sizeof(struct q));
    top->number = rand() % 100;
    // top->number = i;
    top->next = NULL;
    top->prev = NULL;

    while (i <= 5)
    {
        REGTYPE *currentReg;
        currentReg = (REGTYPE *)malloc(sizeof(struct q));
        currentReg->number = rand() % 100;
        // currentReg->number = i + 1;
        currentReg->next = NULL;
        currentReg->prev = NULL;

        old = top;

        while (old->next != NULL)
        {
            old = old->next;
        }

        old->next = currentReg;
        currentReg->prev = old;

        i++;
    }

    return top;
}

//=========================================================

REGTYPE *add_first(REGTYPE *temp, int data)
{
    printf("Inserting a new node with value: %d\n", data);
    REGTYPE *newFirst = (REGTYPE *)malloc(sizeof(struct q));
    newFirst->number = data;
    newFirst->next = temp;
    newFirst->prev = NULL;
    temp->prev = newFirst;

    return newFirst;
}