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
	if (feof(stdin))
		_exit(98);
	if (tokens[0] == NULL)
		return (1);
	if (strcmp(tokens[0], "exit") == 0)
	{
		free(buffer);
		free_ptr(paths);	
		free_ptr(tokens);
		exit(127);
	}
	else if (strcmp(tokens[0], "env") == 0)
	{
		return (1);
	}
	else if (strcmp(tokens[0], "cd") == 0)
	{
	}
	else if (buffer[0] == '/')
		return (2);
	else if (strcmp(tokens[0], "setenv") == 0)
	{
		return (1);
	}
	else if (strcmp(tokens[0], "unsetenv") == 0)
	{
		return (1);
	}
	return (0);
}
