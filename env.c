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
	if (env)
	{
		while (env[i])
		{
			printf("%s\n", env[i]);
			i++;
		}
	}
}
