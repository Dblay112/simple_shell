#include "shellheader.h"

/**
 * stringduplicate - function to duplicate strings
 * @str: string to duplicate
 * Return: final duplicated string
 */

char *stringduplicate(char *str)
{
	int length = 0;
	char *ret;

	if (str == NULL)
		return (NULL);
	while (*str++)
		length++;
	ret = malloc(sizeof(char) * (length + 1));
	if (!ret)
		return (NULL);
	for (length++; length--;)
		ret[length] = *--str;
	return (ret);
}

/**
 * stringcompare_n - compare first n char of str1 & str 2
 * @str1: 1st string to compare
 * @str2: 2nd string to compare
 * @n: number of char to compare in string
 * Return: compared string
 */

int stringcompare_n(const char *str1, const char *str2, size_t n)
{
	size_t i;

	i = 0;
	while (i < n)
	{
		if (str1[i] != str2[i])
	{
		return (str1[i] - str2[i]);
	}
	if (str1[i] == '\0')
	{
		return (0);
	}
	i++;
	}

	return (0);
}

/**
 * file_writer - checks to see if its STDOUT or STDERR
 * @c: char to be written
 * @stream: pointer to the FILE
 * Return: Nothing
 */

void file_writer(char c, FILE *stream)
{
	if (stream == stdout || stream == stderr)
	{
	write(fileno(stream), &c, 1);
	}
}
