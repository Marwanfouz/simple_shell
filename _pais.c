#include "shell.h"

/**
 *_pais - prints an input string
 * @str: the string to be printed
 *
 * Return: Nothing
 */
void _pais(char *str)
{
	int i = 0;

	if (!str)
		return;
	while (str[i] != '\0')
	{
		_wctstderr(str[i]);
		i++;
	}
}
