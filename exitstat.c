#include "shellheader.h"

/**
 * ssfree - frees memory allocated in the struct
 * @info: struct parameter argument
 * @exit_status: represents the exit status
 * Return: void
 */

void ssfree(info_t *info, int exit_status)
{
	if (info != NULL)
	{
		free(info->path);
		free(info->argv);
	}
	exit(exit_status);
}
