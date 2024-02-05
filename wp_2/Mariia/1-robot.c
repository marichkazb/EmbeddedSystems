#include <stdlib.h>
#include <stdio.h>

enum DIRECTION
{
    N,
    E,
    S,
    W
};
typedef struct
{
    int x;
    int y;
    enum DIRECTION dir;
} ROBOT;

void move(int *x, int *y, enum DIRECTION *dir);
void turn(enum DIRECTION *dir);
void startRobot();

int main(int argc, char **argv)
{
    startRobot();
    return 0;
}

void startRobot()
{
    ROBOT robot;
    robot.dir = N;
    char commands[100];
    printf("Input robots starting position X\n");
    if (scanf("%d", &robot.x) != 1 || robot.x < 0 || robot.x > 99)
    {
        printf("Invalid input\n");
        exit(1);
    };
    printf("Input robots starting position Y\n");
    if (scanf("%d", &robot.y) != 1 || robot.y < 0 || robot.y > 99)
    {
        printf("Invalid input\n");
        exit(1);
    };
    printf("Input string of commands\n");
    scanf("%s", commands);

    int i = 0;
    while (commands[i] != '\0')
    {
        if (commands[i] == 'm')
        {
            move(&robot.x, &robot.y, &robot.dir);
        }
        else if (commands[i] == 't')
        {
            turn(&robot.dir);
        }
        else
        {
            printf("Command is invalid, try again\n");
            exit(1);
        }
        i++;
    }

    printf("New position is: %d, %d. Direction is: %i\n", robot.x, robot.y, robot.dir);
    startRobot();
}

void move(int *x, int *y, enum DIRECTION *dir)
{

    switch (*dir)
    {
    case N:
        (*y)++;
        break;
    case E:
        (*x)++;
        break;
    case S:
        (*y)--;
        break;
    case W:
        (*x)--;
    default:
        break;
    }
}

void turn(enum DIRECTION *dir)
{
    if (*dir == W)
    {
        *dir = N;
    }
    else
    {
        (*dir)++;
    }
}