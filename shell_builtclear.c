#include "shell.h"

/**
 * simpleshell_clear - wipes terminal screen clear
 * @args: array containing arguments
 *
 * Return: 1 for successful executing or,
 *        0 exit.
*/
int simpleshell_clear(char **args)
{
	(void)args; /* eliminates "an unsued parameter" prompts */
	_puts("\033[2J\033[H");
	return (1);
}
