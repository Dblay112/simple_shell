#include "shell.h"

/**
 * _strlen - function that returns the length of a strings
 * @s: the length of string to be checked pointer
 *
 * Return: final length of the string characters
 */
int _strlen(const char *s)
{
	int len_string = 0;

	if (!s)
		return (0);

	while (*s++)
		len_string++;
	return (len_string);
}

/**
 * _strcmp - function that compares two strings
 * @s1: char of the first string to compare
 * @s2: char of the second string to compare
 * Return: 0 if both are equal, -1 if @s1 is < @s2
 *    or +1  @s1 is > @s2.
 */
int _strcmp(const char *s1, const char *s2)
{
	while (*s1 != '\0' && *s2 != '\0' && *s1 == *s2)
	{
		s1++;
		s2++;
	}

	if (*s1 != *s2)
		return (*s1 - *s2);

	return (0);
}

/**
 * _strncmp - specific lenght to compare 2 strings
 * @s1: 1st string to compare
 * @s2: 2nd string to compare
 * @k: extreme number of strings to compare
 *
 * Return: 0 if @s1 = "s2, -1 if @s1 is < s2 or + if @s1 is > @s2
 */
int _strncmp(const char *s1, const char *s2, size_t k)
{
	unsigned char b1, b2;

	while (k-- > 0)
	{
		b1 = (unsigned char) *s1++;
		b2 = (unsigned char) *s2++;

		if (b1 != b2)
			return (b1 - b2);
		if (b1 == '\0')
			break;
	}

	return (0);
}

/**
 * _strstr - checks if needle starts with haystack
 * @haystack: string to search
 * @pins: the substring to find
 *
 * Return: address of next char of haystack or NULL
 */
char *_strstr(char *haystack, char *pins)
{
	int i;

	for (i = 0; haystack[i] != '\0'; i++)
	{
		if (haystack[i] == pins[0])
		{
			int j;

			for (j = 0; pins[j] != '\0'; j++)
			{
				if (haystack[i + j] != pins[j])
				{
					break;
				}
			}

			if (pins[j] == '\0')
			{
				return (&haystack[i]);
			}
		}
	}
	return (NULL);
}

/**
 * _strchr - a function that locates a character in a string
 *
 * @s: pointer to our string array input
 * @c: character to locate from input array
 *
 * Return: first occurence of charatcer or null if not found
*/

char *_strchr(char *s, char c)
{
	int indent;

	for (indent = 0; s[indent]; indent++)
	{
		if (s[indent] == c)
			return (s + indent);
	}
	/*return null if missing*/
	return (NULL);
}
