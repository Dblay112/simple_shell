#include "shell.h"

/**
 * simpleshell_builtin - finds out if the command entered is a builtin
 * @args: arguments containing the arrays
 *
 * Return: 1 if command is a builtin, 0 if it is not
 */
int simpleshell_builtin(char **args)
{
	if (!args[0])
		return (0);
	if (!_strcmp(args[0], "exit"))
		simpleshell_exit(args);
	else if (!_strcmp(args[0], "env"))
		simpleshell_env();
	else if (!_strcmp(args[0], "setenv"))
		simpleshell_setenv(args);
	else if (!_strcmp(args[0], "unsetenv"))
		simpleshell_unsetenv(args);
	else if (!_strcmp(args[0], "help"))
		simpleshell_help();
	else if (!_strcmp(args[0], "cd"))
		simpleshell_cd(args);
	else if (!_strcmp(args[0], "clear"))
		simpleshell_clear(args);
	else
		return (0);
	return (1);
}
