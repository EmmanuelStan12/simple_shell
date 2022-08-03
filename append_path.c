#include "shell.h"

/**
 * append_path - appends the arguments to the path
 * @path: path of the command
 * @command: arguments to the command
 * Return: full command path
 */
char *append_path(char *path, char *command)
{
	char *buffer;
	int i = 0, j = 0;

	buffer = malloc((strlen(path) + strlen(command) + 2) * sizeof(char));
	while (path[i] != '\0')
	{
		buffer[i] = path[i];
		i++;
	}
	if (path[i - 1] != '/')
	{
		buffer[i] = '/';
		i++;
	}
	while (command[j] != '\0')
	{
		buffer[i + j] = command[j];
		j++;
	}
	return (buffer);
}
