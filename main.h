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
int execute(char **argv);
int create_proc(char **args);
#endif
