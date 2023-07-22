#include "shell.h"

/**
 * simpleshell_findpath - finds a command in each dir the PATH
 *                environment variable
 * @bright: command string to find
 *
 * Return: pointer string to path. success if found
 *         NULL if failure.
*/
char *simpleshell_findpath(char *bright)
{
	struct stat str;
	int stat_reto, i;
	char buf[MAXIMUM_PATH_LENGTH], *path, *reto, **dir;

	path = simpleshell_getpath();
	if (!path)
		return (NULL);
	dir = simpleshell_tokenize(path, SEPARATER_PATH);
	if (!dir)
		return (NULL);
	for (i = 0; dir[i]; i++)
	{
		_memset(buf, 0, MAXIMUM_PATH_LENGTH);
		_strcpy(buf, dir[i]);
		_strcat(buf, "/");
		_strcat(buf, bright);
		stat_reto = stat(buf, &str);
		if (stat_reto == 0 && S_ISREG(str.st_mode) && (str.st_mode & S_IXUSR))
		{
			simpleshell_tokens(dir);
			reto = malloc(sizeof(char) * (strlen(buf) + 1));
			if (!reto)
				return (NULL);
			strcpy(reto, buf);
			return (reto);
		}
	}
	if (stat_reto == -1)
		simpleshell_tokens(dir);
	return (NULL);
}
