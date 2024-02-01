#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILENAME "test.bin"

// TODO: Ask if I can change the signatures
// TODO: Ask about the dummy data (Should I print it? Remove it?)
// TODO: ask what's the point of input_record(void)

// -----typedefs -------
typedef struct
{
    char firstname[20];
    char famname[20];
    char pers_number[13]; // yyyymmddnnnc
} PERSON;

// Function declaration (to be extend)
void write_new_file(PERSON *inrecord); // Creates a file and writes the first record
void append_file(PERSON *inrecord);    // appends a new person to the file
void search_by_firstname(char *fname); // Prints out the person if in list
void search_by_lastname(char *lname);  // Prints out the person if in list
void printfile(void);                  // Prints out all persons in the file
PERSON input_record(void);             // Reads a person’s record. TODO: ask what's the point of this

int isValidInput(int input)
{
    return (input >= 1 && input <= 5);
}

int main(void)
{
    PERSON ppost;
    char userInput[3] = "1";

    int option = atoi(userInput);

    while (option != 5)
    {
        printf("Choose an option!\n");
        printf("\t1. Create a new and delete the old file.\n");
        printf("\t2. Add a new person to the file.\n");
        printf("\t3. Search for a person in the file.\n");
        printf("\t4. Print out all in the file.\n");
        printf("\t5. Exit the program.\n");

        scanf("%2s", userInput);
        char c;
        while ((c = getchar()) != '\n')
            ;

        option = atoi(userInput);

        if (option < 1 || option > 5)
        {
            printf("Oops! That is not an option :(. Try again\n");
            continue;
        }

        printf("You chose option %d :)\n", option);

        switch (option)
        {
        case 1:
            PERSON dummyData = {"Kamen", "Rider", "190001010000"};
            write_new_file(&dummyData);
            break;
        case 2:
            char firstname[20];
            char famname[20];
            char pers_number[13];
            char c;

            printf("Please input the first name of the person: ");
            scanf("%20s", firstname);

            while ((c = getchar()) != '\n')
                ;

            printf("Please input the last name of the person: ");
            scanf("%20s", famname);

            while ((c = getchar()) != '\n')
                ;

            printf("Please input the ssn of the person: ");
            scanf("%13s", pers_number);

            PERSON newPerson;
            strcpy(newPerson.firstname, firstname);
            strcpy(newPerson.famname, famname);
            strcpy(newPerson.pers_number, pers_number);

            while ((c = getchar()) != '\n')
                ;

            append_file(&newPerson);
            break;
        case 3:
            printf("Would you like to search by firstname or lastname? (f-firstname l-lastname)\n");
            char searchOption[10];

            scanf("%10s", searchOption);

            while ((c = getchar()) != '\n')
                ;

            char name[20];
            printf("Please input the name you'd like to search for: ");
            scanf("%20s", name);

            while ((c = getchar()) != '\n')
                ;

            int firstNameSearch = 0;
            int lastNameSearch = 0;
            if (strcmp(searchOption, "f") == 0)
            {
                search_by_firstname(name);
            }
            else if (strcmp(searchOption, "l") == 0)
            {
                search_by_lastname(name);
            }
            else
            {
                printf("Invalid option\n");
                break;
            }
            break;
        case 4:
            printfile();
            break;
        case 5:
            break;
        default:
            break;
        }
    }

    return 0;
}

void write_new_file(PERSON *inrecord)
{
    printf("Create new file with dummy data\n");

    FILE *fd = fopen(FILENAME, "wb");
    if (fd == NULL)
    {
        printf("Error creating the file :(\n");
        return;
    }

    if (fwrite(inrecord, sizeof(PERSON), 1, fd) != 1)
    {
        printf("Error writing data to the file :(\n");
        return;
    }

    fclose(fd);
}

void append_file(PERSON *inrecord)
{
    printf("Append new information\n");

    FILE *fd = fopen(FILENAME, "rb+");
    if (fd == NULL)
    {
        printf("Error looking for the file :(\n");
        return;
    }

    if (fseek(fd, 0, SEEK_END) < 0)
    {
        printf("Error reading the file :(\n");
    }

    if (fwrite(inrecord, sizeof(PERSON), 1, fd) != 1)
    {
        // TODO: check what happens when sizeof and 1 are different
        printf("Error writing data to the file :(\n");
        return;
    }

    fclose(fd);
}

