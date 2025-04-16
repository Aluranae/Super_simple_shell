#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * struct path_node - Node in a path directory list
 * @directory: Directory path
 * @next: Pointer to the next node
 */
typedef struct path_node
{
	char *directory;
	struct path_node *next;
} path_node_t;

/**
 * build_path_list - Build a linked list of PATH directories
 *
 * Return: Pointer to the first node
 */
path_node_t *build_path_list(void)
{
	extern char **environ;
	int i = 0;
	char *path = NULL;
	char *path_copy;
	char *token;
	path_node_t *head = NULL, *node, *current;

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
			node = malloc(sizeof(path_node_t));

			if (node == NULL)
			{
				/* Libération en cas d'erreur */
				while (head != NULL)
				{
					current = head;
					head = head->next;
					free(current->directory);
					free(current);
				}
				free(path_copy);
				return (NULL);
			}

			node->directory = strdup(token);
			node->next = NULL;

			/* Ajout du nœud à la liste */
			if (head == NULL)
			{
				head = node;
				current = node;
			}
			else
			{
				current->next = node;
				current = node;
			}
			
			token = strtok(NULL, ":");
		}
		
		free(path_copy);
	}
	
	return (head);
}

/**
 * main - Test function
 *
 * Return: Always 0.
 */
int main(void)
{
	path_node_t *path_list, *current;
	
	path_list = build_path_list();
	
	current = path_list;
	while (current != NULL)
	{
		printf("%s\n", current->directory);
		current = current->next;
	}
	
	/* Libération de la mémoire */
	while (path_list != NULL)
	{
		current = path_list;
		path_list = path_list->next;
		free(current->directory);
		free(current);
	}
	
	return (0);
}
