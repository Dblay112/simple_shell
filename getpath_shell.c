#include "shell.h"

/**
 * simpleshell_getpath - function for the the PATH variable value
 *
 * Return: $PATH value pointer
 */
char *simpleshell_getpath(void)
{
	return (_getenv("PATH"));
}
