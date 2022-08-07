#include "shell.h"

/**
* checks - checks for exit, path command, and env commands
* @tokens: tokenized input from user
* @env: environment variable
* @buffer: user's input
* Return: 0, 1, 0r 2
*/
int checks(char **tokens, char **env, char *buffer)
{
	int i, j, k;

	if (feof(stdin))
		_exit(98);
	i = strcmp(tokens[0], "exit");
	j = strcmp(tokens[0], "env");
	k = strcmp(tokens[0], "cd");
	if (i == 0)
	{
		free(buffer);
		_exit(127);
	}
	else if (j == 0)
	{
		print_env(env);
		return (1);
	}
	else if (k == 0)
	{
		if (ch_dir(tokens) == 1)
		return (1);
	}
	else if (buffer[0] == '/')
		return (2);
	return (0);
}
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
* free_ptr - frees an array
* @ptr: array to be freed
* Return: void
*/
void free_ptr(char **ptr)
{
	int i = 0;

	while (ptr[i])
	{
		free(ptr[i]);
		i++;
	}
	free(ptr);
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
