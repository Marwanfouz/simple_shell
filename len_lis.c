#include "shell.h"

/**
 * len_lis - determines length of linked list
 * @h: pointer to first node
 *
 * Return: size of list
 */
size_t len_lis(const list_t *h)
{
	size_t i = 0;

	while (h)
	{
		h = h->next;
		i++;
	}
	return (i);
}
