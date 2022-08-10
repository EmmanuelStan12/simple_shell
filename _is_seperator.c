#include "shell.h"

/**
 * _is_seperator - checks whether there's a seperator
 * @args: the command
 * Return: the seperator
 */
char _is_seperator(char *args)
{
	int i;
	char last_sp = '\0';

	for (i = 0; args[i] != '\0'; i++)
	{
		if (args[i] == ';')
		{
			last_sp = args[i];
			break;
		}
		else if (args[i] == '&' && args[i + 1] == '&')
		{
			last_sp = args[i];
			i++;
			break;
		}
		else if (args[i] == '|' && args[i + 1] == '|')
		{
			last_sp = args[i];
			i++;
			break;
		}
	}
	return (last_sp);
}
