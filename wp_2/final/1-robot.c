// (C) __Mariia Zabolotnia, Joel Celén, Ionel Pop, group: 8__ (2024)
// Work package 2
// Exercise 1
// Submission code: XXXXXX (provided by your TA-s)

// Includes section
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define section
#define END_CHAR 'x' // End character that will stop the execution

// Constant declaration
/**
 * Array of strings that contains the names of the directions.
 * 
 * This is used to format the printing of the facing direction at the end of the program
*/
const char* CARDINAL_DIRECTIONS[10] = {"North", "East", "South", "West"};

/**
 * Enum to store the direction of the robot
 */
enum DIRECTION
{
    N, // North
    E, // East
    S, // South
    W  // West
};

/**
 * Struct named ROBOT that defines the Robot attributes
 *  x position
 *  y position
 *  dir
 */
typedef struct
{
    int xpos;           // x position of the robot
    int ypos;           // y position of the robot
    enum DIRECTION dir; // direction of the robot
} ROBOT;

// Functions prototype declaration

/**
 * Validates that the user input is in the proper format <x> <y> <movement_string>
 * 
 * Input:
 *  input:  a string representing the user input.
 *  xpos:   a pointer to the x position of the robot struct.
 *  ypos:   a pointer to the y position of the robot struct.
 *  path:   an empty string that will be used to store the actual path the robot has to take
 *
 * Output:
 *  1 if input is valid.
 *  0 if input is invalid.
 *  -1 if input is the exit character 'x' (END_CHAR).
 * 
 *  It also returns the previously empty string path, filled with the actual robot path,
 *  And the pointers xpos, and ypos with the proper initial coordinates
 */
int validateInput(char *input, int *xpos, int *ypos, char *path);

/**
 * Initializes the robot to the passed parameters
 * 
 * Input:
 *  rob: A pointer to a variable of type ROBOT
 *  xpos: the value of the robot initial x position
 *  ypos: the value of the robot initial y position
 * 
 * Output:
 *  None, but ROBOT rob will be initialized with the input parameters
*/
void initializeRobot(ROBOT *rob, int xpos, int ypos);

/**
 * Move the robot 1 space based on the facing direction
 * 
 * Input:
 *  rob: A pointer to a variable of type ROBOT
 *  
 * Output:
 *  None, but the ROBOT rob's position (xpos, ypos) will be
 *  updated according to the facing direction
*/
void move(ROBOT *rob);

/**
 * Rotate the robot 90 degrees clockwise based on the facing direction
 * 
 * Input:
 *  rob: A pointer to a variable of type ROBOT
 *  
 * Output:
 *  None, but the ROBOT rob's direction (dir) will be
 *  updated according to the facing direction
*/
void turn(ROBOT *rob);

// Main program section
/**
 *
 * Purpose: Work package 2: Robot
 * DIT633
 *
 * Author: Joel Celén, Ionel Pop, Mariia Zabolotnia 2024
 *
 **/
int main()
{
    // Variable declarations
    ROBOT rob;  // The robot that the user will move
    int xStart; // Robot's initial x position
    int yStart; // Robot's initial y position
    char inputBuffer[500]; // Buffer to capture user input
    char path[500]; // String to save the robot's path after the user input has been validated
    int isInputValid; // Boolean that represents wether the user input was parsed successfully or not

    // Program logic
    // Infinite loop
    while (1)
    {
        // Prompt instructions to the user
        printf("Enter the starting position and the movement string as it follows:\n");
        printf("\t<x> <y> <mt...tm>\n");
        printf("Enter 'x' to close the program\n");

        // Capture user input
        fgets(inputBuffer, sizeof(inputBuffer), stdin);

        // Call validateInput with the corresponding parameters and assign its return value to isInputValid
        isInputValid = validateInput(inputBuffer, &xStart, &yStart, path);

        // If the input was not valid
        if (isInputValid == 0)
        {
            // Prompt the user to try again
            printf("Please try again :)\n\n");
            // Continue to a new iteration of the loop
            continue;
        }
        // Else if the input was the exit character
        else if (isInputValid == -1)
        {
            // Prompt the user a good bye message
            printf("Thank you for using this program :)\n");
            // Break out of the infinite loop
            break;
        }

        // In any other case, the user input is valid

        // Initialize the ROBOT rob with the newly updated starting position
        initializeRobot(&rob, xStart, yStart);

        // Create a pointer that points to the first character of path to iterate over it
        char *pPath = path;

        // Iterate through path until pPath points to the null terminator character
        while (*pPath != '\0')
        {
            // If the current character that pPath points to is 'm'
            if (*pPath == 'm')
            {
                // Move the robot according to the specified function
                move(&rob);
            }
            // Else isf the current character that pPath points to is 't'
            else if (*pPath == 't')
            {
                // Rotate the robot according to the specified function
                turn(&rob);
            }
            // Else
            else
            {
                // Print an error
                printf("Unexpected error.\n");

                /**
                 * Note:
                 *  In theory, this else statement should never trigger since the user
                 *  input has already been validated. Which means that it only contains
                 *  'm's, 't's, and the null terminator character '/0'
                */
            }
            // Update the pointer to evaluate the next character
            pPath++;
        }

        // Print the final position of the robot in a nice format
        printf("\n----------\n");
        printf("The final position of the robot is: \n");
        printf("\t X: %d\n", rob.xpos);
        printf("\t Y: %d\n", rob.ypos);
        printf("\t Facing: %s\n", CARDINAL_DIRECTIONS[rob.dir]);
        printf("----------\n\n");
    }

    // Stop the execution of the program with a code '0'
    return 0;
}

