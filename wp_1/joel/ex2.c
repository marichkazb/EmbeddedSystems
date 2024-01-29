#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 32

int loopAscii(int);

int main(int argc, char const *argv[])
{
    int shiftAmount = atoi(argv[1]);
    char input[MAX];

    printf("Please input word to encrypt.\n");
    
    while (fgets(input, MAX, stdin) != NULL)
    {

        for (int i = 0; i < strlen(input); i++)
        {
            int encryptedChar = (int)input[i] + shiftAmount;
            printf("%c", encryptedChar);
        }
        printf("%s", "\n");
    }

    return 0;
}

int loopAscii(int asciiCode){
    // modulus shit
}