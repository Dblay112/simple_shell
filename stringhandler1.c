#include "shellheader.h"

/**
 * stringlength - function to calculate the length of a string
 * @str: lenghh of string to calculate
 * Return: final length of string
 */

int stringlength(const char *str)
{
	int len;

	len = 0;
	if (!str)
	{
		return (0);
	}

	while (*str != '\0')
	{
		len = len + 1;
		str = str + 1;
	}

	return (len);
}

/**
 * stringcompare - function that compares two strings
 * @str1: first string to compare
 * @str2: second string to compare
 * Return: final string
 */

int stringcompare(char *str1, char *str2)
{
	int i;

	i = 0;
	while (str1[i] != '\0' && str2[i] != '\0')
	{
		if (str1[i] != str2[i])
		{
			return (-1);
		}
		i++;
	}

	if (str1[i] == '\0' && str2[i] == '\0')
	{
		return (0);
	}
	else
	{
		return (1);
	}
}
/**
 * findcharacter - find a string in a character sequence
 * @str: string to find in the sequence
 * @character: pointer to the char in the function
 * Return: final string
 */

char *findcharacter(char *str, char *character)
{
	int len_str, len_char;
	char *res;
	int i;

	len_str = 0;
	len_char = 0;
	while (*(character + len_char) != '\0')
		len_char++;

	while (*(str + len_str) != '\0')
		len_str++;

	for (i = 0; i < len_char; i++)
	{
		if (*(character + i) != *(str + i))
		{
			return ((char *)NULL);
		}
	}

	res = (char *)str;
	return (res);
}

/**
 * appendstring - function to append strings
 * @dest: destination of string to append
 * @src: source of string to be appended
 * Return: final string appended
 */

char *appendstring(char *dest, const char *src)
{
	int dest_length;
	int i;
	int src_length;

	dest_length = 0;
	src_length = 0;
	while (dest[dest_length] != '\0')
	{
		dest_length++;
	}

	while (src[src_length] != '\0')
	{
		src_length++;
	}

	for (i = 0; i < src_length; i++)
	{
		dest[dest_length + i] = src[i];
	}

	dest[dest_length + i] = '\0';

	return (dest);
}

/**
 * copystring- function to copy string
 * @dests: destination of string to copy
 * @source: source of string to copy
 * Return: final string copied
 */

char *copystring(char *dests, char *source)
{
	int i;

	i = 0;

	if (dests == source || source == 0)
	{
		return (dests);
	}

	while (source[i] != '\0')
	{
		dests[i] = source[i];
		i++;
	}

	dests[i] = '\0';

	return (dests);
}
