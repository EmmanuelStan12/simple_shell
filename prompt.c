#include "shell.h"

/**
* prompt - prints the prompt for input from user
* Return: void
*/
void prompt(void)
{
	write(STDOUT_FILENO, "$ ", 2);
}
