#include "minishell.h"

int	does_string_has_operators(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (is_operator(str, i))
			return (1);
		i++;
	}
	return (0);
}
