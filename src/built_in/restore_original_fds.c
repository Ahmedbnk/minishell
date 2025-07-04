#include "minishell.h"

void	restore_original_fds(t_shell_control_block *shell)
{
	ft_dup2(shell->original_stdin, 0);
	ft_dup2(shell->original_stdout, 1);
	ft_close(shell->original_stdin);
	ft_close(shell->original_stdout);
}
