#include "shell.h"

/**
 * has_exit - has exits
 * @argv: arguments
 * Return: int
 */
int has_exit(char **argv)
{
	int i, is_exit = 0;

	for (i = 0; argv[i] != NULL; i++)
	{
		if (strcmp(argv[i], "exit") == 0)
			is_exit = 1;
	}
	return (is_exit);
}

/**
 * handle_exit - handles exit
 * @argv: arguments
 * @buffer: buffer
 * @paths: paths
 * Return: void
 */
void handle_exit(char **argv, char *buffer, char **paths)
{
	int i, j;
	char **commands;

	for (i = 0; argv[i] != NULL; i++)
		;
	if (i != 1)
	{
		commands = malloc(i * sizeof(char *));
		for (j = 0; j < (i - 1); j++)
		{
			commands[j] = argv[j];
		}
		commands[j] = NULL;
		_execve(commands);
		free(buffer);
		free_ptr(paths);
		free_ptr(argv);
		free(commands);
		exit(2);
	}
	free(buffer);
	free_ptr(paths);
	free_ptr(argv);
	exit(0);
}

/**
 * handle_env - handles exit
 * @argv: arguments
 * @buffer: buffer
 * @paths: paths
 * Return: void
 */
void handle_env(char **argv, char *buffer, char **paths)
{
	print_env();
	free(buffer);
	free_ptr(paths);
	free_ptr(argv);
	exit(0);
}
/**
* checks - checks for exit, path command, and env commands
* @tokens: tokenized input from user
* @buffer: user's input
* @paths: paths
* @m: mode
* Return: 0, 1 Or 2
*/
int checks(char **tokens, char *buffer, char **paths, int m)
{
	if (tokens[0] == NULL)
		return (1);
	if (has_exit(tokens) == 1)
		handle_exit(tokens, buffer, paths);
	else if (strcmp(tokens[0], "env") == 0)
	{
		if (m != 1)
			handle_env(tokens, buffer, paths);
		print_env();
		return (1);
	}
	else if (strcmp(tokens[0], "cd") == 0)
	{
	}
	else if (buffer[0] == '/' || buffer[0] == '.')
		return (2);
	else if (strcmp(tokens[0], "setenv") == 0)
	{
		return (1);
	}
	else if (strcmp(tokens[0], "unsetenv") == 0)
	{
		return (1);
	}
	return (0);
}
