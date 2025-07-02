#include "minishell.h"

void	allocat_arr_of_structs_list(t_expand **expand_list, int how_much_to_expand)
{
	*expand_list = ft_malloc(how_much_to_expand * sizeof(t_expand), 1);
}
