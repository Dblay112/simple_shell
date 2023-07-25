#include "shellheader.h"

/**
 * allenv_shell - function that allows access to the env var in the shell.
 * Return: environment variables
 */

char **allenv_shell(void)
{
	return (environ);
}
