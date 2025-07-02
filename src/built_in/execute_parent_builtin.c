#include "minishell.h"

void	execute_parent_builtin(t_shell_control_block *shell)
{
	save_original_fds(shell);
	init_redirection_vars(shell);
	if (parse_redirections(shell))
		shell->exit_status = 1;
	setup_output_redirection(shell);
	setup_input_redirection(shell);
	execute_builtin(shell);
	restore_original_fds(shell);
}
