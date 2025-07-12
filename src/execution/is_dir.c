
#include "minishell.h"

int	is_dir(char *cmd)
{
	DIR *ptr;

	if (!cmd)
		return (0);
	if ((ptr = opendir(cmd)) != NULL)
	{
		closedir(ptr);
		exe_flag(IS_DIR);
		return 1;
	}
	return (0);
}