#include "minishell.h"

void	setup_input_redirection(t_shell_control_block *shell)
{
	int	fd;

	if (shell->in_file_name)
	{
		shell->original_stdin = ft_dup(0);
		fd = ft_open(shell->in_file_name, O_RDONLY, 0);
		ft_dup2(fd, 0);
	}
}
