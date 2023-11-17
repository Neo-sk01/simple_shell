#include "shell.h"


/**
 * check_logic_ops - checks and splits for && and || operators
 * @array_cmds: array of the commands.
 * @i: index in the array_cmds to be checked
 * @array_operators: array of the logical operators for each previous command
 *
 * Return: index of the last command in the array_cmds.
 */

int check_logic_ops(char *array_cmds[], int i, char array_ops[])

{
	char *temp = NULL;
	int j;

	for (j = 0; array_cmds[i] != NULL && array_cmds[i][j]; j++)
	{
		if (array_cmds[i][j] == '&' && array_cmds[i][j + 1] == '&')
		{
			temp = array_cmds[i];
			array_cmds[i][j] = '\0';
			array_cmds[i] = str_duplicate(array_cmds[i]);
			array_cmds[i + 1] = str_duplicate(temp + j + 2);
			i++;
			array_ops[i] = '&';
			free(temp);
			j = 0;
		}
		else if (array_cmds[i][j] == '|' && array_cmds[i][j + 1] == '|')
		{
			temp = array_cmds[i];
			array_cmds[i][j] = '\0';
			array_cmds[i] = str_duplicate(array_cmds[i]);
			array_cmds[i + 1] = str_duplicate(temp + j + 2);
			i++;
			array_ops[i] = '|';
			free(temp);
			j = 0;
		}
	}
	return (i);
}

