#include "minishell.h"

void	setup_output_redirection(t_shell_control_block *shell)
{
	if (shell->file_name)
	{
		shell->original_stdout = dup(1);
		if (shell->tokenze->type == REDIR_OUT)
			ft_close(open(shell->file_name, O_TRUNC | O_CREAT | O_WRONLY,
					0644));
		else if (shell->tokenze->type == REDIR_APPEND)
			ft_close(open(shell->file_name, O_APPEND | O_CREAT | O_WRONLY,
					0644));
		dup2(open(shell->file_name, O_WRONLY), 1);
	}
}
