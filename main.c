#include "main.h"
/**
 * main - Entry point
 * @ac: number of argument
 * @av: argument vector
 * Return: always 0 (success)
 */
int main(int ac, char **av)
{
	char *path, *line;
	char **arg, **array_str, **list;
	int status;
	builtin func[] = {
		{"exit", exit_sh},
		{"env", _env},
		{NULL, NULL}
	};

	(void)ac;
	(void)av;
	list = cp_env();
	path = (path_var(list));
	array_str = path_directory(path);
	do {
		if (isatty(STDIN_FILENO))
			printf("$ ");
		line = read_line();
		arg = create_arg(line);
		status = execute(arg, array_str, func, av);
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
 * @func: structer for builtin functions
 * @av: program name
 * Return: integer
 */
int execute(char **argv, char **array_str, builtin func[], char **av)
{
	int i = 0;

	for (i = 0; func[i].arg != NULL; i++)
	{
		if (strcmp(argv[0], func[i].arg) == 0)
		{
			return (func[i].fun());
		}
	}
	return (create_proc(argv, array_str, av));
}
/**
 * create_proc - check the args and create process to execute the program
 * @args: user input command
 * @array_str: directories in the PATH variable
 * @av: program name
 * Return: integer
 */
int create_proc(char **args, char **array_str, char **av)
{
	pid_t pid;
	int status;
	char **argv;

	argv = check_input_cmd(args, array_str, av);
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
/**
 * exit_sh - exit the shell
 * Return: integer for the status
 */
int exit_sh(void)
{
	return (0);
}
/**
 * _env - print enviroment variable
 * Return: integer for status
 */
int _env(void)
{
	int i = 0;

	while (environ[i] != NULL)
	{
		printf("%s\n", environ[i]);
		i++;
	}
	return (1);
}
