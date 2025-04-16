#include <stdio.h>
#include <unistd.h>

/**
 * main - Compare env and environ addresses
 *
 * Return: Always 0.
 */
int main(int ac, char **av, char **env)
{
	extern char **environ;

	printf("Address of env (parameter): %p\n", (void *)env);
	printf("Address of environ (global): %p\n", (void *)environ);

	if (env == environ)
		printf("env and environ are the same\n");
	else
		printf("env and environ are different\n");

	return (0);
}
