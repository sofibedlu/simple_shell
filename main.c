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
	char *line;
	char **arg;
	int status;

	do {
		printf("$ ");
		line = read_line();
		arg = create_arg(line);
		status = execute(arg);
		free(line);
		free(arg);
	} while (status);
	return (0);
}
/**
 * execute - it checks the user input builtin or
 * aprogram found in the path variable
 * @argv: user input command
 * Return: integer
 */
int execute(char **argv)
{
	return (create_proc(argv));
}
/**
 * create_proc - check the args and create process to execute the program
 * @args: user input command
 * Return: integer
 */
int create_proc(char **args)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid < 0)
	{
		perror("can't create a process");
	}
	else if (pid == 0)
	{
		/*child process*/
		if (execve(args[0], args, environ) == -1)
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
