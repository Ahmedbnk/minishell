#include "minishell.h"

int	is_there_a_char(char *str)
{
	while (*str)
	{
		if (is_space(*str))
			str++;
		else
			return (1);
	}
	return (0);
}
