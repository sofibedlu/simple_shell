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

/**
 * struct built - structer for builtin commands
 * @arg: user input
 * @fun: function pointer for respective command
 */
typedef struct built
{
	char *arg;
	int (*fun)();
} builtin;
char *read_line();
char **create_arg(char *line);
char **cp_env();
char *path_var(char **list);
char **path_directory(char *path1);
char **check_input_cmd(char **argv, char **array);
int execute(char **argv, char **array_str, builtin func[]);
int create_proc(char **args, char **array_str);
int exit_sh();
int _env();
void _free(char **buffer);
#endif
