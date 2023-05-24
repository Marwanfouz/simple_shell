#include "shell.h"

/**
 * get_interactive - returns true if shell is get_interactive mode
 * @info: struct address
 *
 * Return: 1 if get_interactive mode, 0 otherwise
 */
int get_interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}
