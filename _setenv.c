#include "shell.h"

/**
 * _setenv - sets an environmental variable
 * @tokens: the tokens of the command
 * Return: -1, 0
 */
int _setenv(char **tokens)
{
	int status;

	if (tokens[1] == NULL || tokens[2] == NULL)
	{
		perror("Invalid number of arguments...");
		return (1);
	}
	status = setenv(tokens[1], tokens[2], 1);
	return (status);
}
