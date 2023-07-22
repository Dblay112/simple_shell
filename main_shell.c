#include "shell.h"

/**
 * main - entry program for our simple shell
 *
 * Return: EXIT SUCCESS when successful.
 */
int main(void)
{
	char *inputs;
	char **args;
	int status_level;

	/* signal handlers register arguments */
	signal(SIGINT, handles_sigint);
	signal(SIGQUIT, handles_sigquit);
	signal(SIGTSTP, handles_sigstp);

	do {
		inputs = simpleshell_input();
		if (!inputs || !*inputs)/* exit the loop on EOF detection */
			break;

		args = simpleshell_tokenize_input(inputs);
		if (!args || !*args)
		{
			free(inputs);
			simpleshell_tokens(args);
			continue;
		}
		status_level = simpleshell_execute(args);
		free(inputs);
		simpleshell_tokens(args);

		/* to continue the loop, status should be set to 1 */
		status_level = 1;
	} while (status_level);

	return (EXIT_SUCCESS);
}
