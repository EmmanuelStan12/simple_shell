#include "shell.h"

/**
 * sub_shell - part of the main shell
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
			argv[0] = strdup(command);
			free(command);
		}
		else
		{
			perror(COMMAND_NOT_FOUND);
			return;
		}
	}
	else if (i == 2)
	{
		if (access(argv[0], F_OK | X_OK) != 0)
		{
			free(argv);
			perror(COMMAND_NOT_FOUND);
			return;
		}
	}
	_execve(argv);
	clean_execution(argv);
}

/**
 * main - Entry point
 * @argc: the number of arguments
 * @argv: the arguments
 * Return: the status
 */
int main(int argc, char **argv)
{
	char *buffer = NULL, **paths, *path,  *command = NULL, *delim = " \n\t\r:";
	int path_size, i, n;
	size_t buf_size = 0;

	path = getenv(PATH);
	path_size = token_size(path, ":");
	paths = tokenize(path_size, path, ":");
	while (1)
	{
		char seperator;

		prompt();
		n = getline(&buffer, &buf_size, stdin);
		if (strlen(buffer) == 1 && (n != -1))
			continue;
		seperator = _is_seperator(buffer);
		if (seperator == '\0')
		{
			argc = token_size(buffer, delim);
			argv = tokenize(argc, buffer, delim);
			i = checks(argv, buffer, paths);
			s_shell(i, paths, argv);
		}
		else
			_execute_seperators(paths, buffer, seperator, delim);
	}
	return (0);
}
