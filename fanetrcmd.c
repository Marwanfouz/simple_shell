#include "shell.h"

/**
 * fanetrcmd - forks a an exec thread to run cmd
 * @info: the parameter & return info struct
 *
 * Return: void
 */
void fanetrcmd(info_t *info)
{
	pid_t child_pid;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error:");
		return;
	}
	if (child_pid == 0)
	{
		if (execve(info->path, info->argv, get_sace(info)) == -1)
		{
			freein(info, 1);
			if (errno == EACCES)
				exit(126);
			exit(1);
		}
	}
	else
	{
		wait(&(info->status));
		if (WIFEXITED(info->status))
		{
			info->status = WEXITSTATUS(info->status);
			if (info->status == 126)
				err(info, "Permission denied\n");
		}
	}
}
