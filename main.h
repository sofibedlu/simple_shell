#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#define BUFF 40
#define DELI " \n\t"
#define TRUE 1
extern char **environ;


char *read_line();
char **create_arg(char *line);
char **cp_env();
char *path_var(char **list);
char **path_directory(char *path1);
char **check_input_cmd(char **argv, char **array);
int execute(char **argv, char **array_str);
int create_proc(char **args, char **array_str);
void _free(char **buffer);
#endif
