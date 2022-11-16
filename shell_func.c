#include "main.h"

/**
 * read_line - read the input command
 *
 * Return: pointer to the input command
 */
char *read_line()
{
	char *line = NULL;
	size_t n = 0;

	if (getline(&line, &n, stdin) == -1)
	{
		if (feof(stdin))
		{
			perror("end of file");
			exit(EXIT_SUCCESS);
		}
		else
		{
			perror("can't read a line:");
			exit(EXIT_FAILURE);
		}
	}
	return (line);
}
/**
 * create_arg - create array of argument from the line
 * @line: user input
 * Return: array of argument
 */
char **create_arg(char *line)
{
	int i;
	char **argv;
	char *token;

	i = 0;
	argv = malloc(sizeof(char *) * BUFF);
	if (argv == NULL)
	{
		perror("memory allocation failed");
		exit(EXIT_FAILURE);
	}
	token = strtok(line, DELI);
	while (token != NULL)
	{
		argv[i] = token;
		if (i >= BUFF)
		{
			argv = realloc(argv, i + BUFF);
		}
		token = strtok(NULL, DELI);
		i++;
	}
	argv[i] = NULL;
	return (argv);
}
/**
 * cp_env - its duplicate the environ variable
 *
 * Return: pointer to array of string
 */
char **cp_env()
{
	char **list;
	int size, i;

	for (size = 0; environ[size] != NULL; size++)
	list = malloc(size * sizeof(char *));
	if (list == NULL)
	{
		perror("can't allocate memory");
		exit(EXIT_FAILURE);
	}
	for (i = 0; i < size; i++)
	{
		list[i] = strdup(environ[i]);
	}
	/*list[i] = NULL;*/
	return (list);
}
/**
 * path_var - search the path variable
 * @list: array of pointer for environ
 * Return: pointer to the value of PATH variable
 */
char *path_var(char **list)
{
	char *path, *token;
	int i = 0;
	char **_env = list;

	token = strtok(_env[i], "=");
	while (_env[i] != NULL)
	{
		if (strcmp(token, "PATH") == 0)
		{
			path = strtok(NULL, "=");
			break;
		}
		token = strtok(_env[i], "=");
		i++;
	}
	return (path);
}
/**
 * path_directory - store each directoreis found in path variable
 * @path1: pointer to the string $PATH
 * Return: array of pointers
 */
char **path_directory(char *path1)
{
	char **dirc;
	char *token;
	int i = 0;

	dirc = malloc(sizeof(char *) * 10);
	if (dirc == NULL)
	{
		perror("can't allocate memory");
		exit(EXIT_FAILURE);
	}
	token = strtok(path1, ":");
	while (token != NULL)
	{
		dirc[i] = token;
		token = strtok(NULL, ":");
		i++;
	}
	/*dirc[i] = NULL;*/
	return (dirc);
}
