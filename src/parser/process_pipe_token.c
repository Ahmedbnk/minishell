#include "minishell.h"

void	process_pipe_token(t_shell_control_block *sh)
{
	t_name_lst	*new_node;

	new_node = new_file_name("|", NEW_START);
	if (new_node)
		add_back_file_name(&(sh->file_name_lst), new_node);
}
