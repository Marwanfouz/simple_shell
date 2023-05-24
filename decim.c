#include "shell.h"

/**
 * decim - function prints a decimal (integer) number (base 10)
 * @input: the input
 * @fd: the filedescriptor to write to
 *
 * Return: number of characters printed
 */
int decim(int input, int fd)
{
	int (*__wct_stdout)(char) = _wct_stdout;
	int i, count = 0;
	unsigned int _abs_, current;

	if (fd == STDERR_FILENO)
		__wct_stdout = _wctstderr;
	if (input < 0)
	{
		_abs_ = -input;
		__wct_stdout('-');
		count++;
	}
	else
		_abs_ = input;
	current = _abs_;
	for (i = 1000000000; i > 1; i /= 10)
	{
		if (_abs_ / i)
		{
			__wct_stdout('0' + current / i);
			count++;
		}
		current %= i;
	}
	__wct_stdout('0' + current);
	count++;

	return (count);
}
