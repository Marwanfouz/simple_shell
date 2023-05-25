#include "shell.h"

/**
 * fi_path - finds a command in PATH
 * @info: the parameter & return info struct
 *
 * Return: void
 */
void fi_cmd(info_t *info)
{
	char *path = NULL;
	int i, k;

	info->path = info->argv[0];
	if (info->linecount_flag == 1)
	{
		info->line_count++;
		info->linecount_flag = 0;
	}
	for (i = 0, k = 0; info->arg[i]; i++)
		if (!check_delim(info->arg[i], " \t\n"))
			k++;
	if (!k)
		return;

	path = fi_path(info, _get_voev(info, "PATH="), info->argv[0]);
	if (path)
	{
		info->path = path;
		fanetrcmd(info);
	}
	else
	{
		if ((get_interactive(info) || _get_voev(info, "PATH=")
			|| info->argv[0][0] == '/') && check_f(info, info->argv[0]))
			fanetrcmd(info);
		else if (*(info->arg) != '\n')
		{
			info->status = 127;
			err(info, "not found\n");
		}
	}
}
