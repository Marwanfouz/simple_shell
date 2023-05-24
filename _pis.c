#include "shell.h"

/**
 *_pis - prints an input string
 *@str: the string to be printed
 *
 * Return: Nothing
 */
void _pis(char *str)
{
	int i = 0;

	if (!str)
		return;
	while (str[i] != '\0')
	{
		_wct_stdout(str[i]);
		i++;
	}
}
