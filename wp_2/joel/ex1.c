// Includes section
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// Define section
#define MAX 64    // Maximum amount of bytes
#define MATRIX 99 // Matrix constraints

// Enum declarations

// Direction enum
enum DIRECTION
{
    NORTH, // = 0
    EAST,  // = 1
    SOUTH, // = 2
    WEST   // = 3
};

// Action enum
enum ACTION
{
    MOVE = 109, // ascii value for 'm'
    TURN = 116  // ascii value for 't'
};

// type definitions

// Robot type
typedef struct
{
    int xpos;                 // Int position for coordinate X
    int ypos;                 // Int position for coordinate Y
    enum DIRECTION direction; // Current direction of the robot
} ROBOT;                      // Assigned name

// Boolean type
typedef unsigned char boolean;

// Function prototypes
void gameLoop(ROBOT *robotPtr);       // Main game loop function
void gameOver();                      // Game over function
void move(ROBOT *robotPtr);           // Move function
void turn(ROBOT *robotPtr);           // Turn function
void clearBuffer();                   // Clear buffer function
void printMatrix(int posX, int posY); // Print matrix function

// Global 2D array for matrix
char matrix[MATRIX][MATRIX];
// Global flag for keep playing
boolean keepPlaying;

// Main function
int main(int argc, char const *argv[])
{
    // Robot type variable declaration
    ROBOT robot;
    // Robot type pointer declaration and initialization to address of robot
    ROBOT *robotPtr = &robot;

    // Keep playing == true
    keepPlaying = 1;

    // Game loop
    while (keepPlaying) // While true
    {
        // Call gameLoop function with pointer to robot as argument
        gameLoop(robotPtr);
        // Call gameOver to prompt user to keep playing or not
        gameOver();
    }
    // Return 0 for successful operation
    return 0;
}

// Game loop function
void gameLoop(ROBOT *robotPtr)
{
    // Declare variables
    char action[MAX];            // Reserve MAX bytes for action input
    robotPtr->xpos = 0;          // Current robot X position = 0
    robotPtr->ypos = 0;          // Current robot Y position = 0
    robotPtr->direction = NORTH; // Current robot direction = North (0)
    int xInput, yInput;

    do // Do at least once
    {
        // Take input fromm user
        printf("Please provide x-pos between 0-99:\n"); // Prompt to enter X position
        xInput = scanf("%d", &robotPtr->xpos);          // Take X position and store in robot xpos
        clearBuffer();                                  // Clear buffer
        printf("Please provide y-pos between 0-99:\n"); // Prompt to enter Y position
        yInput = scanf("%d", &robotPtr->ypos);          // Take Y position and store in robot ypos
        clearBuffer();                                  // Clear buffer

    } while ((robotPtr->xpos < 0 || robotPtr->xpos > MATRIX) || // Do while x input is out of accepted range OR
             (robotPtr->ypos < 0 || robotPtr->ypos > MATRIX) || // Do while y input is out of accepted range OR
             (xInput != 1 || yInput != 1));                     // Inputs are not integers

    // Print starting coordinates of robot
    printf("Current position of robot is:\nX:%d\nY:%d\n", robotPtr->xpos, robotPtr->ypos);
    // Prompt user to enter instructions
    printf("Please input your instructions as a string, where m is move and t is turn!\n");
    // Take instructions and save them in action variable
    fgets(action, MAX, stdin);

    // For every character in instructions
    for (int i = 0; i < strlen(action); i++)
    {
        if (action[i] != MOVE || action[i] != TURN) // If character is anything else than 'm' or 't'
        {
            // Print error message
            printf("Wrong instructions, please provide in the following format:\n"
                   "For move-turn-move-move, enter mtmm, lowercase without blankspaces\n");
            // Return 1 to indicate faulty execution
            exit(1);
        }
    }

    // For every character in instructions
    for (int i = 0; i < strlen(action); i++)
    {
        // Sleep for half a second
        usleep(500000);

        if (action[i] == MOVE) // If current char = 'm'
        {
            move(robotPtr);                                       // Call move function with robot pointer
            printMatrix(robotPtr->xpos, robotPtr->ypos);          // Call printMatrix to display matrix in CLI
            printf("Current position of robot is:\nX:%d\nY:%d\n", // Print current location of robot
                   robotPtr->xpos, robotPtr->ypos);
        }
        else if (action[i] == TURN) // If current char = 't'
        {
            turn(robotPtr);                                       // Call turn function with robot pointer
            printMatrix(robotPtr->xpos, robotPtr->ypos);          // Call printMatrix to display matrix in CLI
            printf("Current position of robot is:\nX:%d\nY:%d\n", // Print current location of robot
                   robotPtr->xpos, robotPtr->ypos);
        }
    }
}

