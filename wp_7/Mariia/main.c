// Include section
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// create a new type called NODE that will define the structure of elements in the linked list
typedef struct q
{
    // integer with the value of the element
    int number;
    // pointer to the next node
    struct q *next;
    // pointer to the previous node
    struct q *prev;
} NODE; // call this new structure NODE for better usability

// helper function that generates a linked list of fibonacci numbers
// and returns a pointer of type NODE to the first element of the list
NODE *generateList(int num);

// main function declaration
int main(int argc, char *argv[])
{
    // error validation
    // if amount of program arguments is not correct
    if (argc != 2)
    {
        // print user message with error
        printf("invalid: input one number\n");
        // terminate the program
        exit(0);
    }
    // get command line input and save it as an integer
    int userInput = atoi(argv[1]);
    // if the number user provided isn't positive
    if (userInput < 0)
    {
        // print user message
        printf("invalid: number should be positive. output: 0 \n");
        // exit the program
        exit(0);
    }
    // max number that can be processed should be 60, since the fibonacci sequence grows fast
    else if (userInput > 60)
    {
        // print user message
        printf("invalid: input smaller number\n");
        // terminate the program
        exit(0);
    }

    // create a pointer of type NODE and assign the first element of the generated list to it
    NODE *list = generateList(userInput);

    // declare helper variable num
    int num;
    // while there are still elements in the list
    while (list != NULL)
    {
        // if the current's element next is null, so it's the last element of the list
        if (list->next == NULL)
        {
            // save number of the node to the num variable
            num = list->number;
            // exit the loop
            break;
        }
        // in other case continue iterating further
        list = list->next;
    }

    // print the user message with the found number
    printf("Output: number is: %d\n", num);
    // free memory by iterating over all the elements in the array
    while (list != NULL)
    {
        // move to the next element
        list = list->next;
        // free the assigned value for the current element
        free(list);
    }
    // terminate the program
    return 0;
}

// function that generates a list of fibonacci sequence
// and returns a pointer of type NODE to the first element of the list
NODE *generateList(int num)
{
    // initialize pointers of type NODE to start, old and second for creating the list
    NODE *start = NULL, *old = NULL, *second = NULL;
    // allocate memory for the start pointer
    start = (NODE *)malloc(sizeof(NODE));
    // allocate memory for the second pointer
    second = (NODE *)malloc(sizeof(NODE));

    // create start node that is equal to 0;
    start->number = 0;
    // link the second node as start's next
    start->next = second;
    // set previous link to NULL
    start->prev = NULL;

    // create second node that is equal to 1;
    if (num > 1)
    {
        // create a link from second to start
        second->prev = start;
        // assign second node value 1
        second->number = 1;
        // assign second's node next to NULL
        second->next = NULL;

        // now second node becomes an old node for the third node
        old = second;

        // initialize counter that will help iterating over nodes
        int i = 2; // because we already added elements 0 and 1
        // while counter is less than desired number
        while (i < num)
        {
            // create a new node for a new item
            NODE *item;
            // allocate space for the new item
            item = (NODE *)malloc(sizeof(NODE));
            // assign item's previous node to old
            item->prev = old;
            // get the previous node number
            int prevNum = old->number;
            // get the number of the prev of the old
            int oldNum = old->prev->number;
            // assign item's number as a sum of those ancestors
            item->number = prevNum + oldNum;
            // assign item's next to NULL
            item->next = NULL;
            // old's node next is consecutively the current item
            old->next = item;
            // now item becomes an old node for future nodes
            old = item;
            // increment the counter
            i++;
        }
    }
    // return pointer to the first element of the linked list
    return start;
}
