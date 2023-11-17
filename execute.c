#include "shell.h"
/**
 * execute - execute a command with its entire path variables.
 * @data: a pointer to the program's data
 * Return: If sucess returns zero, otherwise, return -1.
 */

int execute(data_of_program *data)
{
	int return_value = 0, status;
	pid_t pidd;

	/* check for program in built ins */
	return_value = builtins_list(data);
	if (return_value != -1) /* if program was found in built ins */
		return (return_value);

	/* check for program file system */
	return_value = find_program(data);
	if (return_value)
	{ /* if program not found */
		return (return_value);
	}
	else
	{				   /* if program was found */
		pidd = fork(); /* create a child process */
		if (pidd == -1)
		{ /* if the fork call failed */
			perror(data->command_name);
			exit(EXIT_FAILURE);
		}
		if (pidd == 0)
		{ /* I am the child process, I execute the program*/
			return_value = execve(data->token[0], data->token, data->env);
			if (return_value == -1) /* if error when execve*/
				perror(data->command_name), exit(EXIT_FAILURE);
		}
		else
		{ /* I am the father, I wait and check the exit status of the child */
			wait(&status);
			if (WIFEXITED(status))
				errno = WEXITSTATUS(status);
			else if (WIFSIGNALED(status))
				errno = 128 + WTERMSIG(status);
		}
	}
	return (0);
}
