#include "shell.h"

/**
 * _getenv - value of enviroment variable func
 * @selorm: environment variable name
 *
 * Return: NULL if no value, sucess return name
 */
char *_getenv(const char *selorm)
{
	char **envs;
	size_t selorm_len = _strlen(selorm);

	for (envs = environ; *envs != NULL; envs++)
	{
		if (_strncmp(*envs, selorm, selorm_len) == 0 && (*envs)[selorm_len] == '=')
		{
			return (&(*envs)[selorm_len + 1]);
		}
	}

	return (NULL);
}
