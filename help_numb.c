#include "shell.h"

/**
 * long_to_string - converts a number to a string.
 * @number: number to be converten in an string.
 * @string: buffer to save the number as string.
 * @base: base to convert number
 *
 * Return: Nothing.
 */


void long_to_string(long number, char *string, int base)
{

	int index = 0, inNegative = 0;
	long constant = number;
	char letters[] = {"0123456789abcdef"};

	if (constant == 0)
		string[index++] = '0';

	if (string[0] == '-')
		inNegative = 1;

	while (constant)
	{
		if (constant < 0)
			string[index++] = letters[-(constant % base)];
		else
			string[index++] = letters[constant % base];
		constant /= base;
	}
	if (inNegative)
		string[index++] = '-';

	string[index] = '\0';
	str_reverse(string);
}


/**
 * _atoi - convert a string to an integer.
 *
 * @str: pointer to str origen.
 * Return: int of string or 0.
 */
int _atoi(char *str)
{
	int sign = 1;
	unsigned int number = 0;
	/*1- analisys sign*/
	while (!('0' <= *str && *str <= '9') && *str != '\0')
	{
		if (*str == '-')
			sign *= -1;
		if (*str == '+')
			sign *= +1;
		str++;
	}

	/*2 - extract the number */
	while ('0' <= *str && *str <= '9' && *str != '\0')
	{

		number = (number * 10) + (*str - '0');
		str++;
	}
	return (number * sign);
}

/**
 * count_characters - count the coincidences of character in string.
 *
 * @string: pointer to str origen.
 * @character: string with  chars to be counted
 * Return: int of string or 0.
 */
int count_characters(char *string, char *character)
{
	int i = 0, counter = 0;

	for (; string[i]; i++)
	{
		if (string[i] == character[0])
			counter++;
	}
	return (counter);
}
