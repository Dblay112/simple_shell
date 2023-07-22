#include "shell.h"

/**
 * simpleshell_prompt - shell prompt printer to STDIN stream
 *
 * Return: void.
 */
void simpleshell_prompt(void)
{
	_puts(PROMPT_SIGN);
	fflush(stdout);
}
