#include "shellheader.h"

/**
 * main - main entry that takes command-line arguments
 * @argc: argument number count
 * @argv: argument number value
 *
 * Return: 1 on success and 0 on failure
 */

int main(int argc, char *argv[])
{
	int descriptor;
	int result;
	char *line;
	size_t line_length;
	ownership file;
	info_t info;
	int built_in_ret;

	line = NULL;
	info.show = 0;
	file.show_flag = 0;
	descriptor = 0;
	line_length = 0;
	built_in_ret = 0;

	if (argc > 1)
	{
		descriptor = open(argv[1], O_RDONLY);
		if (descriptor < 0)
		{
			perror(argv[1]);
			return (1);
		}
	}

	file.explainer = descriptor;
	signal(SIGINT, controlC);
	result = loopshellmain(descriptor, argc, argv, line, line_length,
			file, info, built_in_ret);
	return (result);
}

/**
 * controlC - blocks ctrl-C and avoid compiler warning
 * @thisway: signal number in the function
 *
 * Return: Nothing
 */
void controlC(int thisway)
{
	(void)thisway;
	_printer("\n");
	shell_printer();
}
