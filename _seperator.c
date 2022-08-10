#include "shell.h"

/**
 * _seperator - analyzes a command for seperators
 * @args: the arguments
 * Return: 0, if there's no seperator, 1 for ;, 2 for && and 3 for ||
 */
char*** _seperator(char **paths, char *args, char *seperator, char *delim)
{
	char ***arguments;
	char **commands;
	int size, status, i = 0;

	size = token_size(args, seperator);
	commands = tokenize(size, args, seperator);
	i = 0;
	arguments = malloc(size * sizeof(char **));
	while (i < size)
	{
		int c_size;
		char *command;

		c_size = token_size(commands[i], delim);
		arguments[i] = tokenize(c_size, commands[i], delim);
		status = checks(arguments[i], args);
		if (status == 1)
			continue;
		else if (status == 0)
		{
			command = get_path(paths, arguments[i]);
			if (command != NULL)
				arguments[i][0] = strdup(command);
		}
		i++;
	}
	return (arguments);
}
