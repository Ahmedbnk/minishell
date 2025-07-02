#include "minishell.h"

int	does_it_has_qoutes(char *str)
{
	if (!str)
		return (0);
	while (*str)
	{
		if (is_quote(*str))
			return (1);
		str++;
	}
	return (0);
}
