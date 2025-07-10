
#include "minishell.h"

int	is_dir(char *cmd)
{
	DIR *ptr;

	if (!cmd)
		return (0);
	if ((ptr = opendir(cmd)) != NULL)
	{
		closedir(ptr);
		exit((p_err(buf(cmd, ": ", "Is a directory\n")), free_all(), 126));
	}
	return (0);
}