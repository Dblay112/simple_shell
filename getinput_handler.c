#include "shell.h"

static char *last_input;
/**
 * simpleshell_input - input line reading from the user
 *
 * Return: user input of buffer pointer.
*/
char *simpleshell_input(void)
{
	char *inputs = NULL;
	size_t input_sizet = 0;
	ssize_t reader;

	do {
		/* shell prompt printer */
		simpleshell_prompt();

		/* user inputs a line command */
		reader = getline(&inputs, &input_sizet, stdin);

		/* EOF checker or  error */
		if (reader == -1)
		{
			free(inputs);
			_puts("\n");
			return (NULL);
		}

		/* eliminates newline trailing char */
		inputs[reader - 1] = '\0';

	} while (inputs[0] == '\0' || isspace(inputs[0]));

	/* moves last input to new input */
	last_input = inputs;
	return (inputs);
}

/**
 * simpleshell_last_input - user entered recent input is freed function
 *
 * allocated memory is freed for most of the recent string input
 * string input by user no longer needed is called
 * Return : void
*/
void simpleshell_last_input(void)
{
	free(last_input);
	last_input = NULL;
}


