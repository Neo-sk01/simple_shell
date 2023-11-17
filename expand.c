#include "shell.h"

/**
 * some_function_name - Description of the function
 * @data: Struct containing program data
 *
 * Return: 0 on success, or other values depending on error
 */
int some_function_name(data_of_program *data)
{
	int pidd, return_value, status;

	pidd = fork(); /* create a child process */
	if (pidd == -1)
	{
		perror(data->command_name);
		exit(EXIT_FAILURE);
	}
	if (pidd == 0)
	{
		return_value = execve(data->token[0], data->token, data->env);
		if (return_value == -1)
		{
			perror(data->command_name);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(&status);
		if (WIFEXITED(status))
			errno = WEXITSTATUS(status);
		else if (WIFSIGNALED(status))
			errno = 128 + WTERMSIG(status);
	}
	return (0);
}

