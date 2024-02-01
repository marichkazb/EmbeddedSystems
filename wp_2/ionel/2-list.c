#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//#### Constants #####
#define MAX 5

// ##### typedefs ####
typedef struct q
{
    int number;
    struct q *next;
    struct q *prev;
} REGTYPE;

// ##### Function declarations #####
REGTYPE* random_list(void);
REGTYPE* add_first(REGTYPE* temp, int data);

//###### Main program #######
int main(int argc, char **argv)
{
    int nr=0;

    REGTYPE *act_post, *head=NULL;

    srand(time(0)); // Random seed
    head = random_list();
    act_post = head;

    // while (act_post != NULL)
    // {
    //     printf("\n Post nr %d : %d" , nr++, act_post->number);
    //     act_post=act_post->next;
    // }

    printf("List before the insertion\n");

    while (act_post != NULL)
    {
        printf("\n Post nr %d : %d\n" , nr++, act_post->number);
        if (act_post->prev != NULL)
        {
            printf("\tPrev: %d\n", act_post->prev->number);
        }
        if (act_post->next != NULL)
        {
            printf("\tNext: %d\n", act_post->next->number);
        }
        act_post=act_post->next;
    }
    printf("\n");

    nr = 0;
    head = add_first(head, 420);
    act_post = head;

    printf("List after the insertion\n");

    while (act_post != NULL)
    {
        printf("\n Post nr %d : %d\n" , nr++, act_post->number);
        if (act_post->prev != NULL)
        {
            printf("\tPrev: %d\n", act_post->prev->number);
        }
        if (act_post->next != NULL)
        {
            printf("\tNext: %d\n", act_post->next->number);
        }
        act_post=act_post->next;
    }
    printf("\n");

    // --- Free the allocated memory ---
    while ((act_post=head) != NULL)
    {
        head = act_post->next;
        free(act_post);
    }

    return 0;
}

// ==== End of main ======================================

REGTYPE* random_list(void)
{
    int nr, i = 1;
    REGTYPE *top, *old, *item;

    top = (REGTYPE*)malloc(sizeof(struct q));
    top->number = rand() % 100;
    // top->number = i;
    top->next = NULL;
    top->prev = NULL;

    while (i <= 5)
    {
        REGTYPE* currentReg;
        currentReg = (REGTYPE*)malloc(sizeof(struct q));
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

REGTYPE* add_first(REGTYPE* temp, int data)
{
    REGTYPE* newFirst = (REGTYPE*)malloc(sizeof(struct q));
    newFirst->number = data;
    newFirst->next = temp;
    newFirst->prev = NULL;
    temp->prev = newFirst;

    return newFirst;
}