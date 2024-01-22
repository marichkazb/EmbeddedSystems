// Include section
#include <stdio.h>
#include <string.h>

// Main program section

/**
 * This program greets the user based on
 * the provided command line argument.
 * 
 * If the number of arguments provided is different than 2,
 * it prompts an error message to the user.
 * Similarly, if the name the user provided is less than 3
 * characters or more than 50 characters,
 * it prompts the user with the respective error.
 * 
 * Purpose: Introduction to C programming
 * DIT633 Development of Embedded and Real-time Systems
 * 
 * Author: Ionel Pop, 2024
 * 
**/
int main(int argc, char **argv)
{
    // program logic
    // If the number of arguments provided is less than 2
    if (argc < 2)
    {
        // Print an error message indicating that no command line argument was provided
        printf("No command line argument provided, please provide a name.\n");
        
        // Return 0 and exit the program
        return 0;
    }
    // Else if the number of arguments provided is more than 2
    else if (argc > 2)
    {
        // Print an error message indicating that more than 2 command line argument were provided
        printf("More than 2 command line arguments provided, please provide only a name.\n");

        // Return 0 and exit the program
        return 0;
    }

    // If the name provided in argv[1] is less than 3 characters
    if (strlen(argv[1]) < 3)
    {
        // Print an error message indicating that the name is too short
        printf("Name too short, min 3 characters\n");

        // Return 0 and exit the program
        return 0;
    }
    // Else if name provided in argv[1] is more than 50 characters
    else if (strlen(argv[1]) > 50)
    {
        // Print an error message indicating that the name is too long
        printf("Name too long, max 50 characters\n");

        // Return 0 and exit the program
        return 0;
    }

    // Prints the greeting to the user
    printf("Hello %s, how is your day today?\n", argv[1]);

    // Return 0 and exit the program
    return 0;
}