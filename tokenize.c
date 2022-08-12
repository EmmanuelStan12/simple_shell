#include "shell.h"

/**
 * tokenize - get the path strings
 * @size: number of path variables
 * @path: full string path joined by ':'
 * @delimiter: string seperator
 * Return: the pointer to the array of the path variables
 */
char **tokenize(int size, char *path, char *delimiter)
{
	char **paths = NULL;
	int i;
	char *command, *holder;

	if (path)
	{
		i = 0;
		holder = strdup(path);
		command = holder;
		paths = malloc(sizeof(char *) * (size + 1));
		command = strtok(command, delimiter);
		while (command)
		{
			paths[i] = strdup(command);
			command = strtok(NULL, delimiter);
			i++;
		}
		paths[i] = NULL;
		free(holder);
	}
	return (paths);
}
