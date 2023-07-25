#include "shellheader.h"

/**
 * stringsplit - function that splits strings
 * @info: a pointer to the struct info_t
 * Return: 1 on success and 0 on failure
 */

int stringsplit(info_t *info)
{
	int i;
	(*info).argv = mimic_strtokd((*info).arg, " \t");
		if (!(*info).argv)
		{
			(*info).argv = malloc(sizeof(char *) * 2);
			if ((*info).argv)
			{
				(*info).argv[0] = stringduplicate((*info).arg);
				(*info).argv[1] = NULL;

			}
		}
		for (i = 0; (*info).argv && (*info).argv[i]; i++)
			;
		(*info).argc = i;
		return (i);
}

/**
 * mimic_strtokd - mimics the behaviour of strtok c libraty
 * @inputString: the strings to be inputted
 * @delimiters: delimits the strings in the function
 * Return: pointer to the result string
 */

char **mimic_strtokd(char *inputString, char *delimiters)
{
	int index1, index2, index3, index4, numWords = 0;
	char **result;
	int i;

	if (inputString == NULL || inputString[0] == 0)
		return (NULL);
	if (!delimiters)
		delimiters = " ";
	for (index1 = 0; inputString[index1] != '\0'; index1++)
		if (!shell_lim(inputString[index1], delimiters)
				&& (shell_lim(inputString[index1 + 1], delimiters)
					|| !inputString[index1 + 1]))
		numWords++;
	if (numWords == 0)
		return (NULL);
	result = malloc((1 + numWords) * sizeof(char *));
	if (!result)
		return (NULL);
	for (index2 = 0, index3 = 0; index3 < numWords; index3++)
	{
		while (shell_lim(inputString[index2], delimiters))
		index2++;
		index4 = 0;
		while (!shell_lim(inputString[index2 + index4], delimiters)
				&& inputString[index2 + index4])
			index4++;
		result[index3] = malloc((index4 + 1) * sizeof(char));
	if (!result[index3])
	{
		for (index4 = 0; index4 < index3; index4++)
			free(result[index4]);
		free(result);
		return (NULL);
	}
	for (i = 0; i < index4; i++)
		result[index3][i] = inputString[index2++];
	result[index3][index4] = 0;
	}
	result[index3] = NULL;
	return (result);
}

/**
 * shell_lim - determines whether char is a delimiter or not
 * @c: character to check
 * @delim: delimiting string
 * Return: 1 when successful and 0 on failure
 */

int shell_lim(char c, char *delim)
{
	int i = 0;

	while (delim[i] != '\0')
	{
	if (delim[i] == c)
		return (1);
	i++;
	}
	return (0);
}
