#include "shell.h"

/**
 * s_alis - sets alias to string
 * @info: parameter struct
 * @str: the string alias
 *
 * Return: Always 0 on success, 1 on error
 */
int s_alis(info_t *info, char *str)
{
	char *p, c;
	int ret;

	p = _lacis(str, '=');
	if (!p)
		return (1);
	c = *p;
	*p = 0;
	ret = delete_node_at_index(&(info->alias),
							   get_node_index(info->alias, node_swith(info->alias, str, -1)));
	*p = c;
	return (ret);
}

/**
 * st_alis - sets alias to string
 * @info: parameter struct
 * @str: the string alias
 *
 * Return: Always 0 on success, 1 on error
 */
int st_alis(info_t *info, char *str)
{
	char *p;

	p = _lacis(str, '=');
	if (!p)
		return (1);
	if (!*++p)
		return (s_alis(info, str));

	s_alis(info, str);
	return (add_node_end(&(info->alias), str, 0) == NULL);
}

/**
 * pr_alias - prints an alias string
 * @node: the alias node
 *
 * Return: Always 0 on success, 1 on error
 */
int pr_alias(list_t *node)
{
	char *p = NULL, *a = NULL;

	if (node)
	{
		p = _lacis(node->str, '=');
		for (a = node->str; a <= p; a++)
			_wct_stdout(*a);
		_wct_stdout('\'');
		_pis(p + 1);
		_pis("'\n");
		return (0);
	}
	return (1);
}

/**
 * _m_alias - mimics the alias builtin (man alias)
 * @info: Structure containing potential arguments. Used to maintain
 *		  constant function prototype.
 *  Return: Always 0
 */
int _m_alias(info_t *info)
{
	int i = 0;
	char *p = NULL;
	list_t *node = NULL;

	if (info->argc == 1)
	{
		node = info->alias;
		while (node)
		{
			pr_alias(node);
			node = node->next;
		}
		return (0);
	}
	for (i = 1; info->argv[i]; i++)
	{
		p = _lacis(info->argv[i], '=');
		if (p)
			st_alis(info, info->argv[i]);
		else
			pr_alias(node_swith(info->alias, info->argv[i], '='));
	}

	return (0);
}

/**
 * r_alias - replaces an aliases in the tokenized string
 * @info: the parameter struct
 *
 * Return: 1 if replaced, 0 otherwise
 */
int r_alias(info_t *info)
{
	int i;
	list_t *node;
	char *p;

	for (i = 0; i < 10; i++)
	{
		node = node_swith(info->alias, info->argv[0], '=');
		if (!node)
			return (0);
		free(info->argv[0]);
		p = _lacis(node->str, '=');
		if (!p)
			return (0);
		p = _das(p + 1);
		if (!p)
			return (0);
		info->argv[0] = p;
	}
	return (1);
}
