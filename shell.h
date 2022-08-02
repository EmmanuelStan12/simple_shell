
#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

char *enter_command(void);
int count_cmd(char *cmd);
char **parse_cmd(char *cmd);
void _execve(char **argv);

#endif
