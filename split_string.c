#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * split_string - Splits a string into words
 * @str: The string to split
 *
 * Return: Array of strings (words)
 */
char **split_string(char *str)
{
	int i = 0;
	char *token;
	char **words = malloc(sizeof(char *) * 100);

	if (words == NULL)
		return (NULL);

	token = strtok(str, " \t\n");

	while (token != NULL)
	{
		words[i] = strdup(token); /* Duplication de chaque mot */
		i++;
		token = strtok(NULL, " \t\n");
	}

	words[i] = NULL; /* Terminaison du tableau par NULL */

	return (words);
}
