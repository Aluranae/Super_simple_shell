#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * main - Super simple shell
 *
 * Return: Always 0.
 */
int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	pid_t child_pid;
	int status;
	char *args[2];

	while (1)
	{
		printf("#cisfun$ ");
		
		read = getline(&line, &len, stdin);

		if (read == -1)
			break;
	
		if (line[read - 1] == '\n')
			line[read - 1] = '\0'; /* Suppression du retour à la ligne */
	
		args[0] = line;
		args[1] = NULL;
		
		child_pid = fork();

		if (child_pid == -1)
		{
			perror("Error:");
			continue;
		}

		if (child_pid == 0)
		{
			/* Exécution de la commande dans le processus enfant */
			if (execve(args[0], args, NULL) == -1)
			{
				perror("Error");
				exit(1);
			}
			exit(0);
		}
		else
		{
			/* Attente de la fin du processus enfant */
			wait(&status);
		}
	}

	free(line);
	return (0);
}
