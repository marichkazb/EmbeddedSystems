// Include section
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// main function declaration
int main(int argc, char *argv[])
{
    // declare a variable that will be holding elevator controller code
    unsigned char eCode = 0; // can store max of 8 bits. it is initialized to 0, so in binary 0000 0000
    if (argc == 6)           // check max number of arguments
    {
        // char *userInput[] = {"1", "7", "1", "1", "0"}; // useful for debugging
        // printf("Correct amount of arguments\n"); // useful for debugging
        int engine_on, floor_pos, door_pos, brake1, brake2; // declare variables for storing user input numbers

        // since every user input should be given in a specific order, we know the positions of desired elements
        engine_on = atoi(argv[1]); // input at position 1 corresponds to engine_on
        floor_pos = atoi(argv[2]); // input at postion 2 corresponds to floor_pos
        door_pos = atoi(argv[3]);  // input at position 3 corresponds to door_pos
        brake1 = atoi(argv[4]);    // input at position 4 corresponds to brake1
        brake2 = atoi(argv[5]);    // input at position 5 corresponds to brake2

        // uncomment for debugging
        // printf("engine %d, floor %d, door %d, brake1 %d, brake2 %d", engine_on, floor_pos, door_pos, brake1, brake2);

        // perform validity check of the user input. valid range is given by the task description
        if ((engine_on == 0 || engine_on == 1) && // valid range for engine_on: 0-1
            (floor_pos >= 0 && floor_pos <= 7) && // valid range for floor_pos: 0-7
            (door_pos >= 0 && door_pos <= 2) &&   // valid range for door_pos: 0-2
            (brake1 == 0 || brake1 == 1) &&       // valid range for brake1: 0-1
            (brake2 == 0 || brake2 == 1))         // valid range for brake2: 0-1
        {
            // now we want to bit shift the elements at the correct position and attach them to the final eCode element
            // to do this, I calculated the exact amount of bits the element should be shifted
            // then logical OR operator is comparing the initial eCode that was assigned to 0000 0000 with the binary representation of the number
            // since it's OR operator, the value of the current number will be assigned at the correct position in the eCode number
            eCode |= engine_on << 7; // set bit 0 to value of engine_on
            eCode |= floor_pos << 4; // set bits 2-4 to the value of floor_pos. any number in the range of 0-7 will have binary representation of 3 bits
            eCode |= door_pos << 2;  // set bits 5-6 to the value of door_pos
            eCode |= brake1 << 1;    // set bit 7 to the value of brake1
            eCode |= brake2 << 0;    // set bit 8 to the value of brake1
        }
        else // some validity checks didn't pass
        {
            // print user message
            printf("invalid input, please make sure that the input is in the correct range\n");
            // terminate the program
            return 0;
        }
    }
    else // number of provided elements is not 6
    {    // print user message
        printf("invalid: Incorrect amount of arguments\n");
        // terminate the program
        return 0;
    }
    // print the converted value in the hexadecimal representation
    printf("Hexadecimal representation: 0x%x\n", eCode);
    // terminate the program
    return 0;
}