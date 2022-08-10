#include "shell.h"

/**
 * _execute_seperators - execute the different commands
 * @args: the arguments
 * Return: void
 */
void _execute_seperators(char **paths, char *buffer, char seperator, char *delim)
{
	char ***commands;
	char *seperators;
	int status, i;

	seperators = malloc(2 * sizeof(seperator));
	seperators[0] = seperator;
	i = 0;
	commands = _seperator(paths, buffer, seperators, delim);
	if (seperator == '|')
	{

		while ((status = _execve(commands[i])) != 0 && commands[i] != NULL)
		{
			i++;
		}
	}
	else if (seperator == '&')
	{
		while ((status = _execve(commands[i])) == 0 && commands[i] != NULL)
			i++;
	}
	else if (seperator == ';')
	{
		while (commands[i] != NULL)
		{
			_execve(commands[i]);
			i++;
		}
	}
	free(seperators);
}
