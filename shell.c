#include "shell.h"

/**
 * free_all - frees memory
 * @av: arguments
 * @pts: paths
 * @buf: buffer
 * @m: mode
 * @c: code
 * Return: void
 */
void free_all(char **av, char **pts, char *buf, int m, int c)
{
	if (av)
		free_ptr(av);
	if (m != 1)
	{
		free(buf);
		if (pts)
			free_ptr(pts);
		exit(c);
	}
}

/**
 * handle_terminal - handles terminal input
 * @argv: arguments
 * @buf: buffer
 * @paths: paths
 * Return: void
 */
void handle_terminal(char **argv, char *buf, char **paths)
{
	int i;
	char **command;
	DIR *dir = NULL;

	i = 0;
	if (argv[1])
		dir = opendir(argv[1]);
	if (dir)
	{
		_execve(argv);
		closedir(dir);
		free_ptr(argv);
	}
	else
	{
		while (argv[i])
		{
			command = malloc(sizeof(char *) * 2);
			command[0] = argv[i];
			command[1] = NULL;
			checks(command, buf, paths, 1);
			_execve(command);
			free(argv[i]);
			free(command);
			i++;
		}
		free(argv);
	}
}

/**
 * s_shell - part of the main shell
 * @i: index
 * @paths: env paths
 * @argv: arguments
 * @fname: the name of the file
 * @buf: buffer
 * @m: mode
 * Return: void
 */
void s_shell(char *fname, int i, char *buf, char **paths, char **argv, int m)
{
	if (i == 1)
	{
		free_all(argv, paths, buf, m, 0);
		return;
	}
	else if (i == 0)
	{
		char *command = get_path(paths, argv[0]);

		if (command != NULL)
		{
			free(argv[0]);
			argv[0] = command;
			_execve(argv);
			free_all(argv, paths, buf, m, 0);
		}
		else
		{
			fprintf(stderr, "%s: %d: %s: not found\n", fname, 1, argv[0]);
			free_all(argv, paths, buf, m, 127);
		}
	}
	else if (i == 2)
	{
		int ack = access(argv[0], F_OK | X_OK);

		if (ack != 0 && m == 1)
		{
			free_ptr(argv);
			fprintf(stderr, "%s: %d: %s: not found\n", fname, 1, argv[0]);
		}
		else if (m != 1)
		{
			if (ack == 0)
				_execve(argv);
			else
				printf("%s: %s\n", fname, COMMAND_NOT_FOUND);
			free_all(argv, paths, buf, m, 0);
		}
	}
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
	int path_size, i, n, mode = 1;
	size_t buf_size = 0;
	char *filename = argv[0];

	path = getenv(PATH);
	path_size = token_size(path, ":");
	paths = tokenize(path_size, path, ":");
	while (1)
	{
		mode = isatty(STDIN_FILENO);
		if (mode == 1)
		{
			printf("[%s]$ ", getenv("USER"));
			n = getline(&buffer, &buf_size, stdin);
		}
		else
			n = getdelim(&buffer, &buf_size, '\0', stdin);
		if (strlen(buffer) == 1 && (n != -1))
			continue;
		buffer = analyze_string(buffer);
		argc = token_size(buffer, delim);
		argv = tokenize(argc, buffer, delim);
		if (argc > 1 && check_input(paths, &argv, argc) && mode != 1)
		{
			handle_terminal(argv, buffer, paths);
			free_all((char **)NULL, paths, buffer, mode, 0);
		}
		else
		{
			i = checks(argv, buffer, paths, mode);
			s_shell(filename, i, buffer, paths, argv, mode);
		}
	}
	free_ptr(paths);
	return (0);
}
