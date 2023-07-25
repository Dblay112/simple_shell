#include "shellheader.h"

/**
 * _printer - write characters to STDOUT
 * @str: string to be printed
 * Return: nothing
 */

void _printer(char *str)
{
	int len;

	if (!str)
	{
		return;
	}

	len = 0;
	while (str[len] != '\0')
	{
		len++;
	}

	write(1, str, len);
}
