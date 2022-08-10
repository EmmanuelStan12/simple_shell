#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define PATH "PATH"
#define USER "USER"
#define PWD "PWD"
#define OLDPWD "OLDPWD"
#define HOME "HOME"

extern char **environ;

void print_env(void);
char *enter_command(void);
int count_cmd(char *cmd);
char **parse_cmd(char *cmd);
void _execve(char **argv);
char *append_path(char *path, char *command);
char *join_strings(char *first, char **tokens, char *delimiters);
int token_size(char *str, char *delimiter);
char **tokenize(int size, char *path, char *delimiter);
void free_ptr(char **ptr);
int blank_input(char *buffer);
int if_path(char *buffer);
int check_exit(char **tokens, char **paths, char *buffer);
void free_ptr(char **ptr);
char *get_path(char **paths, char **tokens);
int checks(char **tokens, char *buffer);
int ch_dir(char **token);
void prompt(void);
int _setenv(char **tokens);
int _unsetenv(char **tokens);
int Ex_it(char *str);
int _atoi(char *num);

#endif
