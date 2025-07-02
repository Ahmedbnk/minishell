#include "minishell.h"

void	setup_input_redirection(t_shell_control_block *shell)
{
	if (shell->in_file_name)
	{
		shell->original_stdin = dup(0);
		dup2(open(shell->in_file_name, O_RDONLY), 0);
	}
}
