#include "shell.h"

/**
 * simpleshell_tokenize - user inputs is parsed into arguments by array
 *            spliting into string tokens by the use of a delimiter
 * @str: string to tokenize.
 * @delim: splitting strings by the delimter
 *
 * Return: tokens from the array of pointers,
 *         or NULL on error.
 */
char **simpleshell_tokenize(char *str, const char *delim)
{
	char *token = NULL;
	char **reto = NULL;
	int i = 0;

	token = strtok(str, delim);
	while (token)
	{
		reto = realloc(reto, sizeof(char *) * (i + 1));
		if (reto == NULL)
			return (NULL);

		reto[i] = malloc(_strlen(token) + 1);
		if (!(reto[i]))
			return (NULL);

		_strcpy(reto[i], token);
		token = strtok(NULL, delim);
		i++;
	}
	/*increment of the size of the array*/
	reto = realloc(reto, (i + 1) * sizeof(char *));
	if (!reto)
		return (NULL);

	reto[i] = NULL;
	return (reto);
}

/**
 * simpleshell_tokenize_input - user input splitter of
 * string into tokens with function.
 * @inputs: input string of user to tokenize
 *
 * Return: tokens from the array of pointers, or NULL on an error
 */
char **simpleshell_tokenize_input(char *inputs)
{
	char **tokens = NULL;
	char *sel = NULL;

	sel = _strdup(inputs);
	if (sel == NULL)
	{
		_puts("Memory allocation encountered an error\n");
		exit(EXIT_FAILURE);
	}

	tokens = simpleshell_tokenize(sel, " \t\r\n\a");
	free(sel);

	return (tokens);
}
