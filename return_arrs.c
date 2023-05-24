#include "shell.h"

/**
 * return_arrs - returns an array of strings of the list->str
 * @head: pointer to first node
 *
 * Return: array of strings
 */
char **return_arrs(list_t *head)
{
	list_t *node = head;
	size_t i = len_lis(head), j;
	char **strs;
	char *str;

	if (!head || !i)
		return (NULL);
	strs = malloc(sizeof(char *) * (i + 1));
	if (!strs)
		return (NULL);
	for (i = 0; node; node = node->next, i++)
	{
		str = malloc(_lens(node->str) + 1);
		if (!str)
		{
			for (j = 0; j < i; j++)
				free(strs[j]);
			free(strs);
			return (NULL);
		}

		str = _cas(str, node->str);
		strs[i] = str;
	}
	strs[i] = NULL;
	return (strs);
}
