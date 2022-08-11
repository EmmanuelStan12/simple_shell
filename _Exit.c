#include "shell.h"

/**
 * _atoi - this converts a string to an integer
 * @s: string to be convertwd
 * Return: returns the resulting integer
 */
int _atoi(char *s)
{

	int i, r = 0, sign = -1;

	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] == '-')
			sign = sign * -1;
		if (s[i] >= '0' && s[i] <= '9')
		{
			r = r * 10;
			r -= (s[i] - '0');
		}
	}
	r = sign * r;
	return (r);
}
/**
* Ex_it - exits the shell with an int status
* @str: exit status
* Return: 1
*/
int Ex_it(char *str)
{
	int i = 0, flag = 0, code;
	char *dup = NULL;

	dup = str;
	if (str == NULL)
	{
		return (127);
	}
	while (dup[i])
	{
		if (dup[i] < '0' || dup[i] > '9')
		{
			flag = -1;
			break;
		}
		i++;
	}
	code = _atoi(dup);
	if (flag == -1)
	{
		write(STDERR_FILENO, "invalid number: argument should be of type int\n", 47);
		return (1);
	}
	return (code);
}
