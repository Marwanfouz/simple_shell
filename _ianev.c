#include "shell.h"

/**
 * _ianev - Initialize a new environment variable,
 *			 or modify an existing one
 * @info: Structure containing potential arguments. Used to maintain
 *		constant function prototype.
 *  Return: Always 0
 */
int _ianev(info_t *info)
{
	if (info->argc != 3)
	{
		_pais("Incorrect number of arguements\n");
		return (1);
	}
	if (_ianevo(info, info->argv[1], info->argv[2]))
		return (0);
	return (1);
}

/**
 * _ianevo - Initialize a new environment variable,
 *			 or modify an existing one
 * @info: Structure containing potential arguments. Used to maintain
 *		constant function prototype.
 * @var: the string env var property
 * @value: the string env var value
 *  Return: Always 0
 */
int _ianevo(info_t *info, char *var, char *value)
{
	char *buf = NULL;
	list_t *node;
	char *p;

	if (!var || !value)
		return (0);

	buf = malloc(_lens(var) + _lens(value) + 2);
	if (!buf)
		return (1);
	_cas(buf, var);
	_cts(buf, "=");
	_cts(buf, value);
	node = info->env;
	while (node)
	{
		p = swith(node->str, var);
		if (p && *p == '=')
		{
			free(node->str);
			node->str = buf;
			info->env_changed = 1;
			return (0);
		}
		node = node->next;
	}
	add_node_end(&(info->env), buf, 0);
	free(buf);
	info->env_changed = 1;
	return (0);
}
