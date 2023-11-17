#include "shell.h"

/**
 * tokenize - this function separates a string using a designed delim
 * @data: a pointer to the program's data
 * Return: an array of the different parts of the string
 */

void tokenize(data_of_program *data)
{
	char *delim = " \t";
	int i, j, counter = 2, length;

	length = str_length(data->input_line);
	if (length)
	{
		if (data->input_line[length - 1] == '\n')
			data->input_line[length - 1] = '\0';
	}

	for (i = 0; data->input_line[i]; i++)
	{
		for (j = 0; delim[j]; j++)
		{
			if (data->input_line[i] == delim[j])
				counter++;
		}
	}

	data->token = malloc(counter * sizeof(char *));
	if (data->token == NULL)
	{
		perror(data->program_name);
		exit(errno);
	}
	i = 0;
	data->token[i] = str_duplicate(_strtok(data->input_line, delim));
	data->command_name = str_duplicate(data->token[0]);
	while (data->token[i++])
	{
		data->token[i] = str_duplicate(_strtok(NULL, delim));
	}
}
