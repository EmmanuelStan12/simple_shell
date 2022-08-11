#include "shell.h"

/**
 * clean_execution - frees all allocation in a single execution
 * @argv: the list of strings
 * Return: void
 */
void clean_execution(char **argv)
{
	free(argv[0]);
	free(argv);
}
