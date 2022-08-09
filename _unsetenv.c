#include "shell.h"

/**
 * _unsetenv - removes an environmental variable
 * @tokens: tokens to be evaluated
 * Return: status
 */
int _unsetenv(char **tokens)
{
	int status;

	if (tokens[1] == NULL)
	{
		perror("Invalid number of arguments...\n");
		return (1);
	}
	status = unsetenv(tokens[1]);
	return (status);
}
