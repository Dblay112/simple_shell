#include "shellheader.h"

/**
 * loopshellmain - function that applies the concept of basic shell loop
 * @explainer: handles a file openings or not
 * @argc: handles argument count
 * @argv: argument vectorss
 * @line: line to be read in the shell
 * @line_length: length of line to be read
 * @file: a property file in the struct
 * @info: struct parameter argument
 * @built_in_ret: status of execution is returned
 * Return: 0 when successful and 0 on error
 */

int loopshellmain(int explainer, int argc, char **argv, char *line,
		size_t line_length, ownership file, info_t info,
		int built_in_ret)
{
	while (1)
	{
		info.show++;
		if (file.explainer != 0 && file.show_flag == 0)
			mimic_buffile(file, line, line_length);
		else
		{
			if (isatty(STDIN_FILENO))
				shell_printer();
			fflush(stdout);
			if (bufferfile_handler(&line, &line_length, 0) == -1)
			{
				if (explainer != 0)
					close(explainer);
				return (0);
			}
			ini_builtin(&info, argc, argv, line);
			if (line_length > 0)
			{
				built_in_ret = findbuiltin_shell(&info);
				if (built_in_ret == -2)
					break;
				else if (built_in_ret == -1)
				{
					info.path = info.argv[0];
					shellexec(&info);
				}
			}
		}
		shell_freedom(&info, line);
	}
	if (explainer != 0)
		close(explainer);
	return (0);
}

/**
 * mimic_buffile - reads lines from a file in a custorm func
 * @file: data structure representing a filer
 * @line: pointer to char buffer to store lines read
 * @line_length: length of line buffer
 * Return: void
 */

void mimic_buffile(ownership file, char *line, size_t line_length)
{
	while (bufferfile_handler(&line, &line_length, file.explainer) != -1)
	{
		if (line_length > 0)
		{
			free(line);
		}
		else
		{
			break;
		}
	}
	file.show_flag = 1;
}

/**
 * ini_builtin - initializes members of the struct
 * @info: a pointer to the struct info_t
 * @argc: an integer representing command-line arguments
 * @argv: array of strings of the command-line arguments
 * @line:  pointer to the character array (string).
 * Return: Nothin
 */

void ini_builtin(info_t *info, int argc, char **argv, char *line)
{
			info->path = line;
			info->argv = NULL;
			info->pipefd[0] = -1;
			info->pipefd[1] = -1;
			info->report = -1;
			info->lrf_fd = -1;
			info->argc = argc;
			info->arg = stringduplicate(line);
			info->argv = NULL;
			info->shell = argv[0];
			stringsplit(info);
}

/**
 * shell_freedom - function that frees all alllocated memory
 * @info: a pointer to the struct info_t
 * @line: pointer to the character array (string)
 * Return: NOTHING
 */

void shell_freedom(info_t *info, char *line)
{
	int i;

		if (line != NULL)
		{
			free(line);
			line = NULL;
		}
		if (info->arg != NULL)
		{
			free(info->arg);
			info->arg = NULL;
		}
		if (info->argv != NULL)
		{
			for (i = 0; info->argv[i]; i++)
				free(info->argv[i]);
			free(info->argv);
			info->argv = NULL;
		}
}
