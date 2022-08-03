#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define PATH "PATH"
#define USER "USER"

void print_env(char **args);
char *enter_command(void);
int count_cmd(char *cmd);
char **parse_cmd(char *cmd);
void _execve(char **argv);
char *append_path(char *path, char *command);
char *join_strings(char *first, char **tokens, char *delimiters);
int token_size(char *str, char *delimiter);
void print_env(char **args);
char **tokenize(int size, char *path, char *delimiter);

#endif
