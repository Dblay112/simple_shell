#include "shellheader.h"

/**
 * getshell_env - gets value of an environment variable
 * @variable: name of the environment variable
 * Return: value of the environment variable
 */

char *getshell_env(const char *variable)
{

	size_t var_length;
	char **env = environ;

	if (variable == NULL)
	{
		return (NULL);
	}

	var_length = stringlength(variable);

	while (*env != NULL)
	{
	if (stringcompare_n(variable, *env, var_length) == 0
		&& (*env)[var_length] == '=')
	{
		return (&((*env)[var_length + 1]));
	}
	env++;
	}

	return (NULL);
}
