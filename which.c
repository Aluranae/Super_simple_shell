#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

/**
 * _which - Find a file in the PATH
 * @filename: Name of the file to find
 *
 * Return: Full path if found, NULL otherwise
 */
char *_which(char *filename)
{
	char *path, *path_copy, *path_token, *file_path;
	int filename_len, directory_len;
	struct stat buffer;

	path = getenv("PATH");

	if (path)
	{
		path_copy = strdup(path); /* Copie de PATH pour strtok */
		filename_len = strlen(filename);

		path_token = strtok(path_copy, ":");

		while (path_token != NULL)
		{
			directory_len = strlen(path_token);

			/* Allocation pour chemin complet */
			file_path = malloc(directory_len + filename_len + 2);

			if (file_path == NULL)
			{
				free(path_copy);
				return (NULL);
			}

			/* Construction du chemin complet */
			strcpy(file_path, path_token);
			strcat(file_path, "/");
			strcat(file_path, filename);

			if (stat(file_path, &buffer) == 0)
			{
				free(path_copy);
				return (file_path); /* Fichier trouvé */
			}

			free(file_path);
			path_token = strtok(NULL, ":");
		}

		free(path_copy);
	}

	return (NULL);
}

/**
 * main - Implementation of which command
 *
 * Return: Always 0.
 */
int main(int ac, char **av)
{
	int i;
	char *path;

	if (ac < 2)
	{
		printf("Usage: %s filename ...\n", av[0]);
		return (1);
	}

	for (i = 1; i < ac; i++)
	{
		path = _which(av[i]);

		if (path)
		{
			printf("%s\n", path);
			free(path);
		}
		else
		{
			printf("%s: not found\n", av[i]);
		}
	}

	return (0);
}
