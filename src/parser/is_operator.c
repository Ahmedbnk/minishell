#include "minishell.h"

int	is_operator(char *str, int i)
{
	if (is_between_quotes(str, i))
		return (0);
	if ((str[i] == '>' && str[i + 1] == '>') || (str[i] == '<' && str[i
			+ 1] == '<'))
		return (2);
	if (str[i] == '>' || str[i] == '<' || str[i] == '|')
		return (1);
	return (0);
}
