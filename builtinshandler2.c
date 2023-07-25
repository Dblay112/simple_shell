#include "shellheader.h"

/**
 * findbuiltin_shell - identify/execute built-in commands in our shell program
 * @info: the info parameter in struct
 * Return: 1 on success and 0 on failure
 */

int findbuiltin_shell(info_t *info)
{
	int i, built_in_ret = -1;
	builtin_board builtintbl[] = {
		{"exit", exitbuiltin_shell},
		{"env", custom_env},
		{"cd", shell_builtincd},
		{"setenv", oldsetenv_shell},
		{"unsetenv", oldunsetenv_shell},
		{"alias", oldunsetenv_shell},
		{NULL, NULL}
	};

	for (i = 0; builtintbl[i].type; i++)
	{
		if (stringcompare(info->argv[0], builtintbl[i].type) == 0)
		{
			built_in_ret = builtintbl[i].func(info);
			break;
		}
	}

	return (built_in_ret);
}
