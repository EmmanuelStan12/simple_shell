#include "shell.h"

/**
 * sh_command_err - prints error message when command is not found
 * @argv: program and commands
 *
 */

void sh_command_err(char **argv)
{
	write(STDERR_FILENO, "./hsh " , 6);
	write(STDERR_FILENO, ": ", 2);
	write_int(ERR_COUNT);
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, argv[0], strlen(argv[0]));
	write(STDERR_FILENO, ": not found\n", 13);
}

/**
 * exec_err - prints error message when command fails to execute
 * @command: name of command
 */

void exec_err(char *command)
{
	perror(command);
}

/**
 * access_err - prints error message if user does not have execute permit
 * @argv: program and commands
 * @dir: dir to access
 */

void access_err(const char *dir)
{
	write(STDERR_FILENO, "./hsh ", 6);
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, dir, strlen(dir));
	write(STDERR_FILENO, ": Permission denied\n", 20);
}


/**
 * exit_error - prints error message for an invalid exit status
 * @argv: program and commands
 */

void exit_err(char **argv)
{
	write(STDERR_FILENO, "./hsh ", 6);
	write(STDERR_FILENO, ": ", 2);
	write_int(ERR_COUNT);
	write(STDERR_FILENO, ": Illegal number: ", 17);
	write(STDERR_FILENO, argv[0], strlen(argv[0]));
	write(STDERR_FILENO, "\n", 1);
}
