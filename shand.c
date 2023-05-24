#include "shell.h"

/**
 * shand - blocks ctrl-C
 * @sig_num: the signal number
 *
 * Return: void
 */
void shand(__attribute__((unused)) int sig_num)
{
	_pis("\n");
	_pis("$ ");
	_wct_stdout(BUF_FLUSH);
}
