// include libraries
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define FILE_NAME "test.bin"
// -----typedefs -------
typedef struct
{
    char firstName[20];
    char lastName[20];
    char persNum[13]; // yyyymmddnnnc
} PERSON;

void printMenu();

void write_new_file(PERSON *person);  // 1 create a new file with a test record
void append_file(PERSON *person);     // 2 append a new person to the file
void search_by_firstName(char *name); // 3 search for the person
void printAllInFile();                // 4 print all records
PERSON input_record(void);            // Helper - Read a user input
void clearBuffer(void);               // Helper - clear buffer

int userInput;
int main(void)
{
    while (userInput < 5)
    {
        printMenu();
    }
    return 0;
}

void printMenu()
{
    printf("1 Create a new and delete the old file.\n");
    printf("2 Add a new person to the file.\n");
    printf("3 Search for a person in the file.\n");
    printf("4 Print out all in the file.\n");
    printf("5 Exit the program.\n");
    scanf("%d", &userInput);
    clearBuffer();

    switch (userInput)
    {
    case 1:
    {
        PERSON *testRecord = (PERSON *)malloc(sizeof(PERSON));
        strcpy(testRecord->firstName, "Ann");
        strcpy(testRecord->lastName, "Smith");
        strcpy(testRecord->persNum, "200008191111");
        write_new_file(testRecord);
        break;
    }
    case 2:
    {
        PERSON person = input_record();
        append_file(&person);
        break;
    }
    case 3:
    {

        char name[20];
        printf("Input the name to find: \n");
        scanf("%20s", name);
        clearBuffer();
        search_by_firstName(name);
        break;
    }
    case 4:
        printAllInFile();
        break;
    case 5:
        printf("Thank you for using the system :)\n");
        break;
    default:
        printf("Your input is invalid, try again\n");
        break;
    }
}

void write_new_file(PERSON *person)
{
    FILE *fptr;
    if ((fptr = fopen(FILE_NAME, "wb")) == NULL)
    {
        printf("\n Can not create the file");
        exit(1);
    }
    fwrite(person, sizeof(PERSON), 1, fptr);
    printf("\n**********************************\n");
    printf("Created a new file and inserted a record!");
    printf("\n**********************************\n\n");
    fclose(fptr);
}

PERSON input_record()
{
    PERSON person;
    printf("Input name: \n");
    scanf("%20s", person.firstName);
    clearBuffer();
    printf("Input last name: \n");

    scanf("%20s", person.lastName);
    clearBuffer();
    printf("Input personal number: \n");

    scanf("%13s", person.persNum);
    clearBuffer();
    return person;
}

void append_file(PERSON *person)
{
    FILE *fptr;
    if ((fptr = fopen(FILE_NAME, "ab")) == NULL)
    {
        printf("\n Can not append to the file");
        exit(1);
    }
    fwrite(person, sizeof(PERSON), 1, fptr);
    printf("\n**********************************\n");
    printf("Successfully added a new record!");
    printf("\n**********************************\n\n");
    fclose(fptr);
}

void search_by_firstName(char *name)
{
    FILE *fptr;
    if ((fptr = fopen(FILE_NAME, "rb")) == NULL)
    {
        printf("\n Can not open file");
        exit(1);
    }
    printf("\n**********************************\n");
    printf("Searching for a person...");
    printf("\n**********************************\n\n");
    PERSON current;
    int recordsCounter = 0;
    while (fread(&current, sizeof(PERSON), 1, fptr) == 1)
    {
        if (strcmp(current.firstName, name) == 0 || strcmp(current.lastName, name) == 0)
        {
            printf("Found a person with name %s\n", name);
            printf("First Name: %s\n", current.firstName);
            printf("Last Name: %s\n", current.lastName);
            printf("Personal number: %s\n\n", current.persNum);
            recordsCounter++;
        }
    }
    if (recordsCounter == 0)
    {
        printf("Found no records with the specified name: %s\n", name);
    }

    printf("\n");
    fclose(fptr);
}

void printAllInFile()
{
    FILE *fptr;
    if ((fptr = fopen(FILE_NAME, "rb")) == NULL)
    {
        printf("\n Can not open file");
        exit(1);
    }
    // -------- Reads all file --------
    PERSON current;
    printf("\n**********************************\n");
    printf("Printing all records in a file");
    printf("\n**********************************\n\n");
    while (fread(&current, sizeof(PERSON), 1, fptr) == 1)
    {
        printf("First Name: %s\n", current.firstName);
        printf("Last Name: %s\n", current.lastName);
        printf("Personal number: %s\n", current.persNum);
        printf("\n");
    }

    printf("\n");
    fclose(fptr);
}

// helper function to clear buffer
void clearBuffer()
{
    // declare helper variable
    int userInput;
    // Clear input buffer to prevent infinite loop
    while ((userInput = getchar()) != '\n' && (userInput != EOF))
        ; // empty body because we intend to just iterate on input characters
}
