#include "shell.h"

/**
 * _print_env - prints the env variables
 * @var: nice
 * Return: the env var
 */
void _print_env(char **argv, int i)
{
	if (argv[i] == NULL)
		return;
	_print_env(argv, i + 1);
	printf("%s\n", argv[i]);
}

/**
 * print_env - prints the environmental variables
 * Return: void
 */
void print_env(void)
{
	char **env = environ;
	int i;

	i = 0;
	_print_env(env, i);
}
