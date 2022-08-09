#include "shell.h"

/**
 * _unsetenv - removes an environmental variable
 * @key: key to be removed
 * Return: status
 */
int _unsetenv(char *key)
{
	int status;

	status = unsetenv(key);
	return (status);
}