int validateInput(char *input, int *xpos, int *ypos, char *path)
{
    // If the input length is equal to 2 and the input[0] = 'x' -> input = x\n
    if (strlen(input) == 2 && input[0] == END_CHAR && input[1] == '\n')
    {
        // Return -1 to stop the execution of the program
        return -1;
    }

    int spaceCounter = 0; // Counter for the number of spaces the input should have. For instance: <x> <y> <mtmt..mt> -> means only 2 spaces
    /**
     * Iterate through the input string by breaking it into spaces
     * and validates the formatting.
     * 
     * After this loop has finished, we are guaranteed that the
     * input is in the proper format, and no unwanted characters
     * are present.
     * 
    */
    for (int i = 0; i < strlen(input); i++)
    {
        // If the current character is a space
        if (input[i] == ' ')
        {
            // Increment space counter by 1
            spaceCounter++;

            // If there are more than 2 spaces
            if (spaceCounter > 2)
            {
                // Print the corresponding error message
                printf("Error. Input has more than 3 parameters.\n");
                // Return 0 to show that input is invalid
                return 0;
            }
        }
        // Else if we are currently checking the first or second parameter, and the current character is not a digit
        else if ((spaceCounter == 0 || spaceCounter == 1) && (input[i] < '0' || input[i] > '9'))
        {
            // Print the corresponding error message
            printf("Error. First and second parameters should be numbers from 0 to 99.\n");
            // Return 0 to show that input is invalid
            return 0;
        }
        // Else if we are currently checking the third parameter, and the current character is not 'm', 't', or '\n'
        else if (spaceCounter == 2 && input[i] != 'm' && input[i] != 't' && input[i] != '\n')
        {
            // Print the corresponding error message
            printf("Error. Third parameters should consist of a sequence of 'm's and 't's. (m-ove, t-urn)\n");
            // Return 0 to show that input is invalid
            return 0;
        }
    }

    // If spaceCounter is less than 2, i.e., user input looks like this <x> <y> NOTHING
    if (spaceCounter < 2)
    {
        // Print the corresponding error message    
        printf("Error. Not enough parameters.\n");
        // Return 0 to show that input is invalid
        return 0;
    }


    /**
     * Note:
     *  In theory, now the input should have the proper formatting.
     *  We should only check the range of the starting positions,
     *  but we are also checking for other errors just to double check.
    */

    // Split input into spaces to get the first coordinate
    input = strtok(input, " ");
    // If input could not be split or there were not any more spaces
    if (input == NULL)
    {
        // Print the corresponding error message    
        printf("Error. Invalid input.\n");
        // Return 0 to show that input is invalid
        return 0;
    }

    // Convert the first input to a coordinate and assign it to xpos
    *xpos = atoi(input);

    // Split input again into spaces to get the second coordinate
    input = strtok(NULL, " ");
    // If input could not be split or there were not any more spaces
    if (input == NULL)
    {
        // Print the corresponding error message    
        printf("Error. Invalid input.\n");
        // Return 0 to show that input is invalid
        return 0;
    }

    // Convert the second input to a coordinate and assign it to ypos
    *ypos = atoi(input);


    // Check for proper ranges

    // If xpos is not in the range [0, 99]
    if (*xpos < 0 || *xpos > 99)
    {
        // Print the corresponding error message    
        printf("Error. X position should be between 0 and 99\n");
        // Return 0 to show that input is invalid
        return 0;
    }

    // If ypos is not in the range [0, 99]
    if (*ypos < 0 || *ypos > 99)
    {
        // Print the corresponding error message    
        printf("Error. Y position should be between 0 and 99\n");
        // Return 0 to show that input is invalid
        return 0;
    }

    // Split input again into spaces to get the third parameter
    input = strtok(NULL, " ");
    // If input could not be split or there were not any more spaces
    if (input == NULL)
    {
        // Print the corresponding error message    
        printf("Error. Invalid input.\n");
        // Return 0 to show that input is invalid
        return 0;
    }

    int i = 0; // Variable to keep track of the current index of the input path
    
    // Iterate over the last parameter which is the path
    while (*input != '\n')
    {
        // Assign the current character to the path array
        path[i] = *input;
        // Increment the counter and the input
        i++;
        input++;
    }
    // Assign the null terminator character to the path
    path[i] = '\0';

    // Return 1 for a valid input
    return 1;
}

void initializeRobot(ROBOT *rob, int xpos, int ypos)
{
    // assign the xpos value to the xpos of rob 
    rob->xpos = xpos;
    // assign the ypos value to the ypos of rob 
    rob->ypos = ypos;
    // Initialize the direction of rob to N(orth)(1) 
    rob->dir = N;
}

void move(ROBOT *rob)
{
    // Swich case based on the direction
    switch (rob->dir)
    {
    case N: // If the robot is currently facing North
        rob->ypos += 1; // Add 1 to the ypos
        break;
    case S: // If the robot is currently facing South
        rob->ypos -= 1; // Subtract 1 to the ypos
        break;
    case E: // If the robot is currently facing East
        rob->xpos += 1; // Add 1 to the xpos
        break;
    case W: // If the robot is currently facing West
        rob->xpos -= 1; // Subtract 1 to the xpos
        break;
    default:
        break;
    }
}

void turn(ROBOT *rob)
{
    /**
     * Turn the robot around by adding 1 to the current direction
     * If the current direction is more than 3 (W),
     * we use the modulo operator to loop it around and come back to 0 (N)
    */
     rob->dir = (rob->dir + 1) % 4;
}

/**
 * X Y D P
 * 3 5 N mtmtmtmtm
 * 3 6 N tmtmtmtm
 * 3 6 E mtmtmtm
 * 4 6 E tmtmtm
 * 4 6 S mtmtm
 * 4 5 S tmtm
 * 4 5 W mtm
 * 3 5 W tm
 * 3 5 N m
 * 3 6 N
 */
