#include "shell.h"

/**
 * analyze_char - analyzes a string for a char
 * @holder: char to be evaluated
 * Return: the character
 */
char analyze_char(char holder)
{
	if (holder == 'n')
		return ('\n');
	else if (holder == 't')
		return ('\t');
	else if (holder == 'r')
		return ('\r');
	return ('\0');
}

/**
 * analyze_string - analyzes a given buffer
 * @buffer: the buffer to be analyzed
 * Return: the new buffer
 */
char *analyze_string(char *buffer)
{
	int i, j = 0, size = 0;
	char *str;

	for (i = 0; buffer[i] != '\0'; i++)
	{
		if (buffer[i] == '\\')
		{
			char c;

			c = analyze_char(buffer[i + 1]);
			if (c == '\0')
				continue;
			i++;
		}
		size++;
	}
	str = malloc((size + 1) * sizeof(*str));
	for (i = 0; buffer[i] != '\0'; i++)
	{
		if (buffer[i] == '\\')
		{
			char c = analyze_char(buffer[i + 1]);

			str[j] = c;
			i++;
		}
		else
			str[j] = buffer[i];
		j++;
	}
	str[size] = '\0';
	free(buffer);
	return (str);
}
