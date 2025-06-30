#include "minishell.h"

int	is_valid_flag(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	if (str[i] != '-' || str[i + 1] != 'n')
		return (0);
	i++;
	while (str[i])
	{
		if (str[i] != 'n')
			return (0);
		i++;
	}
	return (1);
}
