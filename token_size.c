#include "shell.h"

/**
 * token_size - determines the size of tokens in a string
 * @str: string to be evaluated
 * @delimiter: delimiter to be used
 * Return: the size of strings
 */
int token_size(char *str, char *delimiter)
{
	int size, flag = 0;
	char *buffer, *holder;

	size = 1;
	buffer = strdup(str);
	holder = buffer;
	while (*holder == ' ')
		holder++;
	while (*holder)
	{
		if (strchr(delimiter, *holder) != NULL && flag == 0)
		{
			size++;
			flag = 1;
		}
		else if (strchr(delimiter, *holder) == NULL && flag == 1)
		{
			flag = 0;
		}
		holder++;
	}
	free(buffer);
	return (size);
}
