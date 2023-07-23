#include "shell.h"

/**
 * handles_sigint - handler for signals func(Ctrl+C)
 * @sigs: Signal number of func
 *
 * Return: Nothing
 */
void handles_sigint(int sigs)
{
	(void) sigs;
	_putchar('\n');
	simpleshell_prompt();
}

/**
 * handles_sigquit - handler for signals func (Ctrl+\)
 * @sigs: Signal number of func
 *
 * Return: nothing
 */
void handles_sigquit(int sigs)
{
	(void) sigs;
	_puterror("Quit (core dumped)\n");
	exit(EXIT_SUCCESS);
}

/**
 * handles_sigstp - handler for (Ctrl+Z) signal
 * @sigs: Signal number of func
 *
 * Return: Nothing
 */
void handles_sigstp(int sigs)
{
	(void) sigs;
	_puts("\n");
	simpleshell_prompt();
}
