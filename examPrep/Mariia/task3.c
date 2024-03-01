#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    char *str = "Cisbest";

    printf("%*c\n", (int)strlen(str), *str); // print first char
    for (int i = strlen(str) - 1; i >= 0; i--)
    {
        if (i == 1)
        {
            // reverse string and print last row
            char arr[strlen(str) + 1];
            char *reverseStr = arr;
            for (int k = strlen(str) - 1; k >= 0; k--)
            {
                int reverse = strlen(str) - k;
                *(reverseStr + reverse - 1) = *(str + k);
            }
            printf("%s%s\n", reverseStr, str);
            break;
        };

        // print pyramid
        int reverse = strlen(str) - i;
        printf("%*c%*c\n", i, *(str + reverse), reverse * 2, *(str + reverse));
    }
    return 0;
}