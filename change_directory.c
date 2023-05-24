#include "shell.h"

/**
 * _chdir - changes the current directory of the process
 * @info: Structure containing potential arguments. Used to maintain
 *		  constant function prototype.
 *  Return: Always 0
 */
int _chdir(info_t *info)
{
	char *s, *dir, buffer[1024];
	int chdir_ret;

	s = getcwd(buffer, 1024);
	if (!s)
		_pis("TODO: >>getcwd failure emsg here<<\n");
	if (!info->argv[1])
	{
		dir = _get_voev(info, "HOME=");
		if (!dir)
			chdir_ret =
				chdir((dir = _get_voev(info, "PWD=")) ? dir : "/");
		else
			chdir_ret = chdir(dir);
	}
	else if (_plcots(info->argv[1], "-") == 0)
	{
		if (!_get_voev(info, "OLDPWD="))
		{
			_pis(s);
			_wct_stdout('\n');
			return (1);
		}
		_pis(_get_voev(info, "OLDPWD=")), _wct_stdout('\n');
		chdir_ret =
			chdir((dir = _get_voev(info, "OLDPWD=")) ? dir : "/");
	}
	else
		chdir_ret = chdir(info->argv[1]);
	if (chdir_ret == -1)
	{
		err(info, "can't cd to ");
		_pais(info->argv[1]), _wctstderr('\n');
	}
	else
	{
		_ianevo(info, "OLDPWD", _get_voev(info, "PWD="));
		_ianevo(info, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}
