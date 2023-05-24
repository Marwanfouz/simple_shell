#include "shell.h"

/**
 * _lens - returns the length of a string
 * @s: the string whose length to check
 *
 * Return: integer length of string
 */
int _lens(char *s)
{
	int j = 0;

	if (!s)
		return (0);

	while (*s++)
		j++;
	return (j);
}
