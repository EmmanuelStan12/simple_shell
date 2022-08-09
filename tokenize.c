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

	i = 0;
	paths = malloc(sizeof(char *) * (size + 1));
	while ((path = strtok(path, delimiter)) != NULL)
	{
		paths[i] = path;
		path = NULL;
		i++;
	}
	paths[i] = NULL;
	return (paths);
}
