#include "shell.h"

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
		prompt();
		n = getline(&buffer, &buf_size, stdin);
		if (strlen(buffer) == 1 && (n != -1))
			continue;
		argc = token_size(buffer, delim);
		argv = tokenize(argc, buffer, delim);

		i = checks(argv, buffer);
		if (i == 1)
			continue;
		else if (i == 0)
		{
			command = get_path(paths, argv);
			if (command != NULL)
				argv[0] = strdup(command);
		}
		_execve(argv);
	}
	return (0);
}