// Game over function
void gameOver()
{
    // Declare string to store user input in, reserves 10 bytes
    char answer[10];
    // Prompt user to keep playing
    printf("Do you want to keep playing? y/n\n");
    // Take input from user and store in answer variable
    fgets(answer, 10, stdin);
    if (answer[0] == 'n' || answer[0] == 'N') // If first character of input is 'N' or 'n'
    {
        // Keep playing set to false, breaks the loop and exits out of the program
        keepPlaying = 0;
    }
}

// Move function
void move(ROBOT *robotPtr)
{
    switch (robotPtr->direction) // Switch case based on the current DIRECTION enum of the robot
    {
    case NORTH:                   // If current position is NORTH (0)
        robotPtr->ypos++;         // Increment robot y position
        robotPtr->ypos %= MATRIX; // If position overflows MATRIX, y appears on the opposite side
        break;                    // Break out of the switch statement
    case EAST:                    // If current position is EAST (1)
        robotPtr->xpos++;         // Increment robot x position
        robotPtr->xpos %= MATRIX; // If position overflows MATRIX, x appears on the opposite side
        break;                    // Break out of the switch statement
    case SOUTH:                   // If current position is SOUTH (2)
        robotPtr->ypos--;         // Decrement robot y position
        if (robotPtr->ypos < 0)   // If robot y position becomes negative
        {
            robotPtr->ypos = MATRIX; // robot y position becomes MATRIX upper boundary
        }
        break;                  // Break out of the switch statement
    case WEST:                  // If current position is WEST (3)
        robotPtr->xpos--;       // Decrement robot x position
        if (robotPtr->ypos < 0) // If robot x position becomes negative
        {
            robotPtr->ypos = MATRIX; // robot x position becomes MATRIX upper boundary
        }
        break; // Break out of the switch statement
    }
}

// Turn function
void turn(ROBOT *robotPtr)
{
    robotPtr->direction++;    // Robot direction increments (clockwise movement)
    robotPtr->direction %= 4; // If direction overflow, go back to start of enum WEST +1 -> NORTH
}

// Clear buffer function
void clearBuffer()
{
    int tempChar;                                             // Temporary int representation of a char
    while ((tempChar = getchar() != '\n' && tempChar != EOF)) // While there is still characters in the buffer, discard them
        ;
}

// Print matrix function
void printMatrix(int posX, int posY)
{
    // Clear screen
    system("clear");

    // Populate matrix with '.'
    for (int i = 0; i < MATRIX; ++i) // For every row, MATRIX amount of times
    {
        for (int j = 0; j < MATRIX; ++j) // For every column, MATRIX amount of times
        {
            matrix[i][j] = '.'; // Fill index with '.'
        }
    }

    // Mark the current position of the robot with 'X'
    if (posX >= 0 && posX <= MATRIX && posY >= 0 && posY <= MATRIX) // If coordinates are within the MATRIX limits
    {
        matrix[posX][posY] = 'X'; // Fill index with 'X'
    }

    // Print matrix
    for (int i = 0; i < MATRIX; ++i) // For every row, MATRIX amount of times
    {
        for (int j = 0; j < MATRIX; ++j) // For every column, MATRIX amount of times
        {
            printf("%c ", matrix[i][j]); // Print every "cell" of the matrix
        }
        printf("\n"); // Print newline
    }
}