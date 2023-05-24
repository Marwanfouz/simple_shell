#include "shell.h"

/**
 * r_var - replaces vars in the tokenized string
 * @info: the parameter struct
 *
 * Return: 1 if replaced, 0 otherwise
 */
int r_var(info_t *info)
{
	int i = 0;
	list_t *node;

	for (i = 0; info->argv[i]; i++)
	{
		if (info->argv[i][0] != '$' || !info->argv[i][1])
			continue;

		if (!_plcots(info->argv[i], "$?"))
		{
			rstring(&(info->argv[i]),
					_das(_cnts(info->status, 10, 0)));
			continue;
		}
		if (!_plcots(info->argv[i], "$$"))
		{
			rstring(&(info->argv[i]),
					_das(_cnts(getpid(), 10, 0)));
			continue;
		}
		node = node_swith(info->env, &info->argv[i][1], '=');
		if (node)
		{
			rstring(&(info->argv[i]),
					_das(_lacis(node->str, '=') + 1));
			continue;
		}
		rstring(&info->argv[i], _das(""));
	}
	return (0);
}
