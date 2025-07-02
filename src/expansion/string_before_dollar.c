#include "minishell.h"

void	string_before_dollar(t_expand *data, char *str, int *offset)
{
	int	flag;

	if (!str)
		return ;
	flag = *offset;
	while (str[*offset])
	{
		if (str[*offset] == '$' && (data->heredoc_flag || should_i_expand(str, *offset))
			&& ft_isalnum(str[(*offset) + 1]))
			break ;
		(*offset)++;
	}
	if (*offset > flag)
		data->befor_dollar = ft_substr(str, flag, *offset - flag);
}
