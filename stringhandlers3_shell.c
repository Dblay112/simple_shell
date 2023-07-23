#include "shell.h"

/**
 * _strcpy - funcrion tthat copies a string
 * @src: the source in the string function
 *@dest: the destination in the function
 *
 * Return: pointer to destination in func
 */
char *_strcpy(char *dest, char *src)
{
	int z = 0;

	if (dest == src || src == 0)
		return (dest);
	while (src[z])
	{
		dest[z] = src[z];
		z++;
	}
	dest[z] = 0;
	return (dest);
}

/**
 * _strcat - concatenates two strings function
 * @src: the source buffer in the function
 * @dest: the destination buffer in the function
 *
 * Return: pointer to destination buffer function
 */
char *_strcat(char *dest, const char *src)
{
	char *reto = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = *src;
	return (reto);
}

/**
 * _strdup - function that duplicates a string
 * @string: the string to duplicate in the function
 *
 * Return: duplicated string pointer
 */
char *_strdup(const char *string)
{
	int lens = 0;
	char *reto;

	if (string == NULL)
		return (NULL);
	while (*string++)
		lens++;
	reto = malloc(sizeof(char) * (lens + 1));
	if (!reto)
		return (NULL);
	for (lens++; lens--;)
		reto[lens] = *--string;
	return (reto);
}

/**
 *_putchar - function that writes the character c to stdout
 * @c: the char to be printed
 *
 * Return: when successful return 1 if not -1
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _strspn - function to get the lenght of a substring
 *
 * @substring: substring prefix to search
 * @s: string input pointer
 * Return: no of bytes in the first segment
 */
unsigned int _strspn(char *s, char *substring)
{
	unsigned int z, y;

	for (z = 0; s[z]; z++)
	{
		for (y = 0; substring[y]; y++)
		{
			if (s[z] == substring[y])
				break;
		}
		if (!substring[y])
			return (z);
	}

	return (z);
}
