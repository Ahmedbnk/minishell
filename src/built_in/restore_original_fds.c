#include "minishell.h"

void	restore_original_fds(t_shell_control_block *shell)
{
	dup2(shell->original_stdin, 0);
	dup2(shell->original_stdout, 1);
	close(shell->original_stdin);
	close(shell->original_stdout);
}
