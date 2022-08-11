#include "shell.h"

/**
* _putchar - writes the character c to stdout
* @c: The character to print
* Return: On success 1.
* On error, -1 is returned
*/
int _putchar(char c)
{
	return (write(1, &c, 1));
}
/**
* write_int - writes an integer
* @n: integer to be written
* Return: void
*/
void write_int(int n)
{
	int digit, sum, last;
	int divis = 1000000000;
	unsigned int num;

	num = n;
	sum = 0;

	while (divis > 1)
	{
		digit = (num / divis) % 10;
		sum += digit;
		if (sum != 0)
			_putchar(digit + '0');
		divis = divis / 10;
	}

	last = num % 10;
	_putchar(last + '0');
}

