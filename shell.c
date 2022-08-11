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
 * handle_terminal - handles terminal input
 * @argv: arguments
 * Return: void
 */
void handle_terminal(char **argv)
{
	int i;
	char **command;

	i = 0;
	while (argv[i])
	{
		command = malloc(sizeof(char *) * 2);
		command[0] = argv[i];
		command[1] = NULL;
		_execve(command);
		free(argv[i]);
		free(command);
		i++;
	}
	free(argv);
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
	int path_size, i, n, int_mode = 1;
	size_t buf_size = 0;

	filename = argv[0];
	path = getenv(PATH);
	path_size = token_size(path, ":");
	paths = tokenize(path_size, path, ":");
	while (1)
	{
		int_mode = isatty(STDIN_FILENO);
		if (int_mode == 1)
			printf("[%s]$ ", getenv("USER"));
		n = getline(&buffer, &buf_size, stdin);
		if (strlen(buffer) == 1 && (n != -1))
			continue;
		argc = token_size(buffer, delim);
		argv = tokenize(argc, buffer, delim);
		if (int_mode == 1)
		{
			i = checks(argv, buffer, paths);
			s_shell(i, paths, argv);
		}
		else
		{
			handle_terminal(argv);
			free(buffer);
			free_ptr(paths);
			exit(0);
		}
	}
	free_ptr(paths);
	return (0);
}
