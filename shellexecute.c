#include "shellheader.h"

/**
 * shellexec - function to execute commands from info struct
 * @info: struct parameter argument
 * Return: Nothing
 */

void shellexec(info_t *info)
{
	char *p = NULL;
	int r = 0, place = 0;

	while (info->arg[r])
	{
		place += !shell_lim(info->arg[r], " \t\n") ? 1 : 0;
		r++;
	}

	p = (!place) ? NULL : shellpath(info, getshell_env("PATH"), info->argv[0]);

	if (p)
	{
		info->path = p;
		executeshell_f(info);
	}
	else
	{
	if ((getshell_env("PATH") || info->argv[0][0] == '/')
			&& commandsearch(info, info->argv[0]))
		executeshell_f(info);
	else if (*(info->arg) != '\n')
		e_construct(info, "not found\n");
	}
}

/**
 * shellpath - finds path of the executed command
 * @info: a pointer to the struct info_t
 * @placestr: the directory strings are input
 * @cmd: executed command path
 * Return: the executed command
 */

char *shellpath(info_t *info, char *placestr, char *cmd)
{
	int r = 0, posi = 0;
	char *place;

	if (!placestr)
		return (NULL);
	else if ((stringlength(cmd) > 2) && findcharacter(cmd, "./"))
	{
		if (commandsearch(info, cmd))
			return (cmd);
		else
			return (NULL);
	}
	else
	{
	while (1)
	{
		if (!placestr[r] || placestr[r] == ':')
		{
			place = mul_strings(placestr, posi, r);
		if (!*place)
			appendstring(place, cmd);
		else
		{
			appendstring(place, "/");
			appendstring(place, cmd);
		}
		if (commandsearch(info, place))
			return (place);
		if (!placestr[r])
			break;
		posi = r;
		}
	r++;
	}
	return (NULL);
	}
}

/**
 * commandsearch - finds out if the input is a command or not
 * @info: a pointer to the struct info_t
 * @place: location of where the command is read
 * Return: 1 if successful or 0 on failure
 */

int commandsearch(info_t *info, char *place)
{
	struct stat st;

	(void)info;
	return ((!place || stat(place, &st)) ? 0 :
		(st.st_mode & S_IFREG) ? 1 :
		0);
}

/**
 * mul_strings - function that multiplies strings
 * @placestr: the directory strings are input
 * @start: string commencement
 * @stop: halting the string
 * Return: final string worked on
 */

char *mul_strings(char *placestr, int start, int stop)
{
	static char place[1024];
	int m = 0, u = 0;

	for (u = 0, m = start; m < stop; m++)
		(placestr[m] != ':') ? (place[u++] = placestr[m]) : 0;
	place[u] = 0;
	return (place);
}
