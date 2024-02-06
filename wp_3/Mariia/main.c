#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void clearBuffer();
int *inputMatrix(int num, int numEl);

int main(void)
{
    int row, col, sum[16];
    printf("Input the size ");
    scanf("%d %d", &row, &col);
    if (row > 4 || col > 4)
    {
        printf("Error: invalid matrix size. max is 4x4\n");
        exit(1);
    }
    clearBuffer();

    int numEl = (row * col);

    int *matrix1 = inputMatrix(1, numEl);
    int *matrix2 = inputMatrix(2, numEl);

    for (int i = 0; i < numEl; i++)
    {
        int temp;
        temp = *(matrix1 + i) + *(matrix2 + i);
        *(sum + i) = temp;
    }
    for (int i = 0; i < numEl; i++)
    {
        printf("i: %d, matrixEl: %d\n", i, sum[i]);
    }
    printf("The sum is: \n");
    int j = col;
    for (int i = 0; i < j; i++)
    {
        printf("%d ", sum[i]);
        if (i == j - 1)
        {
            j < numEl ? j += col : numEl;
            printf("\n");
        }
    }
    return 0;
}

int *inputMatrix(int num, int numEl)
{
    int *matrix = malloc(16 * sizeof(int));
    printf("Input elements of the matrix %d: ", num);
    unsigned int input;
    int i;
    char c;
    for (i = 0; i <= 16; i++)
    {
        if (scanf("%d", &input) != 1)
        {
            printf("invalid character\n");
            exit(0);
        }
        if (((c = getchar()) == '\n') || c == EOF)
        {
            matrix[i] = input;
            break;
        }
        else
        {
            ungetc(c, stdin);
        }
        matrix[i] = input;
    }
    if (i != numEl - 1)
    {
        printf("invalid number of arguments\n");
        exit(0);
    }
    return matrix;
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
