#include "shell.h"

/**
 * freesl - frees a string of strings
 * @pp: string of strings
 */
void freesl(char **pp)
{
	char **a = pp;

	if (!pp)
		return;
	while (*pp)
		free(*pp++);
	free(a);
}
