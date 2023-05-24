#include "shell.h"

/**
 * rbuffer - reads a buffer
 * @info: parameter struct
 * @buf: buffer
 * @i: size
 *
 * Return: r
 */
ssize_t rbuffer(info_t *info, char *buf, size_t *i)
{
	ssize_t r = 0;

	if (*i)
		return (0);
	r = read(info->readfd, buf, rbuffer_SIZE);
	if (r >= 0)
		*i = r;
	return (r);
}
