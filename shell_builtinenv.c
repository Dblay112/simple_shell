#include "shell.h"

/**
 * simpleshell_env - all the environment variables print.
 *
 * Return: void.
 */
int simpleshell_env(void)
{
	int z;

	for (z = 0; environ[z]; z++)
	{
		_puts(environ[z]);
		_putchar('\n');
	}

	return (0);
}
