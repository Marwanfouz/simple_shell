#include "shell.h"

/**
 * _pce - prints the current environment
 * @info: Structure containing potential arguments. Used to maintain
 *		  constant function prototype.
 * Return: Always 0
 */
int _pce(info_t *info)
{
	print_list_str(info->env);
	return (0);
}

/**
 * print_list_str - prints only the str element of a list_t linked list
 * @h: pointer to first node
 *
 * Return: size of list
 */
size_t print_list_str(const list_t *h)
{
	size_t i = 0;

	while (h)
	{
		_pis(h->str ? h->str : "(nil)");
		_pis("\n");
		h = h->next;
		i++;
	}
	return (i);
}

/**
 * env_list - populates env linked list
 * @info: Structure containing potential arguments. Used to maintain
 *		  constant function prototype.
 * Return: Always 0
 */
int env_list(info_t *info)
{
	list_t *node = NULL;
	size_t i;

	for (i = 0; environ[i]; i++)
		add_node_end(&node, environ[i], 0);
	info->env = node;
	return (0);
}
