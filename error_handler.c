#include "shell.h"

/**
 * _puts - function to print a string to the STDOUT
 * @string: the string to be printed
 *
 * Return: void
 */
void _puts(char *string)
{
	size_t lens;
	ssize_t val_written;

	lens = _strlen(string);
	val_written = write(STDOUT_FILENO, string, lens);
	if (val_written == -1)
	{
		perror("write");
	}
}

/**
 * _puterror - function to print a string to the STDOUT
 * @brr: error message to be printed
 *
 * Return: void
 */
void _puterror(char *brr)
{
	size_t lens;
	ssize_t val_written;

	lens = _strlen(brr);
	val_written = write(STDERR_FILENO, brr, lens);
	if (val_written == -1)
	{
		perror("write");
	}
}
