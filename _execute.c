#include "shell.h"

/**
 * _execve - executes command
 * @argv: argument variables with command in argv[0]
 * Return: void
 */
void _execve(char **argv)
{
	int status;
	pid_t pid;

	pid = fork();
	if (pid == 0)
	{
		execve(argv[0], argv, NULL);
		perror("unknown command");
		exit(1);
	}
	else
	{
		wait(&status);
	}
}