#include "main.h"
/**
 * main - Entry point
 * @ac: number of argument
 * @av: argument vector
 * Return: always 0 (success)
 */
int main(int ac, char **av)
{
	(void)ac;
	(void)av;
	char *line, *path;
	char **arg, **array_str, **list;
	int status;

	list = cp_env();
	path = (path_var(list));
	array_str = path_directory(path);
	do {
		printf("$ ");
		line = read_line();
		arg = create_arg(line);
		status = execute(arg, array_str);
		free(line);
		free(arg);
	} while (status);
	free(array_str);
	_free(list);
	return (0);
}
/**
 * execute - it checks the user input builtin or
 * aprogram found in the path variable
 * @argv: user input command
 * @array_str: directories in the PATH variable
 * Return: integer
 */
int execute(char **argv, char **array_str)
{
	return (create_proc(argv, array_str));
}
/**
 * create_proc - check the args and create process to execute the program
 * @args: user input command
 * @array_str: directories in the PATH variable
 * Return: integer
 */
int create_proc(char **args, char **array_str)
{
	pid_t pid;
	int status;
	char **argv;

	argv = check_input_cmd(args, array_str);
	if (argv == NULL)
		return (1);
	pid = fork();
	if (pid < 0)
	{
		perror("can't create a process");
	}
	else if (pid == 0)
	{
		/*child process*/
		if (execve(argv[0], argv, environ) == -1)
		{
			perror("can't execute the command");
		}
	}
	else
	{
		/**parent process*/
		wait(&status);
	}
	return (1);
}
