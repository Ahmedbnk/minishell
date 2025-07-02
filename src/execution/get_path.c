#include "minishell.h"

char	**get_path(void)
{
	char	*path;
	char	**splited;

	path = ft_getenv();
	splited = ft_split(path, ':');
	return (splited);
}
