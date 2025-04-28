#include "minishell.h"

void	allocat_expand_list(t_expand **expand_list, int how_much_to_expand)
{
	*expand_list = ft_malloc(how_much_to_expand * sizeof(t_expand));
}

void	init_expand_list(t_expand *expand_list, int how_much_to_expand)
{
	int	i;

	i = 0;
	while (i < how_much_to_expand)
	{
		expand_list[i].befor_dollar = NULL;
		expand_list[i].to_expand = NULL;
		expand_list[i].after_expand = NULL;
		expand_list[i].last_one = 0;
		i++;
	}
}

void	allocat_and_init(t_expand **expand_list, int how_much_to_expand)
{
	allocat_expand_list(expand_list, how_much_to_expand);
	init_expand_list(*expand_list, how_much_to_expand);
}
