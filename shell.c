#include "shell.h"

/**
 * main - Entry point
 * @argc: the number of arguments
 * @argv: the arguments
 * @env: environmental variables
 * Return: the status
 */
int main(int argc, char **argv, char **env)
{
	char *buffer, **paths, *path, *delim = " \n\t\r:";
	int path_size;
	size_t buf_size;

	buf_size = 1;
	path = getenv(PATH);
	path_size = token_size(path, ":");
	paths = tokenize(path_size, path, ":");
	buffer = malloc(buf_size * sizeof(*buffer));
	if (buffer == NULL)
	{
		free(paths);
		return (1);
	}
	while (1)
	{
		int i = 0, t_size;
		char **tokens;

		if (buffer == "exit\n")
		{
			printf("exit");
			exit(0);
		}
		printf("[%s]~$ ", getenv(USER));
		getline(&buffer, &buf_size, stdin);
		t_size = token_size(buffer, delim);
		tokens = tokenize(t_size, buffer, delim);
		if (*buffer == '/')
		{
			_execve(tokens);
		}
		else
		{
			char *command;
			while (i < path_size)
			{
				command = append_path(paths[i], tokens[0]);
				if (access(command, F_OK | X_OK) == 0)
					break;
				free(command);
				i++;
			}
			tokens[0] = command;
			if (i != path_size)
				_execve(tokens);
			else
				perror("command not found...\n");
		}
	}
	return (0);
}
