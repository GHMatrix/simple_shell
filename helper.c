#include "main.h"

/**
 * free_recurrent_data - free the fields needed each loop
 * @data: struct of the program's data
 * Return: Nothing
 */
void free_recurrent_data(prog_data *data)
{
	if (data->tokens)
		free_array_of_pointers(data->tokens);
	if (data->ip_line)
		free(data->ip_line);
	if (data->cmd_name)
		free(data->cmd_name);

	data->ip_line = NULL;
	data->cmd_name = NULL;
	data->tokens = NULL;
}

/**
 * free_all_data - free all field of the data
 * @data: struct of the program's data
 * Return: Nothing
 */
void free_all_data(prog_data *data)
{
	if (data->file_desc != 0)
	{
		if (close(data->file_desc))
			perror(data->prog_name);
	}
	free_recurrent_data(data);
	free_array_of_pointers(data->env);
	free_array_of_pointers(data->aliases);
}

/**
 * free_array_of_pointers - frees each pointer of an array of pointers and the
 * array too
 * @array: array of pointers
 * Return: nothing
 */
void free_array_of_pointers(char **array)
{
	int i;

	if (array != NULL)
	{
		for (i = 0; array[i]; i++)
			free(array[i]);

		free(array);
		array = NULL;
	}
}

