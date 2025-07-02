#include "minishell.h"

void	create_all_heredocs(t_shell_control_block *shell)
{
	t_token	*ptr;

	shell->exit_status = 0;
	shell->exit_status_flag = 0;
	ptr = shell->tokenze;
	while (ptr)
	{
		if (shell->exit_status_flag == 1)
			break ;
		if (ptr->type == HEREDOC)
			create_heredoc(shell, ptr);
		ptr = ptr->next;
	}
}
