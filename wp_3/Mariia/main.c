#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void clearBuffer();
void inputMatrix(int matrix[], int num, int numEl);

int main(void)
{
    int row, col, matrix1[16], matrix2[16], sum[16];
    printf("Input the size ");
    scanf("%d %d", &row, &col);
    clearBuffer();

    int numEl = (row * col);

    inputMatrix(matrix1, 1, numEl);
    clearBuffer();
    inputMatrix(matrix2, 2, numEl);

    for (int i = 0; i < numEl; i++)
    {
        sum[i] = matrix1[i] + matrix2[i];
        // matrix1[0] <<= sizeof(int) * 8;
        // matrix2[0] <<= sizeof(int) * 8;
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

void inputMatrix(int matrix[], int num, int numEl)
{
    printf("Input elements of the matrix %d: ", num);
    char c;
    int i = 0;
    while ((c = getchar()) != '\n' && c != EOF)
    {
        if (i > numEl)
        {
            printf("Error: Invalid number of arguments\n");
            exit(0);
        };
        if (!isdigit(c))
        {
            if (isspace(c))
            {
                continue;
            }
            else
            {

                printf("Error: Invalid input, please provide only digits\n");
                exit(0);
            }
        }
        matrix[i] = c;
        printf("%c", matrix[i]);
        i++;
        // ungetc(c, stdin);
    }
    printf("matrix is\n");
    for (int i = 0; i < numEl; i++)
    {
        printf("numEl: %d, matrix: %d", numEl, matrix[i]);
        printf("\n");
    }
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
