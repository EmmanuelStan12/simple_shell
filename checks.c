#include "shell.h"

/**
* checks - checks for exit, path command, and env commands
* @tokens: tokenized input from user
* @buffer: user's input
* @paths: paths
* Return: 0, 1 Or 2
*/
int checks(char **tokens, char *buffer, char **paths)
{
	int code;

	if (feof(stdin))
		_exit(98);
	if (tokens[0] == NULL)
		return (1);
	if (strcmp(tokens[0], "exit") == 0)
	{
		code = Ex_it(tokens[1]);
		if (code != 1)
		{
			free(tokens);
			free(buffer);
			free(paths);
			exit(code);
		}
		return (1);
	}
	else if (strcmp(tokens[0], "env") == 0)
	{
		print_env();
		return (1);
	}
	else if (strcmp(tokens[0], "cd") == 0)
	{
		if (ch_dir(tokens) == 1)
			return (1);
	}
	else if (buffer[0] == '/')
		return (2);
	else if (strcmp(tokens[0], "setenv") == 0)
	{
		_setenv(tokens);
		return (1);
	}
	else if (strcmp(tokens[0], "unsetenv") == 0)
	{
		_unsetenv(tokens);
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
