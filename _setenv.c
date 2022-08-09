#include "shell.h"

/**
 * _setenv - sets an environmental variable
 * @key: the identifier
 * @value: the value to be set
 * Return: -1, 0
 */
int _setenv(char *key, char *value)
{
	int status;

	status = setenv(key, value, 1);
	return (status);
}
