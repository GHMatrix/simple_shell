#include "main.h"
/**
 * tokenize - this function separate the string using a designed delimiter
 * @data: a pointer to the program's data
 * Return: an array of the different parts of the string
 */
void tokenize(prog_data *data)
{
	char *delimiter = " \t";
	int i, j, counter = 2, length;

	length = str_length(data->ip_line);
	if (length)
	{
		if (data->ip_line[length - 1] == '\n')
			data->ip_line[length - 1] = '\0';
	}

	for (i = 0; data->ip_line[i]; i++)
	{
		for (j = 0; delimiter[j]; j++)
		{
			if (data->ip_line[i] == delimiter[j])
				counter++;
		}
	}

	data->tokens = malloc(counter * sizeof(char *));
	if (data->tokens == NULL)
	{
		perror(data->prog_name);
		exit(errno);
	}
	i = 0;
	data->tokens[i] = str_duplicate(_strtok(data->ip_line, delimiter));
	data->cmd_name = str_duplicate(data->tokens[0]);
	while (data->tokens[i++])
	{
		data->tokens[i] = str_duplicate(_strtok(NULL, delimiter));
	}
}
