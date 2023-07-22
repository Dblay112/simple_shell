#include "shell.h"

/**
 * simpleshell_setenv - environment variable value is set func
 * @args: Arguments containing name and value of the variable
 *
 * Return: void
 */
int simpleshell_setenv(char **args)
{
	char *selorm, *values;

	if (args[1] == NULL || args[2] == NULL)
	{
		_puterror("Usage: setenv's VARIABLE VALUE\n");
		return (-1);
	}

	selorm = args[1];
	values = args[2];

	if (setenv(selorm, values, 1) != 0)
	{
		_puterror("setenv");
		return (-1);
	}
	return (0);
}

/**
 * simpleshell_unsetenv - Unset an environment variable
 * @args: Arguments containing name and value of the var
 *
 * Return: void
 */
int simpleshell_unsetenv(char **args)
{
	char *selorm;

	if (args[1] == NULL)
	{
		_puterror("Usage: unsetenv's VARIABLE\n");
		return (-1);
	}

	selorm = args[1];

	if (unsetenv(selorm) != 0)
	{
		_puterror("unsetenv");
	}
	return (0);
}
