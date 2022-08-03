#include "shell.h"

/**
 * token_size - determines the size of tokens in a string
 * @str: string to be evaluated
 * @delimiter: delimiter to be used
 * Return: the size of strings
 */
int token_size(char *str, char *delimiter)
{
	int size;
	char *buffer, *holder;

	size = 0;
	buffer = strdup(str);
	holder = buffer;
	while ((buffer = strtok(buffer, delimiter)) != NULL)
	{
		size++;
		buffer = NULL;
	}
	free(holder);
	return (size);
}
