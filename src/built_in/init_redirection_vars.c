#include "minishell.h"

void	init_redirection_vars(t_shell_control_block *shell)
{
	shell->in_file_name = NULL;
	shell->file_name = NULL;
}
