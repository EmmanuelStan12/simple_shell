#include "shell.h"

/**
 * check_input - checks whether the input are commands only
 * @args: the commands
 * @paths: the paths
 * @size: the size
 * Return: the arguments
 */
int check_input(char **paths, char ***args, int size)
{
	int i, are_commands = 1;
	char **tokens, **argv = *args;

	tokens = malloc((size + 1) * sizeof(char *));
	for (i = 0; argv[i] != NULL; i++)
		tokens[i] = strdup(argv[i]);
	tokens[i] = NULL;
	for (i = 0; tokens[i] != NULL; i++)
	{
		if (tokens[i][0] == '/')
		{
			if (access(argv[i], F_OK & X_OK) == 0)
				continue;
			are_commands = 0;
		}
		else
		{
			char *command = get_path(paths, tokens[i]);

			if (command)
			{
				free(tokens[i]);
				tokens[i] = command;
				continue;
			}
			are_commands = 0;
		}
	}
	if (are_commands)
	{
		free_ptr(argv);
		*args = tokens;
	}
	else
		free_ptr(tokens);
	return (are_commands);
}
