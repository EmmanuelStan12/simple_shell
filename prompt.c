#include "shell.h"

/**
* prompt - prints the prompt for input from user
* Return: void
*/
void prompt(void)
{
	char *w_dir = NULL, *buff = NULL;
	int len;

	w_dir = getcwd(buff, 150);
	len = strlen(w_dir);
	write(STDOUT_FILENO, "[", 2);
	write(STDOUT_FILENO, w_dir, len);
	write(STDOUT_FILENO, "] ", 2);
}
