#include "shell.h"

/**
 * _execve - executes command
 * @argv: argument variables with command in argv[0]
 * Return: void
 */
int _execve(char **argv)
{
	int status;
	pid_t pid;

	pid = fork();
	if (pid == 0)
	{
		status = execve(argv[0], argv, environ);
		printf("%s: 1: %s: not found\n", argv[0], argv[1]);
		exit(1);
	}
	else
	{
		wait(&status);
	}
	return (status);
}
