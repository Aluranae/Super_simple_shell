#include <stdio.h>
#include <stdlib.h>

/**
 * main - Entry point of the program
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	char *line = NULL;

	size_t len = 0;
	ssize_t nread;

	while (1)
	{
		printf("$ ");
		nread = getline(&line, &len, stdin);

		if (nread == -1)
		{
			printf("\n");
			break;
		}

		printf("%s", line);
	}

	free(line);
	return (0);
}
