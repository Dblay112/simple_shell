#include "shell.h"

/**
 * simpleshell_free_error - allocated pointers are freed ff error in systems
 * @argv: argument vector count of arrays
 * @arg: argument counts of arrays
 *
 * Return: void.
 */
void simpleshell_free_error(char **argv, char *arg)
{
	int z;

	for (z = 0; argv[z]; z++)
		free(argv[z]);
	free(argv);
	free(arg);
	exit(EXIT_FAILURE);
}

/**
 * simpleshell_tokens - frees memory allocated dynamically by tokenize()
 * @ptr: pointer to allocated memory
 *
 * Return: void.
 */
void simpleshell_tokens(char **ptr)
{
	int z;

	for (z = 0; ptr[z]; z++)
		free((ptr[z]));
	free(ptr);
}


/**
 * simpleshell_freepath - global variable is freed in the PATH environ
 *              variable value
 *
 * Return: void
 */
void simpleshell_freepath(void)
{
	if (environ != NULL)
	{
		size_t z = 0;

		while (environ[z] != NULL)
		{
			if (_strncmp(environ[z], "PATH=", 5) == 0)
			{
				free(environ[z]);
				environ[z] = NULL;
				break;
			}
			z++;
		}
	}
}
