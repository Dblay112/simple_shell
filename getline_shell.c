#include "shell.h"


/**
 * simpleshell_getline - standard input reader
 *
 * Return: user entered string
*/
void *simpleshell_getline(void)
{
	static char buffer[SIZE_OF_BUFFER];
	static int buf_post, buf_size;
	char *input_string = NULL;
	char current_chars;
	int input_lens = 0;

	while (1)
	{
		if (buf_post >= buf_size)
		{
			buf_size = read(STDIN_FILENO, buffer, SIZE_OF_BUFFER);
			buf_post = 0;
			if (buf_size == 0)
				return (input_string);
			else if (buf_size < 0)
			{
				perror("read");
				return (NULL);
			}
		}

		current_chars = buffer[buf_post];

		buf_post++;

		if (current_chars == '\n')
		{
			input_string = realloc(input_string, input_lens + 1);
			input_string[input_lens] = '\0';
			return (input_string);
		}
		else
		{
			input_string = realloc(input_string, input_lens + 1);
			input_string[input_lens] = current_chars;
			input_lens++;
		}
	}
}
