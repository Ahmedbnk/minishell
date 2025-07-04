#include "minishell.h"

void	save_original_fds(t_shell_control_block *shell)
{
	shell->original_stdin = ft_dup(0);
	shell->original_stdout = ft_dup(1);
}
