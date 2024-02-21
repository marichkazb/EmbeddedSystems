#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_OF_ARGS 2

typedef struct node
{
    unsigned long value;
    struct node *prev;
    struct node *next;
} NODE;

void freeList(NODE *head)
{
    while (head->next != NULL)
    {
        NODE *remove = head;
        head = head->next;
        free(remove);
    }
    free(head);
}

int main(int argc, char **argv)
{
    if (argc != NUM_OF_ARGS)
    {
        printf("Error. Invalid number of command line arguments passed\n");
        return 0;
    }

    // Create the first element fib(0)
    NODE *head = (NODE *)malloc(sizeof(NODE));
    memset(head, 0, sizeof(NODE));
    head->prev = NULL;
    head->next = NULL;
    head->value = 1;

    NODE *current = head->next;
    NODE *prev = head;

    int inputNumber = atoi(argv[1]);

    if (inputNumber < 0)
    {
        printf("0\n");
        return 0;
    }

    int counter = 1;
    // I have to fix this to pass the tests, but the tests are wrong
    while (counter < inputNumber - 1)
    {
        current = (NODE *)malloc(sizeof(NODE));
        memset(current, 0, sizeof(NODE));
        if (prev != NULL && prev->prev != NULL)
        {
            // fib(n) = fib(n - 1) + fib(n - 2)
            current->value = prev->value + prev->prev->value;
        }
        else
        {
            // fib(0) = 1, fib(1) = 1
            current->value = 1;
        }
        prev->next = current;
        current->prev = prev;
        prev = current;
        current = current->next;
        counter++;
    }

    unsigned long fibonacciNumber = prev->value;

    printf("Fibonacci of %d: %lu\n", inputNumber, fibonacciNumber);

    freeList(head);

    return 0;
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