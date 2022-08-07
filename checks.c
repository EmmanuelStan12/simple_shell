#include "shell.h"

/**
* checks - checks for exit, path command, and env commands
* @tokens: tokenized input from user
* @env: environment variable
* @buffer: user's input
* Return: 0, 1, 0r 2
*/
int checks(char **tokens, char **env, char *buffer)
{
	int i, j, k;

	if (feof(stdin))
		_exit(98);
	i = strcmp(tokens[0], "exit");
	j = strcmp(tokens[0], "env");
	k = strcmp(tokens[0], "cd");
	if (i == 0)
	{
		free(buffer);
		_exit(127);
	}
	else if (j == 0)
	{
		print_env(env);
		return (1);
	}
	else if (k == 0)
	{
		if (ch_dir(tokens) == 1)
		return (1);
	}
	else if (buffer[0] == '/')
		return (2);
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
