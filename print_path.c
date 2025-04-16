#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * print_path_directories - Print each directory in PATH
 *
 * Return: void
 */
void print_path_directories(void)
{
	extern char **environ;
	int i = 0;
	char *path = NULL;
	char *path_copy;
	char *token;

	/* Recherche de PATH dans l'environnement */
	while (environ[i] != NULL)
	{
		if (strncmp(environ[i], "PATH=", 5) == 0)
		{
			path = environ[i] + 5;
			break;
		}
		i++;
	}

	if (path)
	{
		path_copy = strdup(path);

		token = strtok(path_copy, ":");

		while (token != NULL)
		{
			printf("%s\n", token);
			token = strtok(NULL, ":");
		}

		free(path_copy);
	}
}

/**
 * main - Test function
 *
 * Return: Always 0.
 */
int main(void)
{
	print_path_directories();
	return (0);
}
