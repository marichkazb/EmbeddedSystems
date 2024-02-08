// (C) __Mariia Zabolotnia, Joel Celén, Ionel Pop, group: 8__ (2024)
// Work package 2
// Exercise 1
// Submission code: 355721 (provided by your TA-s)

// Include section
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Define section
#define MAX 20

// Type definitions
// Person struct
typedef struct
{
    char firstname[MAX];   // Character array for first name
    char surname[MAX];     // Character array for surname
    char pers_number[MAX]; // Character array for personnummer
} PERSON;                  // Declare struct name

// Choice struct
typedef enum
{
    CREATE = 1, // Initializing the first value to 1 instead of 0
    ADD,        // =2
    SEARCH,     // =3
    PRINT,      // =4
    EXIT        // =5
} CHOICE;       // Declare struct name

// Function prototypes
void write_new_file(PERSON *inrecord); // Creates a file and writes the first record
void printfile(void);                  // Prints out all persons in the file
void search_by_firstname(char *name);  // Prints out the person if in list
void append_file(PERSON *inrecord);    // appends a new person to the file
void clearBuffer();                    // Clears the buffer of any unwanted characters

// Main function
/**
 *
 * Purpose: Work package 2: Binary files
 * DIT633
 *
 * Author: Joel Celén, Ionel Pop, Mariia Zabolotnia 2024
 *
 **/
int main(void)
{
    PERSON ppost;               // Temporary person
    PERSON *personPtr = &ppost; // Pointer to temp person
    CHOICE choice;              // Choice for menu

    while (choice != EXIT) // While exit option is not pressed
    {
        // Print statement for menu
        printf("1 Create a new and delete the old file.\n"
               "2 Add a new person to the file.\n"
               "3 Search for a person in the file.\n"
               "4 Print out all in the file.\n"
               "5 Exit the program.\n");

        // Take user input as an integer
        scanf("%d", &choice);
        // Clear buffer of any possible unwanted characters
        clearBuffer();

        if (choice == CREATE) // If user inputs 1 in the menu
        {
            // Call write new file function
            write_new_file(personPtr);
        }
        else if (choice == ADD) // If user inputs 2 in the menu
        {
            // Call append file function
            append_file(personPtr);
        }
        else if (choice == SEARCH) // If user inputs 3 in the menu
        {
            // Create temporary string to hold name input from user
            char name[MAX];
            // Prompt user to input name
            printf("Please specify what name you want to search for:\n");
            // Take input from CLI
            fgets(name, MAX, stdin);
            // Call search function
            search_by_firstname(name);
        }
        else if (choice == PRINT) // If user inputs 4 in the menu
        {
            // Call print file function
            printfile();
        }
        else if (choice == EXIT) // If user inputs 5 in the menu
        {
            // Print exit statement
            printf("Goodbye!\n");
        }
        else // If user inputs any number out of bounds in the menu
        {
            // Prompt user to input integer in the correct value range
            printf("Please enter an integer between 1 and 5.\n");
        }
    }
    // Return 0 for successful execution
    return (0);
}

// New file function
void write_new_file(PERSON *inrecord)
{
    // Open file in write/binary mode and assign a file pointer to the address
    FILE *file = fopen("example.bin", "wb");

    if (file == NULL) // If there is a problem with creating the file
    {
        // Print error message
        printf("Error reading file.\n");
        // Return out of function
        return;
    }

    // Fill memory allocated to person with zeroes
    memset(inrecord, 0, sizeof(PERSON));

    strcpy(inrecord->firstname, "Place\n");   // Set placeholder first name
    strcpy(inrecord->surname, "Holder\n");    // Set placeholder surname
    strcpy(inrecord->pers_number, "Empty\n"); // Set placeholder personnummer

    if (fwrite(inrecord, sizeof(PERSON), 1, file) == 1) // If write was unsuccessful
    {
        // Print error message
        printf("Data written to file successfully.\n");
    }
    // Close file
    fclose(file);
}

