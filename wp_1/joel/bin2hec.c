#include <stdio.h>
#include <stdlib.h>

int main() {
    char bin[33];
    if (scanf("%32s", &bin[0]) != 1) {
        fprintf(stderr, "Error reading binary input\n");
        return 1;
    }

    int dec = strtol(bin, NULL, 2);
    printf("Hexadecimal: %X\n", dec);

    return 0;
}