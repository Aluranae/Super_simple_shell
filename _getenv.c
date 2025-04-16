#include <stdio.h>
#include <string.h>

/**
 * _getenv - Get an environment variable
 * @name: Name of the environment variable
 *
 * Return: Value of the environment variable, or NULL if not found
 */
char *_getenv(const char *name)
{
	extern char **environ;
	int i = 0;
	char *token;

	while (environ[i] != NULL)
	{
		token = strchr(environ[i], '=');

		if (token != NULL)
		{
			int name_len = token - environ[i];

			/* Vérification si le nom correspond */
			if (strncmp(environ[i], name, name_len) == 0 && 
				name_len == strlen(name))
			{
				return (token + 1); /* Retourne la valeur après '=' */
			}
		}

		i++;
	}

	return (NULL);
}
