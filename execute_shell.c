#include "shell.h"

/**
 * simpleshell_execute - argument commands are executed
 * @argv: array containing commands and its associated arguments
 *
 * Return: exit status of command executed
 */
int simpleshell_execute(char **argv)
{
	pid_t id;
	int statuses = 0;
	char *cmds_path, *envp[2];

	if (argv == NULL || *argv == NULL)
		return (statuses);
	if (simpleshell_builtin(argv))
		return (statuses);

	id = fork();
	if (id < 0)
	{
		_puterror("fork");
		return (1);
	}
	if (id == -1)
		perror(argv[0]), simpleshell_tokens(argv), simpleshell_last_input();
	if (id == 0)
	{
		envp[0] = simpleshell_getpath();
		envp[1] = NULL;
		cmds_path = NULL;
		if (argv[0][0] != '/')
			cmds_path = simpleshell_findpath(argv[0]);
		if (cmds_path == NULL)
			cmds_path = argv[0];
		if (execve(cmds_path, argv, envp) == -1)
		{
			perror(argv[0]), simpleshell_tokens(argv), simpleshell_last_input();
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		do {
			waitpid(id, &statuses, WUNTRACED);
		} while (!WIFEXITED(statuses) && !WIFSIGNALED(statuses));
	}
	return (statuses);
}
