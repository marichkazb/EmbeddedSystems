#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        printf("No command line argument provided, please provide a name.\n");
        return 0;
    }
    if (strlen(argv[1]) > 50)
    {
        printf("Name too long, max 50 characters");
        return 0;
    }
    else if (strlen(argv[1]) < 3)
    {
        printf("Name too short, min 3 characters");
        return 0;
    }
    printf("Hello %s, how is your day today?\n", argv[1]);
    return 0;
}