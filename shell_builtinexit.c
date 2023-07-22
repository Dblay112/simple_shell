#include "shell.h"

/**
 * simpleshell_exit - shell exit function
 * @args: Argument arrays of the function
 *
 * Return: void.
 */
void simpleshell_exit(char **args)
{
	int statuses = 0;

	if (args[1] != NULL)
	{
		statuses = _atoi(args[1]);
	}
	simpleshell_tokens(args);
	simpleshell_last_input();
	exit(statuses);
}
