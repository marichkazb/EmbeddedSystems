#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define END_CHAR x

enum DIRECTION
{
    N,
    S,
    E,
    W
};

typedef struct
{
    int xpos;
    int ypos;
    enum DIRECTION dir;
} ROBOT;

void validateInput(char *input, int *xpos, int *ypos, char *path)
{
    for (int i = 0; i < strlen(input); i++)
    {
        if (input[i] == 'x')
        {
            printf("Thank you for using this program :)\n");
            exit(0);
        }
    }

    // TODO: check for every character to make sure null characters don't give me 0s
    input = strtok(input, " ");
    if (input == NULL)
    {
        printf("Invalid input");
        exit(0);
    }

    *xpos = atoi(input);

    input = strtok(NULL, " ");
    if (input == NULL)
    {
        printf("Invalid input");
        exit(0);
    }

    *ypos = atoi(input);

    input = strtok(NULL, " ");
    if (input == NULL)
    {
        printf("Invalid input");
        exit(0);
    }

    if (*xpos < 0 || *xpos > 99)
    {
        printf("Invalid x");
        exit(0);
    }
    if (*ypos < 0 || *ypos > 99)
    {
        printf("Invalid y");
        exit(0);
    }

    int i = 0;
    while (*input != '\0')
    {
        if (*input == '\n')
        {
            break;
        }
        else if (*input != 'm' && *input != 't')
        {
            printf("Invalid path");
            exit(0);
        }
        path[i] = *input;
        i++;
        input++;
    }
    path[i] = '\0';
}

void initializeRobot(ROBOT *rob, int xpos, int ypos)
{
    rob->xpos = xpos;
    rob->ypos = ypos;
    rob->dir = N;
}

void move(ROBOT *rob)
{
    switch (rob->dir)
    {
    case N:
        rob->ypos += 1;
        break;
    case S:
        rob->ypos -= 1;
        break;
    case E:
        rob->xpos += 1;
        break;
    case W:
        rob->xpos -= 1;
        break;
    default:
        break;
    }
}

void turn(ROBOT *rob)
{
    switch (rob->dir)
    {
    case N:
        rob->dir = E;
        break;
    case E:
        rob->dir = S;
        break;
    case S:
        rob->dir = W;
        break;
    case W:
        rob->dir = N;
        break;
    default:
        break;
    }
}

int main()
{
    int xStart;
    int yStart;
    char inputBuffer[500];
    char path[500];

    while (1)
    {
        printf("Enter the starting position and the movement string as it follows:\n");
        printf("\t<x> <y> <mt...tm>\n");

        fgets(inputBuffer, sizeof(inputBuffer), stdin);

        validateInput(inputBuffer, &xStart, &yStart, path);

        ROBOT rob;

        initializeRobot(&rob, xStart, yStart);

        char *pPath = path;

        while (*pPath != '\0')
        {
            if (*pPath == 'm')
            {
                move(&rob);
            }
            else if (*pPath == 't')
            {
                turn(&rob);
            }
            else
            {
                printf("Some error here\n");
            }
            pPath++;
        }

        printf("\n----------\n");
        printf("The final position of the robot is: \n");
        printf("\t X: %d\n", rob.xpos);
        printf("\t Y: %d\n", rob.ypos);
        printf("\t Facing: %d\n", rob.dir);
        printf("----------\n\n");
    }

    return 0;
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