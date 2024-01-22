#include <stdio.h>

int main()
{
	char* sentences[5] = { "Hello there!", "Bro, calm down", "I don't know what I'm doing", "I got that dawg in me", "Cringe" };
	int sentenceOption = 1;

	while (1)
	{
		printf("Enter an option from 1 to 5: \n");
		scanf("%d", &sentenceOption);

		if (sentenceOption < 1 || sentenceOption > 5)
			break;

		printf("\t%s\n\n", sentences[sentenceOption - 1]);
	}

	printf("Thank you for using this program :)\n");
}
