#include "main.h"
/**
 * check_input_cmd - check the input command for its possible directories
 * @array: path directories
 * @argv: argument from getline
 * @av: program name
 * Return: executable command and arguments
 */
char **check_input_cmd(char **argv, char **array, char **av)
{
	char buffer[1024];
	struct stat st;
	int len, i;

	if (stat(argv[0], &st) == 0)
	{
		return (argv);
	}
	memset(buffer, 0, 1024);
	i = 0;
	while (array[i] != NULL)
	{
		len = strlen(array[i]) + strlen(argv[0]) + 2;
		strcat(buffer, array[i]);
		strcat(buffer, "/");
		strcat(buffer, argv[0]);
		buffer[len - 1] = '\0';
		if (stat(buffer, &st) == 0)
		{
			argv[0] = buffer;
			return (argv);
		}
		buffer[0] = '\0';
		i++;
	}
	printf("%s: 1: %s: not found\n", av[0], argv[0]);
	return (NULL);
}
/**
 * _free - frees allocated memory
 * @buffer: pointer to allocated space
 */
void _free(char **buffer)
{
	int i = 0;

	while (buffer[i] != NULL)
	{
		free(buffer[i]);
		i++;
	}
	free(buffer);
}