// Print function
void printfile(void)
{
    // Open file in read/binary mode and assign a file pointer to the address
    FILE *file = fopen("example.bin", "rb");

    if (file == NULL) // If file is not present
    {
        // Print error message
        printf("Error reading file.\n");
        // Return out of the function
        return;
    }

    // Create a temporary person for comparison
    PERSON temp;

    while (fread(&temp, sizeof(PERSON), 1, file)) // While there is still entries in the file
    {
        printf("First name: %s", temp.firstname);     // Prints fist name of current entry
        printf("Surname: %s", temp.surname);          // Prints surname of current entry
        printf("Personnummer: %s", temp.pers_number); // Prints personnummer of current entry
        printf("%c", '\n');                           // Prints newline for easier reading in CLI
    }
    // Close file
    fclose(file);
}

// Search function
void search_by_firstname(char *name)
{
    // Initiate counter
    int counter = 0;

    // Open file in read/binary mode and assign a file pointer to the address
    FILE *file = fopen("example.bin", "rb");

    if (file == NULL) // If file is not present
    {
        // Print error message
        printf("Error reading file.\n");
        // Return out of the function
        return;
    }

    // Create a temporary person
    PERSON temp;

    while (fread(&temp, sizeof(PERSON), 1, file)) // For every entry in the file
    {
        if (strcmp(temp.firstname, name) == 0 || strcmp(temp.surname, name) == 0) // If provided name match first OR surname
        {
            printf("%c", '\n');                           // Prints newline for easier reading in CLI
            printf("First name: %s", temp.firstname);     // Prints fist name of current entry
            printf("Surname: %s", temp.surname);          // Prints surname of current entry
            printf("Personnummer: %s", temp.pers_number); // Prints personnummer of current entry
            printf("%c", '\n');                           // Prints newline for easier reading in CLI
            counter++;                                    // Increment counter
        }
    }
    // Close file
    fclose(file);
    // Print records found
    printf("\nRecords found: %d\n\n", counter);
}

// Append function
void append_file(PERSON *inrecord)
{
    // Create a file pointer and try to open file in read/binary mode
    FILE *file = fopen("example.bin", "rb");
    
    if (file == NULL)// If file is not present
    {
        // Error message
        printf("File does not exist.\n");
        // Return out of function
        return;
    }
    // Close file
    fclose(file);

    // Open file in read/binary/plus mode and assign a file pointer to the address
    file = fopen("example.bin", "ab");

    if (file == NULL)
    {
        // Print error message
        printf("Error creating/reading file.\n");
        // Return out of the function
        return;
    }

    // Fill memory allocated to person with zeroes
    memset(inrecord, 0, sizeof(PERSON));

    printf("Please enter the details of the person.\n"); // Prompt user to input details of person to enter into file
    printf("First name:\n");                             // Prompt user to enter first name
    fgets(inrecord->firstname, MAX, stdin);              // Get first name from CLI and store it in ppost.firstname
    printf("Surname:\n");                                // Prompt user to enter surname
    fgets(inrecord->surname, MAX, stdin);                // Get surname from CLI and store it in ppost.surname
    printf("Personnummer, format(yyyymmddnnn):\n");      // Prompt user to enter personnummer
    fgets(inrecord->pers_number, MAX, stdin);            // Get personnummer from CLI and store it in ppost.pers_number

    if ((fwrite(inrecord, sizeof(PERSON), 1, file)) == 1) // If data was written successfully
    {
        // Print success message
        printf("Data written to file successfully.\n");
    }
    // Close file
    fclose(file);
}

// Clear buffer function
void clearBuffer()
{
    // Temporary integer representation of character
    int tempChar;
    // While there are more characters in the buffer, get them and discard them
    while ((tempChar = getchar() != '\n' && tempChar != EOF))
        ;
}