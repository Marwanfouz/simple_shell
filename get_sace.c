#include "shell.h"

/**
 * get_sace - returns the string array copy of our environ
 * @info: Structure containing potential arguments. Used to maintain
 *		  constant function prototype.
 * Return: Always 0
 */
char **get_sace(info_t *info)
{
	if (!info->environ || info->env_changed)
	{
		info->environ = return_arrs(info->env);
		info->env_changed = 0;
	}

	return (info->environ);
}
