#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * main - Execute ls -l /tmp in 5 child processes
 *
 * Return: Always 0.
 */
int main(void)
{
	pid_t child_pid;
	int status;
	int i;
	char *args[] = {"/bin/ls", "-l", "/tmp", NULL};

	for (i = 0; i < 5; i++)
	{
		child_pid = fork();

		if (child_pid == -1)
		{
			perror("Error:");
			return (1);
		}

		if (child_pid == 0)
		{
			/* Code du processus enfant */
			printf("Child %d executing ls -l /tmp\n", i + 1);

			if (execve(args[0], args, NULL) == -1)
			{
				perror("Error:");
				exit(1);
			}
			exit(0);
		}
		else
		{
			/* Attendre que l'enfant termine avant de créer le suivant */
			wait(&status);
			printf("Child %d has finished\n", i + 1);
		}
	}

	return (0);
}
