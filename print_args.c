#include <stdio.h>


/**
* main - Entry point of the program
* @ac: Argument count
* @av: Argument vector
*
* Return: Always 0 (Success)
*/

int main(int ac, char **av)
{
	(void)ac;

	char **arg = av;

	while (*arg != NULL)
	{
		printf("%s\n", *arg);
		arg++;
	}

	return (0);
}
