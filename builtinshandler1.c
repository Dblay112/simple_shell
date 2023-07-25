#include "shellheader.h"

/**
 * shell_builtincd - function that handles changing the work env
 * @info: argument in the struct
 * Return: 1 when changed successfully and 0 on failure
 */

int shell_builtincd(info_t *info)
{
	char *s, *dir, buffer[1024];
	int chdir_ret;

	s = getcwd(buffer, 1024);
	if (!s)
	{
		perror("getcwd failure");
		return (1);
	}
	if (!info->argv[1])
	{
		dir = getshell_env("HOME");
		if (!dir)
			chdir_ret = chdir((dir = getshell_env("PWD")) ? dir : "/");
		else
			chdir_ret = chdir(dir);
	}
	else if (stringcompare(info->argv[1], "-") == 0)
	{
		if (!getshell_env("OLDPWD"))
		{
			_printer(s);
			_printer("\n");
			return (1);
		}
		_printer(getshell_env("OLDPWD"));
		_printer("\n");
		chdir_ret = chdir((dir = getshell_env("OLDPWD")) ? dir : "/");
	}
	else
		chdir_ret = chdir(info->argv[1]);
	if (chdir_ret == -1)
	{
		e_construct(info, "can't cd to ");
		write(2, info->argv[1], stringlength(info->argv[1]));
		write(2, "\n", 2);
	}
	else
		setenv("OLDPWD", getshell_env("PWD"), 1);
	return (0);
}

/**
 * memfill_shell - function to fill a block of memory
 * @s: pointer to the char to be filled
 * @b: the string to be filled
 * @n: the total memory byte size
 * Return: successful memory filled
 */

char *memfill_shell(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		*(s + i) = b;
	}
	return (s);
}
