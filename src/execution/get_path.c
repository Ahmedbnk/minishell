#include "minishell.h"

char	**get_path(void)
{
	char	*path;
	char	**splited;

	path = getenv("PATH");
	splited = ft_split(path, ':');
	return (splited);
}
