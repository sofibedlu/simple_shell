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

	if(getline(&line, &n, stdin) == -1)
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
