#include "shell.h"

char *filename;

/**
 * s_shell - part of the main shell
 * @i: index
 * @paths: env paths
 * @argv: arguments
 * Return: void
 */
void s_shell(int i, char **paths, char **argv)
{
	char *command;

	if (i == 1)
		return;
	else if (i == 0)
	{
		command = get_path(paths, argv);
		if (command != NULL)
		{
			free(argv[0]);
			argv[0] = command;
		}
		else
		{
			printf("%s: %s\n", filename, COMMAND_NOT_FOUND);
			return;
		}
	}
	else if (i == 2)
	{
		if (access(argv[0], F_OK | X_OK) != 0)
		{
			free_ptr(argv);
			printf("%s: %s\n", filename, COMMAND_NOT_FOUND);
			return;
		}
	}
	_execve(argv);
	free_ptr(argv);
}

/**
 * main - Entry point
 * @argc: the number of arguments
 * @argv: the arguments
 * Return: the status
 */
int main(int argc, char **argv)
{
	char *buffer = NULL, **paths, *path, *delim = " \n\t\r:";
	int path_size, i, n;
	size_t buf_size = 0;

	filename = argv[0];
	path = getenv(PATH);
	path_size = token_size(path, ":");
	paths = tokenize(path_size, path, ":");
	while (1)
	{
		printf("[%s]$ ", getenv("USER"));
		n = getline(&buffer, &buf_size, stdin);
		if (strlen(buffer) == 1 && (n != -1))
			continue;
		argc = token_size(buffer, delim);
		argv = tokenize(argc, buffer, delim);
		i = checks(argv, buffer, paths);
		s_shell(i, paths, argv);
	}
	free_ptr(paths);
	return (0);
}
