#include "minishell.h"

void	init_arr_of_structs_list(t_expand *expand_list, int how_much_to_expand, int heredoc_flag)
{
	int	i;

	i = 0;
	while (i < how_much_to_expand)
	{
		expand_list[i].befor_dollar = NULL;
		expand_list[i].to_expand = NULL;
		expand_list[i].after_dollar = NULL;
		expand_list[i].last_one = 0;
		expand_list[i].heredoc_flag = heredoc_flag;

		i++;
	}
}
