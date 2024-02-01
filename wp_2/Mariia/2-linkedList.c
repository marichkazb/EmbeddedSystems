// include libraries
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// #### Constants #####
#define MAX 5

// ##### typedefs ####
typedef struct q
{
    int number;
    struct q *next;
    struct q *prev;
} REGTYPE;

// ##### Function declarations #####
REGTYPE *random_list(void);
REGTYPE *add_first(REGTYPE *temp, int data);
void printList(REGTYPE *act_post);

// ###### Main program #######
int main(int argc, char *argv[])
{
    int nr = 0;
    REGTYPE *act_post, *head = NULL;
    srand(time(0)); // Random seed

    printf("\nPrint list before insertion: \n");
    head = random_list();
    act_post = head;

    printList(act_post);
    printf("\nPrint list after insertion: \n");

    act_post = add_first(head, 123);
    printList(act_post);

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
    // create pointers to top and old
    // let's assume that top pointer will be dedicated to have the value of the head of the list
    REGTYPE *top = NULL, *old = NULL;
    // allocate memory for top, so that we don't face segmentation error
    top = (REGTYPE *)malloc(sizeof(REGTYPE));

    top->number = rand() % 100;
    top->prev = NULL;
    top->next = NULL;
    // assign node of top to be the old. Because in order for the following node to access it's previous node, it needs to know it
    old = top;

    for (int i = 0; i < MAX; i++)
    {
        // Important!! Have to keep item as a local pointer, since it's value is continuously reset
        // and values from different iterations shouldn't mix up
        REGTYPE *item;
        item = (REGTYPE *)malloc(sizeof(REGTYPE));
        item->next = NULL;
        item->prev = NULL;

        int value = (rand() % 100);
        item->number = value;

        old->next = item;
        item->prev = old;
        // node of current item is created, so time to assign it as old node for the next iteration
        old = item;
    }
    return top;
}

//==========================================================
REGTYPE *add_first(REGTYPE *temp, int data)
{

    REGTYPE *newHead = (REGTYPE *)malloc(sizeof(REGTYPE));

    newHead->number = data;
    newHead->prev = NULL;
    newHead->next = temp;
    temp->prev = newHead;
    return newHead;
}

void printList(REGTYPE *act_post)
{
    int nr = 0;
    while (act_post != NULL)
    {
        printf("\n Post nr %d : %d", nr++, act_post->number);
        act_post = act_post->next;
    }
    printf("\n\n");
}