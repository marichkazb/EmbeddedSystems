#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char *sentences[5] = {"Hello there!", "Bro, calm down", "I don't know what I'm doing", "I got that dawg in me", "Cringe"};
	int sentenceOption = 1;
	char userInput[10];

	while (sentenceOption > 0 && sentenceOption < 6)
	{
		printf("Enter an option from 1 to 5: \n");

		scanf("%s", userInput); // This will give you the address that's why you need the &

		if (strlen(userInput) > 1)
		{
			printf("Invalid option :(\n");
			break;
		}

		sentenceOption = atoi(userInput);

		if (sentenceOption > 0 && sentenceOption < 6)
		{
			printf("\t%s\n\n", sentences[sentenceOption - 1]);
		}
	}

	printf("Thank you for using this program :)\n");
}
