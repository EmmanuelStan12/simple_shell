#include "shell.h"

/**
 * print_env - prints the environmental variables
 * @args: environmental variables
 * Return: void
 */
void print_env(char **args)
{
	int i;

	i = 0;
	while (args[i] != NULL)
	{
		printf("%s\n", args[i]);
		i++;
	}
}
