#include "shell.h"

int main(int argc, char *argv[])
{
	char *cmd;
	int n, c;

	cmd = enter_command();
	n = count_cmd(cmd);
	argv = parse_cmd(cmd);
	_execve(argv);
	return (0);
}
/**
 * enter_command - gets input from standard input
 * commands and arguments
 * Return: address to a buffer holding the input
 */
char *enter_command(void)
{
	char *cmd, *buffer = NULL;
	size_t n = 0;
	int i = 0;

	printf("✓™ ");
	getline(&buffer, &n, stdin);
	if (feof(stdin))
		exit(98);
	cmd = malloc(sizeof(char) * strlen(buffer));
	if (cmd == NULL)
		return (NULL);
	cmd = buffer;
	return(cmd);
	free(cmd);
	free(buffer);
}
/**
 * count_cmd - counts tokens in input command
 * @cmd_str: command string and arguments
 * Return: number of tokens
 */
int count_cmd(char *cmd_str)
{
	int n, len, in = 0, out = 1;

	n = 0;
	len = strlen(cmd_str);
	while (*cmd_str)
	{
		if (*cmd_str == ' ' && len != 1)
		{
			in = 0;
		}
		if (in == 0 && *cmd_str != ' ' && *cmd_str != '\n')
		{
			n++;
			in = out;
		}
		++cmd_str;
	}
	return (n);
}
/**
 * parse_cmd - tokenizes command string to argv
 * @cmd: command string
 * Return: address to argv holding the tokens
 */
char **parse_cmd(char *cmd)
{
	char **argv, *tokens;
	char delim[] = " ,\n";
	int i = 0, argc = 0;

	argc = count_cmd(cmd);
	argv = malloc(sizeof(char) * (argc));
	if (argv == NULL)
		return (NULL);
	tokens = strtok(cmd, delim);
	while (tokens)
	{
		argv[i] = malloc(sizeof(char) * strlen(tokens));
		if (argv[i] == NULL)
		{
			free(argv);
			return (NULL);
		}
		argv[i] = tokens;
		tokens = strtok(NULL, delim);
		i++;
	}
	argv[i] = NULL;
	return(argv);
}
/**
 * _execve - executes command
 * @argv: argument variables with command in argv[0]
 * Return: void
 */
void _execve(char **argv)
{
	int argc, status;
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
		main(argc, argv);
	}
}
