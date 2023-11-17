#include "shell.h"
/**
 * str_length - returns the length of a string.
 * @string: pointer to string.
 * Return: length of string.
 */


int str_length(char *string)
{
	int len = 0;

	if (string == NULL)
		return (0);

	while (string[len++] != '\0')
	{
	}
	return (--len);
}

/**
 * str_duplicate - duplicates an string
 * @string: String to be copied
 * Return: pointer to the array
 */
char *str_duplicate(char *string)
{
	char *result;
	int len, i;

	if (string == NULL)
		return (NULL);

	len = str_length(string) + 1;

	result = malloc(sizeof(char) * len);

	if (result == NULL)
	{
		errno = ENOMEM;
		perror("Error");
		return (NULL);
	}
	for (i = 0; i < len ; i++)
	{
		result[i] = string[i];
	}

	return (result);
}

/**
 * str_compare - Compare two strings
 * @str1: String one, or the shorter
 * @str2: String two, or the longer
 * @number: number of characters to be compared, 0 if infinite
 * Return: 1 if the strings are equals,0 if the strings are different
 */


int str_compare(char *str1, char *str2, int number)
{
	int iterate;

	if (str1 == NULL && str2 == NULL)
		return (1);

	if (str1 == NULL || str2 == NULL)
		return (0);

	if (number == 0) /* infinite longitud */
	{
		if (str_length(str1) != str_length(str2))
			return (0);
		for (iterate = 0; str1[iterate]; iterate++)
		{
			if (str1[iterate] != str2[iterate])
				return (0);
		}
		return (1);
	}
	else /* if there is a number of chars to be compared */
	{
		for (iterate = 0; iterate < number ; iterate++)
		{
			if (str1[iterate] != str2[iterate])
			return (0);
		}
		return (1);
	}
}

/**
 * str_concat - concatenates two strings.
 * @str1: String to be concatenated
 * @str2: String to be concatenated
 *
 * Return: pointer to the array
 */
char *str_concat(char *str1, char *str2)
{
	char *result;
	int leng = 0, length2 = 0;

	if (str1 == NULL)
		str1 = "";
	leng = str_length(str1);

	if (str2 == NULL)
		str2 = "";
	length2 = str_length(str2);

	result = malloc(sizeof(char) * (leng + length2 + 1));
	if (result == NULL)
	{
		errno = ENOMEM;
		perror("Error");
		return (NULL);
	}

	/* copy of str1 */
	for (leng = 0; str1[leng] != '\0'; leng++)
		result[leng] = str1[leng];
	free(str1);

	/* copy of str2 */
	for (length2 = 0; str2[length2] != '\0'; length2++)
	{
		result[leng] = str2[length2];
		leng++;
	}

	result[leng] = '\0';
	return (result);
}


/**
 * str_reverse - reverses a string.
 *
 * @string: pointer to string.
 * Return: void.
 */
void str_reverse(char *string)
{

	int i = 0, len = str_length(string) - 1;
	char hold;

	while (i < len)
	{
		hold = string[i];
		string[i++] = string[len];
		string[len--] = hold;
	}
}
