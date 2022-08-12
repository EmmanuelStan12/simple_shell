#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <dirent.h>
#include <errno.h>
#include <ctype.h>

#define PATH "PATH"
#define USER "USER"
#define PWD "PWD"
#define OLDPWD "OLDPWD"
#define HOME "HOME"
#define COMMAND_NOT_FOUND "No such file or directory"

extern char **environ;

void print_env(void);
char *enter_command(void);
int count_cmd(char *cmd);
char **parse_cmd(char *cmd);
int _execve(char **argv);
char *append_path(char *path, char *command);
char *join_strings(char *first, char **tokens, char *delimiters);
int token_size(char *str, char *delimiter);
char **tokenize(int size, char *path, char *delimiter);
void free_ptr(char **ptr);
int blank_input(char *buffer);
int if_path(char *buffer);
int check_exit(char **tokens, char **paths, char *buffer);
void free_ptr(char **ptr);
char *get_path(char **paths, char *token);
int checks(char **tokens, char *buffer, char **paths, int m);
int ch_dir(char **token);
void prompt(void);
int _setenv(char **tokens);
int _unsetenv(char **tokens);
char ***_seperator(char **paths, char *args, char *sp, char *delim);
char _is_seperator(char *args);
void _execute_seperators(char **paths, char *buffer, char sp, char *delim);
int Ex_it(char *str);
int _atoi(char *num);
void clean_execution(char **args);
char *analyze_string(char *buffer);
int check_input(char **paths, char ***argv, int size);

#endif
