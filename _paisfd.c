#include "shell.h"

/**
 *_paisfd - prints an input string
 * @str: the string to be printed
 * @fd: the file descriptor to write to
 *
 * Return: the number of chars put
 */
int _paisfd(char *str, int fd)
{
	int i = 0;

	if (!str)
		return (0);
	while (*str)
	{
		i += _wctgfd(*str++, fd);
	}
	return (i);
}
