#include "shell.h"

/**
 * fi_path - finds this cmd in the PATH string
 * @info: the info struct
 * @pathstr: the PATH string
 * @cmd: the cmd to find
 *
 * Return: full path of cmd if found or NULL
 */
char *fi_path(info_t *info, char *pathstr, char *cmd)
{
	int i = 0, curr_pos = 0;
	char *path;

	if (!pathstr)
		return (NULL);
	if ((_lens(cmd) > 2) && swith(cmd, "./"))
	{
		if (check_f(info, cmd))
			return (cmd);
	}
	while (1)
	{
		if (!pathstr[i] || pathstr[i] == ':')
		{
			path = du_chars(pathstr, curr_pos, i);
			if (!*path)
				_cts(path, cmd);
			else
			{
				_cts(path, "/");
				_cts(path, cmd);
			}
			if (check_f(info, path))
				return (path);
			if (!pathstr[i])
				break;
			curr_pos = i;
		}
		i++;
	}
	return (NULL);
}
