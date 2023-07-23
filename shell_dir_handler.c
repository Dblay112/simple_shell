#include "shell.h"

/**
 * simpleshell_cd - swaps the current pwd of the shell
 * @args: arguments containing arrays
 *
 *Return : void
 */
void simpleshell_cd(char **args)
{
	char *dir = args[1];
	int reto;

	/* If no no command is entered, swap to HOME directory */
	if (dir == NULL)
	{
		dir = _getenv("HOME");
		if (dir == NULL)
		{
			_puts("cd: No HOME directory is available\n");
			return;
		}
	}

	reto = chdir(dir);
	if (reto == -1)
	{
		perror("cd");
	}
}
