#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/**
 * _setenv - Change or add an environment variable
 * @name: Name of the environment variable
 * @value: Value to set
 * @overwrite: Whether to overwrite if exists
 *
 * Return: 0 on success, -1 on error
 */
int _setenv(const char *name, const char *value, int overwrite)
{
	extern char **environ;
	int i = 0, name_len, found = 0;
	char *new_var, **new_environ;

	if (name == NULL || name[0] == '\0' || strchr(name, '=') != NULL)
		return (-1);

	name_len = strlen(name);

	/* Recherche si la variable existe déjà */
	while (environ[i] != NULL)
	{
		if (strncmp(environ[i], name, name_len) == 0 && environ[i][name_len] == '=')
		{
			found = 1;
			if (!overwrite)
				return (0);

			/* Création de la nouvelle variable name=value */
			new_var = malloc(name_len + strlen(value) + 2);
			if (new_var == NULL)
				return (-1);

			sprintf(new_var, "%s=%s", name, value);

			free(environ[i]);
			environ[i] = new_var;
			return (0);
		}
		i++;
	}

	/* Ajout de la variable si elle n'existe pas */
	if (!found)
	{
		new_environ = malloc(sizeof(char *) * (i + 2));
		if (new_environ == NULL)
			return (-1);

		for (int j = 0; j < i; j++)
			new_environ[j] = environ[j];

		new_var = malloc(name_len + strlen(value) + 2);
		if (new_var == NULL)
		{
			free(new_environ);
			return (-1);
		}

		sprintf(new_var, "%s=%s", name, value);
		
		new_environ[i] = new_var;
		new_environ[i + 1] = NULL;
		
		environ = new_environ;
		return (0);
	}
	
	return (-1);
}
