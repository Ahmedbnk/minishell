#include "minishell.h"

void	allocat_and_init(t_expand **expand_list, int how_much_to_expand, int heredoc_flag)
{
	allocat_arr_of_structs_list(expand_list, how_much_to_expand);
	init_arr_of_structs_list(*expand_list, how_much_to_expand, heredoc_flag);
}
