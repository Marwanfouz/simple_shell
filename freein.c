#include "shell.h"

/**
 * freein - frees info_t struct fields
 * @info: struct address
 * @all: true if freeing all fields
 */
void freein(info_t *info, int all)
{
	freesl(info->argv);
	info->argv = NULL;
	info->path = NULL;
	if (all)
	{
		if (!info->cmd_buf)
			free(info->arg);
		if (info->env)
			freelis(&(info->env));
		if (info->alias)
			freelis(&(info->alias));
		freesl(info->environ);
		info->environ = NULL;
		_free_pan((void **)info->cmd_buf);
		if (info->readfd > 2)
			close(info->readfd);
		_wct_stdout(BUF_FLUSH);
	}
}
