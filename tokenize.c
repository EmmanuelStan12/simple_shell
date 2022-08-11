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
	char **paths;
	int i;
	char *command;

	i = 0;
	command = strdup(path);
	paths = malloc(sizeof(char *) * (size));
	while ((command = strtok(command, delimiter)) != NULL)
	{
		paths[i] = command;
		command = NULL;
		i++;
	}
	return (paths);
	free(paths);
}
