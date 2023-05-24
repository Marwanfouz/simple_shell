#include "shell.h"

/**
 * getin - gets a line minus the newline
 * @info: parameter struct
 *
 * Return: bytes read
 */
ssize_t getin(info_t *info)
{
	static char *buf; /* the ';' command chain buffer */
	static size_t i, j, len;
	ssize_t r = 0;
	char **buf_p = &(info->arg), *p;

	_wct_stdout(BUF_FLUSH);
	r = bufferin(info, &buf, &len);
	if (r == -1) /* EOF */
		return (-1);
	if (len) /* we have commands left in the chain buffer */
	{
		j = i;		 /* init new iterator to current buf position */
		p = buf + i; /* get pointer for return */

		ch_next(info, buf, &j, i, len);
		while (j < len) /* iterate to semicolon or end */
		{
			if (test_chain_delim(info, buf, &j))
				break;
			j++;
		}

		i = j + 1;	  /* increment past nulled ';'' */
		if (i >= len) /* reached end of buffer? */
		{
			i = len = 0; /* reset position and length */
			info->cmd_buf_type = NORM;
		}

		*buf_p = p;		   /* pass back pointer to current command position */
		return (_lens(p)); /* return length of current command */
	}

	*buf_p = buf; /* else not a chain, pass back buffer from _getnloi() */
	return (r);	  /* return length of buffer from _getnloi() */
}
