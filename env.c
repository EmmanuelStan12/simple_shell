#include "shell.h"

/**
 * print_env - prints the environmental variables
 * @args: environmental variables
 * Return: void
 */
void print_env(char **args)
{
	while (*args != NULL)
	{
		printf("%s\n", *args);
		(*args)++;
	}
}
