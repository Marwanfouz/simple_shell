#include "shell.h"

/**
 * err - prints an error message
 * @info: the parameter & return info struct
 * @estr: string containing specified error type
 * Return: 0 if no numbers in string, converted number otherwise
 *		-1 on error
 */
void err(info_t *info, char *estr)
{
	_pais(info->fname);
	_pais(": ");
	decim(info->line_count, STDERR_FILENO);
	_pais(": ");
	_pais(info->argv[0]);
	_pais(": ");
	_pais(estr);
}
