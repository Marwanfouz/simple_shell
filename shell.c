#include "shell.h"

/**
 * main - entry point
 * @argc: arg count
 * @argv: arg vector
 *
 * Return: 0 on success, 1 on error
 */
int main(int argc, char **argv)
{
	info_t info[] = {INFO_INIT};
	int fd;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
		{
			if (errno == EACCES)
				exit(126);
			if (errno == ENOENT)
			{
				_pais(argv[0]);
				_pais(": 0: Can't open ");
				_pais(argv[1]);
				_wctstderr('\n');
				_wctstderr(BUF_FLUSH);
				exit(127);
			}
			return (EXIT_FAILURE);
		}
	}
	env_lilis(info);
	msl(info, argv);
	return (EXIT_SUCCESS);
}
