// #include <stdio.h>
// #define MAX_SIZE 5 // Maximum size of the array
// int main()
// {
//     int arr[MAX_SIZE]; // Declares an array size
//     int i, num;
//     // Enter size of array
//     printf("Enter size of the array: ");
//     scanf("%d", &num);
//     // Reading elements of array
//     printf("Enter elements in array: ");
//     for (i = 0; i < num; i++)
//     {
//         scanf("%d", &arr[i]);
//     }
//     printf("\nAll negative elements in array are: \n");
//     for (i = 0; i < num; ++i)
//     {
//         // Printing negative elements
//         if (arr[i] < 0)
//         {
//             printf("%d\t", arr[i]);
//         }
//     }
//     return 0;
// }

// #include <stdio.h> //Used to include basic c library files
// int main()         // Used to execute the C application
// {
//     // declaring and defining the array variables
//     int a[5] = {100, 101, 102, 103, 104};
//     int b[5] = {105, 106, 107, 108, 109};
//     // displaying the output
//     printf("%d\n", a[0]);
//     // and another element
//     printf("%d\n", b[1]);
//     return 0;
// }

// #include <stdio.h> //Used to include basic c library files
// int sum(int a, int b);

// int main() // main() method for executing the application
// {
//     // declaring and defining the variables
//     int a = 100;
//     int b = 200;
//     // displaying the output
//     printf("Sum of %d and %d is=%d\n", a, b, sum(a, b)); // sum(a,b) is calling method
//     return 0;
// }
// // called method
// int sum(int a, int b)
// {
//     return a + b; // making the calculation
// }

// #include <stdio.h>
// #include <string.h>
// #include <stdlib.h>
// #include <stdbool.h>
// // structure describing one node of the list
// struct node
// {
//     int data;
//     int key;
//     struct node *next;
// };

// int length();
// void insertFirst(int key, int data);
// struct node *deleteFirst();
// void deleteList();
// void printList();

// // pointing to the beginning of the list and the current node
// struct node *head = NULL;
// struct node *current = NULL;

// int length()
// {
//     int counter = 0;
//     struct node *temp = head;
//     while (temp->next != NULL)
//     {
//         temp = temp->next;
//         counter++;
//     }
//     return counter;
// }
// // insert link at the first location
// void insertFirst(int key, int data)
// {
//     // create a link
//     struct node *link = (struct node *)malloc(sizeof(struct node));
//     link->key = key;
//     link->data = data;
//     if (length() == 0)
//     {
//         head = link;
//         head->next = head;
//     }
//     else
//     {
//         // point it to old first node
//         link->next = head;
//         // point first to new first node
//         head = link;
//     }
// }
// // delete first item
// struct node *deleteFirst()
// {
//     // save reference to first link
//     struct node *tempLink = head;
//     if (head->next == head)
//     {
//         head = NULL;
//         return tempLink;
//     }
//     // mark next to first link as first
//     head = head->next;
//     // return the deleted link
//     return tempLink;
// }

// void deleteList()
// {
//     while (head->next != NULL)
//     {
//         head = head->next;
//         head = NULL;
//     }
// }

// // display the list
// void printList()
// {
//     struct node *ptr = head;
//     printf("\n[ ");
//     // start from the beginning
//     if (head != NULL)
//     {
//         while (ptr->next != ptr)
//         {
//             printf("(%d,%d) ", ptr->key, ptr->data);
//             ptr = ptr->next;
//         }
//     }
//     printf(" ]");
// }
// int main()
// {
//     insertFirst(1, 10);
//     insertFirst(2, 20);
//     insertFirst(3, 30);
//     insertFirst(4, 1);
//     insertFirst(5, 40);
//     insertFirst(6, 56);
//     printf("Original List: ");
//     // print list
//     printList();
//     // TODO: write the code to delete the entire list
//     // deleteList();
//     printf("\nList after deleting all items: ");
//     printList();
//     return 0;
// }
