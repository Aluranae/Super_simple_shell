#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
* main - Simple program that prints a prompt, waits for user input,
*        and then prints the entered line.
*
* Return: Always 0 (Success)
*
* Description:
* This program mimics the first step of a shell.
* It:
*  1. Displays the prompt "$ " to stdout.
*  2. Waits for the user to enter a command (using getline).
*  3. Prints the entered command to stdout.
*
* Note:
* - If the user sends EOF (Ctrl+D), the program exits silently.
* - getline automatically allocates (or resizes) the buffer.
*/

int main(void)
{
	char *line = NULL; /* Pointer to store the input line */

	size_t len = 0;   /* Size of the buffer */
	ssize_t nread;   /* Number of characters read */

	/* Display the prompt */
	write(STDOUT_FILENO, "$ ", 2);

	/* Read a line from standard input */
	nread = getline(&line, &len, stdin);
	if (nread == -1)
	{
		/* If getline fails (EOF or error), clean up and exit */
		free(line);
		return (0);
	}

	/* Print the input line */
	printf("%s", line);

	free(line);  /* Free the allocated memory */
	return (0);
}
