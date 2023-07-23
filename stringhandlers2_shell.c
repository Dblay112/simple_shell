#include "shell.h"

/**
 * _atoi - function to convert a string to an integer
 * @string: string to be converted
 *
 * Return: value of the string integer
 */
int _atoi(const char *string)
{
	int z, symbol;
	unsigned int val;

	z = 0;
	symbol = 1;
	val = 0;

	while (string[z] != '\0')
	{
		if (string[z] == '-')
			symbol *= -1;
		else if (string[z] >= '0' && string[z] <= '9')
			val = (val * 10) + (string[z] - '0');
		else
			break;
		z++;
	}
	return (val * symbol);
}

/**
 **_memset - memory with constant byte to be filled
 *@s: pointer of the memory area
 *@b: pointer to be filled with the byte
 *@m: bytes to be filled amount
 *Return: a poointer of the memory area
 */
char *_memset(char *s, char b, unsigned int m)
{
	unsigned int z;

	for (z = 0; z < m; z++)
		s[z] = b;
	return (s);
}

/**
 * _memcpy - function that copies memory area
 *
 * @dest: wherre it will be copied to buffer
 * @src: source of what to be copied
 * @b: b bytes of @src in the function
 *
 * Return: always 0 if successful
*/

char *_memcpy(char *dest, char *src, unsigned int b)
{
	unsigned int z;

	for (z = 0; z < b; z++)
		dest[z] = src[z];
	return (dest);
}

/**
 * _realloc - block memory reallocater
 * @ptr: previous mallocated block pointer
 * @old_value: previous block bytes size
 * @new_value: new block bytes size
 *
 * Return: old block pointer name
 */
void *_realloc(void *ptr, unsigned int old_value, unsigned int new_value)
{
	char *q;

	if (!ptr)
		return (malloc(new_value));
	if (!new_value)
		return (free(ptr), NULL);
	if (new_value == old_value)
		return (ptr);

	q = malloc(new_value);
	if (!q)
		return (NULL);

	old_value = old_value < new_value ? old_value : new_value;
	while (old_value--)
		q[old_value] = ((char *)ptr)[old_value];
	free(ptr);
	return (q);
}

/**
 * _calloc - allocates the requested memory
 *
 * @member: array size in func
 * @size: each element size in func
 *
 * Return: new allocated point, NULL if failure
*/

void *_calloc(unsigned int member, unsigned int size)
{
	char *q;

	if (member == 0 || size == 0)
		return (NULL);

	q = malloc(member * size);
	if (q == NULL)
		return (NULL);

	_memset(q, 0, member * size);

	return (q);
}
