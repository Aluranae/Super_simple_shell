#include <stdio.h>
#include <string.h>

#define MAX_ARGS 64

/**
 * split_line - Découpe une ligne de commande en tokens
 * @line: Chaîne de caractères à découper
 * @args: Tableau qui contiendra les pointeurs vers les tokens
 *
 * Cette fonction :
 * - Utilise les espaces et retours à la ligne comme délimiteurs
 * - Stocke chaque mot (token) dans le tableau args
 * - Termine le tableau par NULL
 */

void split_line(char *line, char **args)
{
	char *token;
	int i = 0;

	token = strtok(line, " \n");
	while (token != NULL)
	{
		args[i++] = token;
		token = strtok(NULL, " \n");
	}
	args[i] = NULL;
}

/**
 * main - Programme de test pour split_line
 *
 * Lit une ligne depuis l'entrée standard, découpe les mots,
 * et les affiche un par un.
 *
 * Return: Always 0
 */

int main(void)
{
	char line[1024];
	char *args[MAX_ARGS];
	int i;

	printf("$ ");
	if (fgets(line, sizeof(line), stdin) == NULL)
		return (0);

	split_line(line, args);

	for (i = 0; args[i] != NULL; i++)
		printf("arg[%d] = %s\n", i, args[i]);

	return (0);
}
