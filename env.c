#include "shell.h"

/**
 * print_env - prints the environmental variables
 * Return: void
 */
void print_env(void)
{
	char **env = environ;
	int i;

	i = 0;
	while (env[i] != NULL)
	{
		printf("%s\n", env[i]);
		i++;
	}
}
