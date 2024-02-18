// Include section
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct q
{
    int number;
    struct q *next;
    struct q *prev;
} NODE;

NODE *generateList(int num);

// main function declaration
int main(int argc, char *argv[])
{
    // error validation
    if (argc != 2)
    {
        printf("invalid: input one number\n");
        exit(0);
    }
    int userInput = atoi(argv[1]);
    if (userInput < 0)
    {
        printf("invalid: number should be positive. output: 0 \n");
        exit(0);
    }
    else if (userInput > 60)
    {
        printf("invalid: input smaller number\n");
        exit(0);
    }

    NODE *list = generateList(userInput);

    int num;
    while (list != NULL)
    {
        if (list->next == NULL)
        {
            num = list->number;
            break;
        }
        list = list->next;
    }

    printf("Output: number is: %d\n", num);
    while (list != NULL)
    {
        list = list->next;
        free(list);
    }

    return 0;
}

NODE *generateList(int num)
{
    NODE *start = NULL, *old = NULL, *second = NULL;
    start = (NODE *)malloc(sizeof(NODE));
    second = (NODE *)malloc(sizeof(NODE));

    // create start node that is equal to 0;
    start->number = 0;
    start->next = second;
    start->prev = NULL;

    // create second node that is equal to 1;
    if (num > 1)
    {
        second->prev = start;
        second->number = 1;
        second->next = NULL;

        old = second;

        int i = 2; // because we already added elements 0 and 1
        while (i < num)
        {
            NODE *item;
            item = (NODE *)malloc(sizeof(NODE));
            item->prev = old;
            int prevNum = old->number;
            int oldNum = old->prev->number;
            item->number = prevNum + oldNum;
            item->next = NULL;

            old->next = item;
            old = item;
            i++;
        }
    }
    return start;
}
