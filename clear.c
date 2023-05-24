#include "shell.h"

/**
 * clear - initializes info_t struct
 * @info: struct address
 */
void clear(info_t *info)
{
	info->arg = NULL;
	info->argv = NULL;
	info->path = NULL;
	info->argc = 0;
}
