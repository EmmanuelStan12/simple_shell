#include "shell.h"

/**
 * join_strings - returns the command with the tokens seperated by delimiter
 * @tokens: the split tokens
 * Return: the full path of the command
 */
char *join_strings(char *first, char **tokens, char *delimiter)
{
	char *command;
	int j = 1;

	command = first;
	while (tokens[j] != NULL)
	{
		strcat(command, " ");
		strcat(command, tokens[j]);
		j++;
	}
	return (command);
}
