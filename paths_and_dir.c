#include "shell.h"

/**
* get_path - gets the path of a given command
* @paths: directories in the path
* @tokens: tokenized input from user
* Return: address of the path
*/
char *get_path(char **paths, char **tokens)
{
	int i, j, path_len, command_len, len;
	char *path;

	for (i = 0; paths[i] != NULL; i++)
	{
		path_len = strlen(paths[i]);
		command_len = strlen(tokens[0]);
		len = (path_len + command_len);
		path = malloc(sizeof(char) * (len + 2));
		if (path == NULL)
		{
			return (NULL);
		}
		j = 0;
		while (j < path_len)
		{
			path[j] = paths[i][j];
			j++;
		}
		path[j] = '/';
		j = 0;
		while (j < command_len)
		{
			path[path_len + j + 1] = tokens[0][j];
			j++;
		}
		path[len + 1] = '\0';
		if (access(path, F_OK | X_OK) == 0)
			return (path);
	}
	return (NULL);
}
/**
* ch_dir - function that changes the working directory
* @token: contains the directory path
* Return: 1 0n success
*/
int ch_dir(char **token)
{
	const char *dir = NULL;
	char *buf = NULL;
	size_t size = 1024;

	if (token[1] == NULL)
		dir = getcwd(buf, size);
	else
		dir = token[1];
	if (chdir(dir) == -1)
	{
		perror(dir);
		return (0);
	}
	return (1);
}