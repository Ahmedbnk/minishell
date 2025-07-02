#include "minishell.h"

void	process_redirection_token(t_shell_control_block *sh, char **ptr)
{
	t_name_lst	*new_node;

	if (!*(ptr + 1))
		return ;
	new_node = new_file_name(*(ptr + 1), VALID);
	if (new_node)
		add_back_file_name(&(sh->file_name_lst), new_node);
}
