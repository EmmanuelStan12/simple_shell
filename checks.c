#include "shell.h"

/**
* checks - checks for exit, path command, and env commands
* @tokens: tokenized input from user
* @buffer: user's input
* Return: 0, 1 Or 2
*/
int checks(char **tokens, char *buffer)
{
	int i, j, k, e, u;

	if (feof(stdin))
		_exit(0);
	if (tokens[0] == NULL)
		return (1);
	i = strcmp(tokens[0], "exit");
	j = strcmp(tokens[0], "env");
	k = strcmp(tokens[0], "cd");
	e = strcmp(tokens[0], "setenv");
	u = strcmp(tokens[0], "unsetenv");
	if (i == 0)
	{
		if (Ex_it(tokens[1]) == 1)
			return (1);
	}
	else if (j == 0)
	{
		print_env();
		return (1);
	}
	else if (k == 0)
	{
		if (ch_dir(tokens) == 1)
		return (1);
	}
	else if (buffer[0] == '/')
		return (2);
	else if (e == 0)
	{
		if (_setenv(tokens) != 0)
			perror("Invalid arguments...");
		return (1);
	}
	else if (u == 0)
	{
		if (_unsetenv(tokens) != 0)
			perror("Invalid arguments...");
		return (1);
	}
	return (0);
}
/**
* free_ptr - frees an array
* @ptr: array to be freed
* Return: void
*/
void free_ptr(char **ptr)
{
	int i = 0;

	while (ptr[i])
	{
		free(ptr[i]);
		i++;
	}
	free(ptr);
}
