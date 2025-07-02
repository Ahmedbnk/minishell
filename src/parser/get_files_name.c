#include "minishell.h"

void	get_files_name(t_shell_control_block *sh)
{
	if (!sh)
		return ;
	sh->file_name_lst = NULL;
	parse_tokens(sh);
	prepare_lst(sh);
	// debug_print_list(sh);
}
