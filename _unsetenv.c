#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/**
 * _unsetenv - Delete a variable from the environment
 * @name: Name of the variable to delete
 *
 * Return: 0 on success, -1 on error
 */
int _unsetenv(const char *name)
{
	extern char **environ;
	int i = 0, j, name_len;

	if (name == NULL || name[0] == '\0' || strchr(name, '=') != NULL)
		return (-1);

	name_len = strlen(name);

	/* Recherche de la variable à supprimer */
	while (environ[i] != NULL)
	{
		if (strncmp(environ[i], name, name_len) == 0 && environ[i][name_len] == '=')
		{
			free(environ[i]);

			/* Décalage des variables suivantes */
			for (j = i; environ[j] != NULL; j++)
				environ[j] = environ[j + 1];

			return (0);
		}
		i++;
	}

	return (0);
}
