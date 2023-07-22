#include "shell.h"

/**
 * simpleshell_help - shows help info for the built-in commands
 */
void simpleshell_help(void)
{
	_puts("\nShell Version 1.1.1\n\n");
	_puts("Usage: ./myhsh\n\n");
	_puts("Shell built-in command:\n\n");
	_puts("help\t\tDisplay help information\n\n");
	_puts("cd [dir]\tChange the current  directory\n\n");
	_puts("env\t\tDisplay all environment variables\n\n");
	_puts("setenv\t\tSet to an environment variable\n\n");
	_puts("unsetenv\tUnset to an environment variable\n\n");
	_puts("exit\t\tExits the shell\n\n");
}
