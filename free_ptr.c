#include "shell.h"

/**
 * free_ptr - frees memory
 * @ptr: the memory to be freed
 * Return: void
 */
void free_ptr(char **ptr)
{
	int i;

	i = 0;
	while (ptr[i])
	{
		free(ptr[i]);
		i++;
	}
	free(ptr);
}
