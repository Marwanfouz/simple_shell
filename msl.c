#include "shell.h"

/**
 * msl - main shell loop
 * @info: the parameter & return info struct
 * @av: the argument vector from main()
 *
 * Return: 0 on success, 1 on error, or error code
 */
int msl(info_t *info, char **av)
{
	ssize_t r = 0;
	int builtin_ret = 0;

	while (r != -1 && builtin_ret != -2)
	{
		clear(info);
		if (get_interactive(info))
			_pis("$ ");
		_wctstderr(BUF_FLUSH);
		r = getin(info);
		if (r != -1)
		{
			sinfo(info, av);
			builtin_ret = builtin(info);
			if (builtin_ret == -1)
				fi_path(info);
		}
		else if (get_interactive(info))
			_wct_stdout('\n');
		freein(info, 0);
	}
	freein(info, 1);
	if (!get_interactive(info) && info->status)
		exit(info->status);
	if (builtin_ret == -2)
	{
		if (info->err_num == -1)
			exit(info->status);
		exit(info->err_num);
	}
	return (builtin_ret);
}
