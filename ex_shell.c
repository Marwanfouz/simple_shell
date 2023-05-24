#include "shell.h"

/**
 * ex_shell - exits the shell
 * @info: Structure containing potential arguments. Used to maintain
 *		  constant function prototype.
 *  Return: exits with a given exit status
 *		 (0) if info.argv[0] != "exit"
 */
int ex_shell(info_t *info)
{
	int exitcheck;

	if (info->argv[1]) /* If there is an exit arguement */
	{
		exitcheck = _casti(info->argv[1]);
		if (exitcheck == -1)
		{
			info->status = 2;
			err(info, "Illegal number: ");
			_pais(info->argv[1]);
			_wctstderr('\n');
			return (1);
		}
		info->err_num = _casti(info->argv[1]);
		return (-2);
	}
	info->err_num = -1;
	return (-2);
}