void search_by_firstname(char *fname)
{
    printf("Looking for first name matches\n");

    int counter = 0;

    FILE *fd = fopen(FILENAME, "rb");
    if (fd == NULL)
    {
        printf("Error looking for the file :(\n");
        return;
    }

    if (fseek(fd, 0, SEEK_END) < 0)
    {
        printf("Error reading the file\n");
    }

    size_t data_size = ftell(fd);

    if (data_size <= 53)
    {
        printf("List is empty\n");
        return;
    }
    rewind(fd);

    PERSON currentPerson;

    while (fread(&currentPerson, sizeof(PERSON), 1, fd) == 1)
    {
        if (strcmp(currentPerson.firstname, fname) == 0)
        {
            printf("PERSON: \n");
            printf("\tFirst Name:\t%s\n", currentPerson.firstname);
            printf("\tLast Name:\t%s\n", currentPerson.famname);
            printf("\tSSN:\t%s\n", currentPerson.pers_number);

            counter++;
        }
    }

    if (counter == 0)
    {
        printf("No matches found\n");
    }

    fclose(fd);
}

void search_by_lastname(char *lname)
{
    printf("Looking for last name matches\n");

    int counter = 0;

    FILE *fd = fopen(FILENAME, "rb");
    if (fd == NULL)
    {
        printf("Error looking for the file :(\n");
        return;
    }

    if (fseek(fd, 0, SEEK_END) < 0)
    {
        printf("Error reading the file\n");
    }

    size_t data_size = ftell(fd);

    if (data_size <= 53)
    {
        printf("List is empty\n");
        return;
    }
    rewind(fd);

    PERSON currentPerson;

    while (fread(&currentPerson, sizeof(PERSON), 1, fd) == 1)
    {
        if (strcmp(currentPerson.famname, lname) == 0)
        {
            printf("PERSON: \n");
            printf("\tFirst Name:\t%s\n", currentPerson.firstname);
            printf("\tLast Name:\t%s\n", currentPerson.famname);
            printf("\tSSN:\t%s\n", currentPerson.pers_number);

            counter++;
        }
    }

    if (counter == 0)
    {
        printf("No matches found\n");
    }

    fclose(fd);
}

void printfile()
{
    FILE *fd = fopen(FILENAME, "rb");
    if (fd == NULL)
    {
        printf("Error looking for the file :(\n");
        return;
    }

    if (fseek(fd, 0, SEEK_END) < 0)
    {
        printf("Error reading the file\n");
    }

    size_t data_size = ftell(fd);

    if (data_size <= 53)
    {
        printf("List is empty\n");
        return;
    }
    else
    {
        printf("There are %lu entries in the list\n", (unsigned long)data_size / 53);
    }

    rewind(fd);

    PERSON currentPerson;

    while (fread(&currentPerson, sizeof(PERSON), 1, fd) == 1)
    {
        printf("PERSON: \n");
        printf("\tFirst Name:\t%s\n", currentPerson.firstname);
        printf("\tLast Name:\t%s\n", currentPerson.famname);
        printf("\tSSN:\t%s\n", currentPerson.pers_number);
    }
}

// PERSON input_record()
// {
//     PERSON *
// }

// void search_by_name(char *fname, char *lname, int firstNameSearch, int lastNameSearch)
// {
//     printf("Looking for first name matches\n");

//     FILE *fd = fopen(FILENAME, "rb");
//     if (fd == NULL)
//     {
//         printf("Error looking for the file :(\n");
//         return;
//     }

//     PERSON currentPerson;

//     while (fread(&currentPerson, sizeof(PERSON), 1, fd) == 1)
//     {
//         if ((strcmp(currentPerson.firstname, fname) == 0 && firstNameSearch == 1 && lastNameSearch == 0) ||
//         (strcmp(currentPerson.famname, lname) == 0 && firstNameSearch == 0 && lastNameSearch == 1) ||
//         (strcmp(currentPerson.famname, lname) == 0 && strcmp(currentPerson.firstname, fname) == 0 && firstNameSearch == 1 && lastNameSearch == 1))
//         {
//             printf("PERSON: \n");
//             printf("\tFirst Name:\t%s\n", currentPerson.firstname);
//             printf("\tLast Name:\t%s\n", currentPerson.famname);
//             printf("\tSSN:\t%s\n", currentPerson.pers_number);
//         }
//     }

//     fclose(fd);
// }