#include "shell.h"

/**
 * _execute_seperators - execute the different commands
 * @paths: paths to env vars
 * @buffer: command input
 * @sp: command seperator
 * @delim: delimiter
 * Return: void
 */
void _execute_seperators(char **paths, char *buffer, char sp, char *delim)
{
	char ***commands;
	char *seperators;
	int status, i;

	seperators = malloc(2 * sizeof(sp));
	seperators[0] = sp;
	i = 0;
	commands = _seperator(paths, buffer, seperators, delim);
	if (sp == '|')
	{

		while ((status = _execve(commands[i])) != 0 && commands[i] != NULL)
		{
			i++;
		}
	}
	else if (sp == '&')
	{
		while ((status = _execve(commands[i])) == 0 && commands[i] != NULL)
			i++;
	}
	else if (sp == ';')
	{
		while (commands[i] != NULL)
		{
			_execve(commands[i]);
			i++;
		}
	}
	free(seperators);
	i = 0;
	while (commands[i] != NULL)
	{
		i++;
	}
}
